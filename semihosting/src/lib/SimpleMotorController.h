/*
 * SimpleMotorController.h
 *
 *  Created on: Aug 15, 2014
 *      Author: jgdo
 */

#ifndef SIMPLEMOTORCONTROLLER_H_
#define SIMPLEMOTORCONTROLLER_H_

#include <lib/Motor.h>
#include "stm32f4xx.h"
#include <array>
#include <string>

template<class T, unsigned NumMotors>
class SimpleMotorController {
public:
	SimpleMotorController(const std::array<std::string, NumMotors>& motor_names) {
		for(unsigned i = 0; i < NumMotors; i++) {
			new (_p_motors()+i) _Motor(motor_names[i], i , this);
		}
	}
	
	virtual ~SimpleMotorController() {
		for(_Motor* motor = _p_motors(); motor < _p_motors() + NumMotors; motor++) {
			motor->~_Motor();
		}
	}
	
	inline void setMotorPWM(int motor_index, float percent) {
		assert_param(motor_index >= 0 && motor_index < NumMotors);
		_setMotorPWM(motor_index, percent);
	}

	inline Motor& getMotor(int motor_index) {
		assert_param(motor_index >= 0 && motor_index < NumMotors);
		return _p_motors()[motor_index];
	}
	
protected:	
	class _Motor: public Motor {
	public:
		_Motor(const std::string& name, int motor_index, SimpleMotorController* c) :
				Motor(name), motor_index(motor_index), controller(c) {
		}
		
	protected:
		virtual void _set(float percent) {
			controller->setMotorPWM(motor_index, percent);
		}
		
	private:
		int motor_index;
		SimpleMotorController* controller;
	};

	inline _Motor* _p_motors() {
		return ((_Motor*) _motors_container);
	}
	
	virtual void _setMotorPWM(int motor_index, float percent) = 0;
	
private:
	char _motors_container[sizeof(_Motor) * NumMotors];
};

#endif /* SIMPLEMOTORCONTROLLER_H_ */
