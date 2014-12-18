/*
 * ArmController.h
 *
 *  Created on: Aug 9, 2014
 *      Author: jgdo
 */

#ifndef _ARM_POSITION_READER_H_
#define _ARM_POSITION_READER_H_

#include "stm32f4xx_conf.h"

#include <ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>
#include "lib/Timer.h"
#include <m/Matrix.h>

// #include <lib/MedianSet.h>

#define SERVO_SHOULDER 0
#define SERVO_HAND 2
#define SERVO_GRIPPER 3
#define MOTOR_LIDAR 1

#define NUM_ADC_CHANS	4
#define NUM_MOV_AVG		5

class ArmPositionReader {
public:
	ArmPositionReader();

	float getServoRawPosition(int num);

	void updateJointState();

	inline ml::Vec2f jointPosition() const {
		return joint_p;
	}
	
	inline ml::Vec2f jointVelocity() const {
		return joint_v;
	}
	
private:
	struct ADC_ConfigS {
		GPIO_TypeDef* ADC_PORT; // Port
		const uint16_t ADC_PIN; // Pin
		const uint32_t ADC_CLK; // Clock
		const uint8_t ADC_CH;   // ADC-Channel
	};

	static const ADC_ConfigS adcConfig[4];

	ml::Vec2f joint_p = ml::Vec2f::zeros(), joint_v = ml::Vec2f::zeros(), joint_a = ml::Vec2f::zeros();
	double lastSamplingTime;

	volatile uint32_t adc_dma_buf[NUM_ADC_CHANS] = { 0 };
//	int moving_average_values[NUM_ADC_CHANS][NUM_MOV_AVG] = { { 0 } };
//	int moving_average_idx[4] = { 0 };
	volatile int adc_sum_values[NUM_ADC_CHANS] = { 0 };
	
	InterruptQueue<uint64_t, 1000> adc_queue;
	
	std::array<float, NUM_MOV_AVG> adc_set[NUM_ADC_CHANS];
	int adc_counter = 0;
	
	std_msgs::Float32 raw_msg;
	ros::Publisher raw_pub;

	SysTickTimer raw_pub_timer;
	
	SysTickTimer adc_timer;

	void adcISR();
	
	void updateADC();
	
	void publishRaw();
};

#endif /* _ARM_POSITION_READER_H_ */
