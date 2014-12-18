/*
 * ArmHandler.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: jgdo
 */

#include <arm_controller/ArmHandler.h>

#include <arips/ParameterStore.h>

const char* ArmHandler::jointNames[2] = { "shoulder_joint", "hand_joint" };

using namespace ml;
using namespace std::placeholders;

ArmHandler::ArmHandler(ArmPositionReader& reader, Motor& motor0, Motor& motor1, Controller& controller,
        TrajectoryHandler& traj_handler) :
		position_reader(reader), arm_motor0(motor0), arm_motor1(motor1), controller(controller), traj_handler(
		        traj_handler), jointStatePublisher("joint_states", &jointStateMsg), joint_pub_timer(10,
		        std::bind(&ArmHandler::publishJointStates, this)), control_timer(
		        1000 / controller.defaultControllerFrequency(), std::bind(&ArmHandler::doControlLoop, this)), traj_point_sub(
		        "/trajectory_point", std::bind(&ArmHandler::onPointReceived, this, _1)) {
	nodeHandle.advertise(jointStatePublisher);
	nodeHandle.subscribe(traj_point_sub);
}

void ArmHandler::publishJointStates() {
//	position_reader.updateJointState();
//	joint_p = position_reader.jointPosition();
//	joint_v = position_reader.jointVelocity();
//	jointStateMsg.name.assign((char**) jointNames, (char**) jointNames + 2);
//	
//	jointStateMsg.position.assign(joint_p.data, joint_p.data + 2);
//	
//	jointStateMsg.velocity.assign(joint_v.data, joint_v.data + 2);
//	
//	jointStateMsg.effort.assign(joint_torque.data, joint_torque.data + 2);
//	
//	jointStateMsg.header.stamp = ros::Time::now();
//	jointStateMsg.header.frame_id = "base_link";
//	
//	jointStatePublisher.publish(&jointStateMsg);
}

void ArmHandler::doControlLoop() {
	position_reader.updateJointState();
	joint_p = position_reader.jointPosition();
	joint_v = position_reader.jointVelocity();
	
	if (state == IDLE) {
		if (traj_handler.hasTrajectory()) {
			state = TRAJECTORY;
			have_set_traj_point = false;
		} else if (have_set_traj_point)
			state = POINT;
	} else if (state == TRAJECTORY) {
		if (have_set_traj_point) {
			traj_handler.clearTrajectory();
			state = POINT;
		}
	} else if (state == POINT) {
		if (traj_handler.hasTrajectory()) {
			state = TRAJECTORY;
			have_set_traj_point = false;
		}
	}
	
	Vec2f t = Vec2f::zeros(); // torque
	        
	Vec2f q_des = Vec2f::zeros(), qd_des = Vec2f::zeros(), qdd_des = Vec2f::zeros();
	bool des_valid = false;
	
	if (state == TRAJECTORY) {
		if (traj_handler.getCurrentPoint(q_des, qd_des, qdd_des)) { // have point
			des_valid = true;
			
			//joint_torque(0) = t_q_des(0, 1);
			//joint_torque(1) = t_q_des(1, 1);
			
//		t(0) *= 0.8f;
//		t(1) *= 10.0f;
//		
//			if (fabs(t_q_des(0, 1)) > 0.1) {
//				if (t_q_des(0, 1) > 0)
//					t_q_des(0, 0) += 0.10;
//				else
//					t_q_des(0, 0) -= 0.10;
//				
//			}
//			
//			if (fabs(t_q_des(1, 1)) > 0.1) {
//				if (t_q_des(1, 1) < 0)
//					t_q_des(1, 0) -= 0.10;
//				else
//					t_q_des(1, 0) += 0.10;
//			}
			
			// joint_torque = t;
			
		} else
			state = IDLE;
	} else if (state == POINT) {
		q_des = set_traj_point;
		des_valid = true;
	}
	
	if (des_valid) {
		Mat22f t_q_des = controller.computeVoltage(joint_p, joint_v, q_des, qd_des, qdd_des);
		
		t(0) = t_q_des(0, 0);
		t(1) = t_q_des(1, 0);
		
		Vec2f frictionComp = Vec2d::zeros();
		
		if (fabs(joint_v(0)) > 0.1) {
			if (joint_v(0) > 0) {
				frictionComp(0) = 0.03;
			} else
				frictionComp(0) = -0.03;
		} else if (fabs(t_q_des(0, 1)) > 0.005) {
			if (t_q_des(0, 1) > 0)
				frictionComp(0) = 0.1;
			else
				frictionComp(0) = -0.1;
		}
		
		if (fabs(joint_v(1)) > 0.1) {
			if (joint_v(1) > 0) {
				frictionComp(1) = 0.03;
			} else
				frictionComp(1) = -0.03;
		} else if (fabs(t_q_des(1, 1)) > 0.005) {
			if (t_q_des(1, 1) > 0)
				frictionComp(1) = 0.1;
			else
				frictionComp(1) = -0.1;
		}
//		
//		if (fabs(t_q_des(0, 1)) > 0.1) {
//			if (t_q_des(0, 1) > 0)
//				t_q_des(0, 0) += 0.15;
//			else
//				t_q_des(0, 0) -= 0.15;
//			
//		}
//		
//		if (fabs(t_q_des(1, 1)) > 0.1) {
//			if (t_q_des(1, 1) < 0)
//				t_q_des(1, 0) -= 0.10;
//			else
//				t_q_des(1, 0) += 0.10;
//		}
		
		ParameterStore::say("frictionComp", frictionComp);
		
		t += frictionComp;
		
		float limit = 0.5f;
		
		if (t(0) < -limit)
			t(0) = -limit;
		else if (t(0) > limit)
			t(0) = limit;
		
		if (t(1) < -limit)
			t(1) = -limit;
		else if (t(1) > limit)
			t(1) = limit;
	}
	
	joint_torque = t;
	arm_motor0.set(t(0));
	arm_motor1.set(t(1));
	
	jointStateMsg.name.assign((char**) jointNames, (char**) jointNames + 2);
	
	jointStateMsg.position.assign(joint_p.data, joint_p.data + 2);
	
	jointStateMsg.velocity.assign(joint_v.data, joint_v.data + 2);
	
	jointStateMsg.effort.assign(joint_torque.data, joint_torque.data + 2);
	
	jointStateMsg.header.stamp = ros::Time::now();
	jointStateMsg.header.frame_id = "base_link";
	
	jointStatePublisher.publish(&jointStateMsg);
}

void ArmHandler::onPointReceived(const trajectory_msgs::JointTrajectoryPoint& point) {
	if (point.positions.size() == 2) {
		set_traj_point(0) = point.positions[0];
		set_traj_point(1) = point.positions[1];
		have_set_traj_point = true;
	}
}
