/*
 * AripsPositionPublisher.cpp
 *
 *  Created on: Aug 17, 2014
 *      Author: jgdo
 */

#include <arips/AripsPositionPublisher.h>
#include <tf/tf.h>
#include <iostream>

#define ENCODER_FACTOR 0.000863937

AripsPositionPublisher::AripsPositionPublisher(MD25& md25) :
		md25(md25), timer(50, std::bind(&AripsPositionPublisher::sendOdometryTF, this)), lastTime(ros::Time::now()), odom_pub(
		        "/odom", &odom_msg) {
	broadcaster.init(nodeHandle);
	
	nodeHandle.advertise(odom_pub);
}

#if 0
inline static void rpyToQuaternion(double r, double p, double y, geometry_msgs::Quaternion& quat) {
	r /= 2.0;
	p /= 2.0;
	y /= 2.0;
	double ci = cos(r);
	double si = sin(r);
	double cj = cos(p);
	double sj = sin(p);
	double ck = cos(y);
	double sk = sin(y);
	double cc = ci * ck;
	double cs = ci * sk;
	double sc = si * ck;
	double ss = si * sk;
	
	//   if repetition:
//	quat.x = cj * (cs + sc);
//	quat.y = sj * (cc + ss);
//	quat.z = sj * (cs - sc);
//	quat.w = cj * (cc - ss);
	/// else:
	quat.x = cj * sc - sj * cs;
	quat.y = cj * ss + sj * cc;
	quat.z = cj * cs - sj * sc;
	quat.w = cj * cc + sj * ss;
//	    if parity:
//	        quaternion[j] *= -1
}

#endif

void AripsPositionPublisher::sendOdometryTF() {
	static bool first_time = true;
	
	if (first_time) {
		int err = md25.resetEncoder();
		if (err) {
			std::cout << "Error resetting md25 distance: " << err << std::endl;
			return;
		}
		
		first_time = false;
	}
	
	auto nowTime = ros::Time::now();
	
	// read encoder
	long dCountL, dCountR;
	int err = md25.readDistance(&dCountL, &dCountR);
	if (err) {
		std::cout << "Error reading md25 distance: " << err << std::endl;
		return;
	}
	
	long diffL = (dCountL - currentDrivenDistLeft);
	long diffR = (dCountR - currentDrivenDistRight);
	
	// update position
	double currentSpeed = 0, currentAngleSpeed = 0;
	if (diffL || diffR) {
		// http://www-home.fh-konstanz.de/~bittel/roboMSI/Vorlesung/04_Lokalisierung.pdf
		double theta = currentAngle;
		
		// delta in meter
		double fl = diffL * ENCODER_FACTOR, fr = diffR * ENCODER_FACTOR;
		
		double d = (fl + fr) / 2;
		double alpha = (fr - fl) / ARIPS_WHEEL_DIST;
		
		ros::Duration dt = nowTime - lastTime;
		currentSpeed = d / dt.toSec();
		currentAngleSpeed = alpha / dt.toSec();
		
		double x = currentPosX + d * cos(theta + alpha / 2); // neue posX	
		double y = currentPosY + d * sin(theta + alpha / 2); // neue posY	
		        
		currentDrivenDistLeft += diffL;
		currentDrivenDistRight += diffR;
		// currentDriveDist += (diffL + diffR) / 2;
		
		currentPosX = x;
		currentPosY = y;
		currentAngle += alpha;
		if (currentAngle >= M_TWOPI)
			currentAngle -= M_TWOPI;
		if (currentAngle < 0)
			currentAngle += M_TWOPI;
	}
	
	lastTime = nowTime;
	
	// publish TF
	static geometry_msgs::TransformStamped t;
	
	t.header.frame_id = "/odom";
	t.header.stamp = nowTime;
	t.child_frame_id = "/base_link";
	
	t.transform.translation.x = currentPosX;
	t.transform.translation.y = currentPosY;
	
	t.transform.rotation = tf::createQuaternionFromRPY(0, 0, currentAngle);
	broadcaster.sendTransform(t);
	
	// Publish Odometry
	odom_msg.header.stamp = nowTime;
	odom_msg.header.frame_id = "/odom";
	odom_msg.child_frame_id = "/base_link";
	
	odom_msg.pose.pose.position.x = currentPosX;
	odom_msg.pose.pose.position.y = currentPosY;
	odom_msg.pose.pose.position.z = 0.0;
	odom_msg.pose.pose.orientation = tf::createQuaternionFromRPY(0, 0, currentAngle);
	
	odom_msg.twist.twist.linear.x = currentSpeed;
	odom_msg.twist.twist.angular.z = currentAngleSpeed;
	
	for (int i = 0; i < 36; i++)
		odom_msg.pose.covariance[i] = 0;
	
	odom_msg.pose.covariance[0] = 0.01;
	odom_msg.pose.covariance[7] = 0.01;
	odom_msg.pose.covariance[14] = 99999;
	odom_msg.pose.covariance[21] = 99999;
	odom_msg.pose.covariance[28] = 99999;
	odom_msg.pose.covariance[35] = 0.01;
	
	for (int i = 0; i < 36; i++)
		odom_msg.twist.covariance[i] = odom_msg.pose.covariance[i];
	
	odom_pub.publish(&odom_msg);
}
