/*
 * MD25.h
 *
 *  Created on: Aug 15, 2014
 *      Author: jgdo
 */

#ifndef MD25_H_
#define MD25_H_

#include <lib/SimpleMotorController.h>

class MD25: public SimpleMotorController<MD25, 2> {
public:
	static const int MOTOR_LEFT = 0, MOTOR_RIGHT = 1;

	MD25();

	void setSpeedLeftRight(float left, float right);

	int readDistance(long *left, long *right);

	int resetEncoder();

protected:
	virtual void _setMotorPWM(int motor, float percent);

	void assignMotorSpeed(int motor, float percent);

	void sendI2CSpeedCommand();

private:
	int speed[2] = { 128, 128 };
};

#endif /* MD25_H_ */
