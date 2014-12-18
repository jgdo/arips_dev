/*
 * AripsPositionPublisher.h
 *
 *  Created on: Aug 17, 2014
 *      Author: jgdo
 */

#ifndef ARIPSPOSITIONPUBLISHER_H_
#define ARIPSPOSITIONPUBLISHER_H_

#include <lib/Timer.h>

#include <ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

#include <MD25/MD25.h>

#define ARIPS_WHEEL_DIST 0.325 // TODO

class AripsPositionPublisher {
public:
	AripsPositionPublisher(MD25& md25);
	
	void sendOdometryTF();
	
private:
	MD25& md25;
	
	tf::TransformBroadcaster broadcaster;
	
	long long currentDrivenDistLeft = 0, currentDrivenDistRight = 0;
	double currentPosX = 0, currentPosY = 0, currentAngle = 0;
	
	SysTickTimer timer;
	
	ros::Time lastTime;
	
	nav_msgs::Odometry odom_msg;
	ros::Publisher odom_pub;
};

#endif /* ARIPSPOSITIONPUBLISHER_H_ */
