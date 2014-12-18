//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <iostream>
#include <functional>
#include <stdio.h>
#include "diag/Trace.h"

#include "stm32f4_discovery.h"

#include "stm32f4xx.h"

#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

#include <ros.h>
#include <arips_msgs/MotorPWMRawArray.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>

#include "arm_controller/ArmHandler.h"
#include "arm_controller/L298d.h"
#include "arm_controller/InverseDynamicsController.h"
#include "arm_controller/PDController.h"

#include <lidar/XV11Lidar.h>

#include <MD25/MD25.h>

#include <lib/Timer.h>

#include <arips/AripsPositionPublisher.h>
#include <arips/ParameterStore.h>

#include <math.h>

#include <m/Matrix.h>

#include <sstream>
#include <string>

#include "lib/tm_stm32f4_servo.h"

using namespace std;
using namespace std::placeholders;
// for _1, _2, .. in std::bind

__ALIGN_BEGIN USB_OTG_CORE_HANDLE USB_OTG_dev __ALIGN_END;

ros::NodeHandle nodeHandle;

void motorCB(const arips_msgs::MotorPWMRawArray& msg, L298& l298) {
	for (unsigned i = 0; i < msg.motor_pwm.size(); i++) {
		l298.setMotorPWM(msg.motor_pwm[i].motor_index, msg.motor_pwm[i].pwm_value);
	}
}

void cmd_vel_CB(const geometry_msgs::Twist& msg, MD25& md25) {
	float x = msg.linear.x;
	float z = msg.angular.z * ARIPS_WHEEL_DIST / 2.0f;
	
	float left = (x - z);
	float right = (x + z);
	
	md25.setSpeedLeftRight(left, right);
}

int main() {
	SysTick_Config(SystemCoreClock / 1000);
	
	// ------------- USB -------------- //
	USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_CDC_cb, &USR_cb);
	
	nodeHandle.initNode();
	
	std::list<std::function<void(void)>> task_list;
	
	task_list.push_back([&] () {
		SysTickTimer::handleTimers();
	});
	
	task_list.push_back([&] () {
		nodeHandle.spinOnce();
	});
	
	tf::TransformBroadcaster tf_broadcaster;
	tf_broadcaster.init(nodeHandle);
	
	static geometry_msgs::TransformStamped servo_transform;
	
	MD25 md25;
	// ArmPositionReader arm_reader;
	// L298 l298;
	// InverseDynamicsController controller;
	// PDController controller;
	//TrajectoryHandler traj_handler;
	//ArmHandler arm_handler(arm_reader, l298.getMotor(MOTOR_SHOULDER), l298.getMotor(MOTOR_HAND), controller,
	//       traj_handler);
	
	// XV11Lidar lidar(l298.getMotor(MOTOR_LIDAR));
	// lidar.turnOn();
//	task_list.push_back([&] () {
//		lidar.checkData();
//	});
	
	// ros::Subscriber<arips_msgs::MotorPWMRawArray> motor_sub("motor_pwm_set", std::bind(motorCB, _1, (L298&) l298));
	// nodeHandle.subscribe(motor_sub);
	
	ros::Subscriber<geometry_msgs::Twist> cmd_vel_sub("/cmd_vel", std::bind(cmd_vel_CB, _1, (MD25&) md25));
	nodeHandle.subscribe(cmd_vel_sub);
	
	ParameterStore::readFromFlash(true);
		ParameterStore::registerPubSub();
		
		SysTickTimer paramPubTimer(500, &ParameterStore::publishOutParameters);
	
	float kinectServoPos = 0;
	
	TM_SERVO_t kinectServo; //							= PE5
	TM_SERVO_Init(&kinectServo, TIM9, TM_PWM_Channel_1, TM_PWM_PinsPack_2);
	TM_SERVO_SetDegrees(&kinectServo, ParameterStore::get("kinect_servo_offset", 0));
	
	ros::Subscriber<std_msgs::Float32> servoSub("kinect_tilt",
	        [&kinectServo, &kinectServoPos](const std_msgs::Float32& position) {
		        kinectServoPos = position.data;
		        float raw = kinectServoPos * ParameterStore::get("kinect_servo_fact", 1) + ParameterStore::get("kinect_servo_offset", 0);
		        TM_SERVO_SetDegrees(&kinectServo, raw);
	        });
	
	SysTickTimer servoPubTimer(100, [&]() {
		// publish TF
		    servo_transform.header.frame_id = "/base_link";
		    servo_transform.header.stamp = ros::Time::now();
		    servo_transform.child_frame_id = "/camera_link";

		    servo_transform.transform.translation.x = -0.14;
		    servo_transform.transform.translation.y = 0;
		    servo_transform.transform.translation.z = 0.74;

		    servo_transform.transform.rotation = tf::createQuaternionFromRPY(0, kinectServoPos/180.0f * M_PI, 0);
		    tf_broadcaster.sendTransform(servo_transform);

		    servo_transform.child_frame_id = "/laser_frame";

		    servo_transform.transform.rotation = tf::createQuaternionFromYaw(0);// faster than from RPY
		    tf_broadcaster.sendTransform(servo_transform);
	    });
	
	nodeHandle.subscribe(servoSub);
	
	AripsPositionPublisher pos_pub(md25);
	
	cout << "Entering loop" << endl;
	
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_LEDOn(LED4);
	
	while (1) {
		for (auto& func : task_list) {
			func();
		}
	}
}
