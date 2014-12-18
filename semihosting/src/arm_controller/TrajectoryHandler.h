/*
 * TrajectoryHandler.h
 *
 *  Created on: Aug 24, 2014
 *      Author: jgdo
 */

#ifndef TRAJECTORYHANDLER_H_
#define TRAJECTORYHANDLER_H_

#include <m/Matrix.h>
#include <vector>
#include <trajectory_msgs/JointTrajectory.h>
#include <ros.h>

class TrajectoryHandler {
public:
	TrajectoryHandler();
	
	bool getCurrentPoint(ml::Vec2f& q_des, ml::Vec2f& qd_des, ml::Vec2f& qdd_des);
	
	inline bool hasTrajectory() const {
		return !traj_q.empty();
	}
	
	void clearTrajectory();
	
private:
	ros::Subscriber<trajectory_msgs::JointTrajectory> traj_sub;
	
	std::vector<ml::Vec2f> traj_q, traj_qd, traj_qdd;
	std::vector<unsigned long> traj_time_millis;
	
	long traj_start_time_millis;
	long traj_index;
	
	void handleTrajectoryMsg(const trajectory_msgs::JointTrajectory& msg);
	
	ml::Vec2f interp(const ml::Vec2f& p1, const ml::Vec2f& p2, int t1, int t2, int t);
};

#endif /* TRAJECTORYHANDLER_H_ */
