/*
 * MD25.cpp
 *
 *  Created on: Aug 15, 2014
 *      Author: jgdo
 */

#include <MD25/MD25.h>
#include "stm32f4xx.h"

#include <lib/stm32_ub_i2c1.h>

#define MD25_I2C_ADDR	0xB0

#define MD25_REG_SPEED1				0
#define MD25_REG_SPEED2				1
#define MD25_REG_ENC1				2			
#define MD25_REG_ENC2				6
#define MD25_REG_FIRMWARE_VERSION	13
#define MD25_REG_COMMAND			16

#define MD25_CMD_RESET_ENCODERS		0x20

MD25::MD25() :
		SimpleMotorController( { "md25_motor_1", "md25_motor_2" }) {
	UB_I2C1_Init();
}

void MD25::_setMotorPWM(int motor, float percent) {
	assignMotorSpeed(motor, percent);
	sendI2CSpeedCommand();
}

void MD25::assignMotorSpeed(int motor, float percent) {
	speed[motor] = 128 + percent * 127;
	if (speed[motor] < 0)
		speed[motor] = 0;
	else if (speed[motor] > 255)
		speed[motor] = 255;
}

void MD25::setSpeedLeftRight(float left, float right) {
	assignMotorSpeed(MOTOR_LEFT, left);
	assignMotorSpeed(MOTOR_RIGHT, right);
	sendI2CSpeedCommand();
}

int MD25::readDistance(long * left, long * right) {
	unsigned char buf[8];
	int ret = UB_I2C1_ReadMultiByte(MD25_I2C_ADDR, MD25_REG_ENC1, buf, sizeof(buf));
	// data is big endian
	*left = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | (buf[3] << 0);
	*right = (buf[4] << 24) | (buf[5] << 16) | (buf[6] << 8) | (buf[7] << 0);
	return ret;
}

int MD25::resetEncoder() {
	unsigned char buf[1] = { MD25_CMD_RESET_ENCODERS };
	return UB_I2C1_WriteMultiByte(MD25_I2C_ADDR, MD25_REG_COMMAND, buf, sizeof(buf));
}

void MD25::sendI2CSpeedCommand() {
	unsigned char buf[2] = { speed[0], speed[1] };
	UB_I2C1_WriteMultiByte(MD25_I2C_ADDR, MD25_REG_SPEED1, buf, sizeof(buf));
}
