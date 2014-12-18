/*
 * ArmHandler.h
 *
 *  Created on: Aug 24, 2014
 *      Author: jgdo
 */

#ifndef ARMHANDLER_H_
#define ARMHANDLER_H_

#include <ros.h>
#include <lib/Timer.h>
#include <lib/Motor.h>
#include <m/Matrix.h>
#include <arm_controller/ArmPositionReader.h>
#include <arm_controller/Controller.h>
#include <arm_controller/TrajectoryHandler.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

class ArmHandler {
public:
	ArmHandler(ArmPositionReader& reader, Motor& motor0, Motor& motor1, Controller& controller,
	        TrajectoryHandler& traj_handler);

private:
	static const char* jointNames[2];
	
	enum State {
		IDLE, TRAJECTORY, POINT
	} state = IDLE;

	ArmPositionReader& position_reader;
	Motor& arm_motor0, &arm_motor1;
	Controller& controller;
	TrajectoryHandler& traj_handler;

	sensor_msgs::JointState jointStateMsg;
	ros::Publisher jointStatePublisher;

	SysTickTimer joint_pub_timer, control_timer;

	ml::Vec2f joint_p = ml::Vec2f::zeros(), joint_v = ml::Vec2f::zeros(), joint_torque = ml::Vec2f::zeros();
	
	ros::Subscriber<trajectory_msgs::JointTrajectoryPoint> traj_point_sub;
	
	ml::Vec2f set_traj_point;
	bool have_set_traj_point = false;

	void publishJointStates();

	void doControlLoop();
	
	void onPointReceived(const trajectory_msgs::JointTrajectoryPoint& point);
};

#endif /* ARMHANDLER_H_ */
