/*
 * TrajectoryHandler.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: jgdo
 */

#include <arm_controller/TrajectoryHandler.h>
#include <lib/Timer.h>

#include <iostream>

using namespace std::placeholders;
using namespace ml;
using namespace std;

TrajectoryHandler::TrajectoryHandler() :
		traj_sub("/trajectory", std::bind(&TrajectoryHandler::handleTrajectoryMsg, this, _1)) {
	nodeHandle.subscribe(traj_sub);
}

bool TrajectoryHandler::getCurrentPoint(ml::Vec2f& q_des, ml::Vec2f& qd_des, ml::Vec2f& qdd_des) {
	if (traj_q.empty()) {
		return false; // no active trajectory
	}
	
	// find next point
	long t = SystemMillisLong() - traj_start_time_millis;
	
	while ((traj_index < traj_q.size() - 1) && (traj_time_millis[traj_index + 1] <= t)) {
		traj_index++;
		//cout << "next point at " << traj_time_millis[traj_index] << " ms\n";
	}
	
	if (traj_index >= traj_q.size() - 1) {
		// we finished the trajectory
		clearTrajectory();
		
		// cout << "done after " << t << " ms\n";
		return false;
	}
	
	long t1 = traj_time_millis.at(traj_index);
	long t2 = traj_time_millis.at(traj_index + 1);
	
	q_des = interp(traj_q.at(traj_index), traj_q.at(traj_index + 1), t1, t2, t);
	
	if (!traj_qd.empty())
		qd_des = interp(traj_qd.at(traj_index), traj_qd.at(traj_index + 1), t1, t2, t);
	else
		qd_des = Vec2f::zeros();
	
	if (!traj_qdd.empty())
		qdd_des = interp(traj_qdd.at(traj_index), traj_qdd.at(traj_index + 1), t1, t2, t);
	else
		qdd_des = Vec2f::zeros();
	
	return true;
}

void TrajectoryHandler::clearTrajectory() {
	traj_q.clear();
	traj_qd.clear();
	traj_qdd.clear();
	traj_time_millis.clear();
}

void TrajectoryHandler::handleTrajectoryMsg(const trajectory_msgs::JointTrajectory& msg) {
	// cout << "handleTrajectoryMsg\n";
	
	clearTrajectory();
	
	if (msg.joint_names.size() != 2)
		return; // wrong number of joints
		
	if (strcmp("shoulder_joint", msg.joint_names[0]) || strcmp("hand_joint", msg.joint_names[1]))
		return; // wrong joints
		
	if (msg.points.size() < 2)
		return; // trajectory must have at least 2 points
		
	unsigned num_points = msg.points.size();
	traj_q.reserve(num_points);
	traj_qd.reserve(num_points);
	traj_qdd.reserve(num_points);
	traj_time_millis.reserve(num_points);
	
	bool got_vel = msg.points[0].velocities.size() > 0;
	bool got_acc = msg.points[0].accelerations.size() > 0;
	
	Vec2f q, qd, qdd;
	
	for (unsigned i = 0; i < num_points; i++) {
		const trajectory_msgs::JointTrajectoryPoint&p = msg.points[i];
		if (p.positions.size() != 2) {
			// no positions for one point
			clearTrajectory();
			return;
		}
		
		q(0) = p.positions[0];
		q(1) = p.positions[1];
		
		// cout << "q " << q << '\t';
		
		traj_q.push_back(q);
		
		if ((got_vel && (p.velocities.size() != 2)) || (!got_vel && (p.velocities.size() != 0))) {
			// inconsistent velocity specification
			clearTrajectory();
			return;
		}
		if (got_vel) {
			qd(0) = p.velocities[0];
			qd(1) = p.velocities[1];
			traj_qd.push_back(qd);
			// cout << "qd " << qd << '\t';
		}
		
		if ((got_acc && (p.accelerations.size() != 2)) || (!got_acc && (p.accelerations.size() != 0))) {
			// inconsistent acceleration specification
			clearTrajectory();
			return;
		}
		
		if (got_acc) {
			qdd(0) = p.accelerations[0];
			qdd(1) = p.accelerations[1];
			traj_qdd.push_back(qdd);
			// cout << "qdd " << qdd << '\t';
		}
		 
		traj_time_millis.push_back(p.time_from_start.nsec / 1000000 + p.time_from_start.sec * 1000);
		
		// cout << "t" << traj_time_millis.back() << endl;
	}
	
	// trajectory complete now
	traj_start_time_millis = SystemMillisLong();
	traj_index = 0;
	
	cout << "got trajectory with " << num_points << " points\n";
}

ml::Vec2f TrajectoryHandler::interp(const ml::Vec2f& p1, const ml::Vec2f& p2, int t1, int t2, int t) {
	float f = (float) (t - t1) / (float) (t2 - t1);
	return p1 * (1 - f) + p2 * f;
}
