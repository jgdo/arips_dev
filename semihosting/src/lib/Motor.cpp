/*
 * Motor.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: jgdo
 */

#include "Motor.h"

Motor::Motor(const std::string& name): _name(name) {
	
}

void Motor::set(float percent) {
	_set(percent);
}
