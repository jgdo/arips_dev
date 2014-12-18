#ifndef _L298D_H_
#define _L298D_H_

#define MOTOR_GRIPPER 0
#define MOTOR_SHOULDER 2
#define MOTOR_HAND 3

#include "lib/SimpleMotorController.h"

class L298: public SimpleMotorController<L298, 4> {
public:
	L298();

protected:
	virtual void _setMotorPWM(int motor, float percent);
};

#endif // _L298D_H_
