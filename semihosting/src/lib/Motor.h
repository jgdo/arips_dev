/*
 * Motor.h
 *
 *  Created on: Aug 13, 2014
 *      Author: jgdo
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <string>

class Motor {
public:
	Motor(const std::string& name); 
	virtual inline ~Motor() {};
	void set(float percent);
	
	inline const std::string& name() {
		return _name;
	}
	
protected:
	const std::string _name;
	virtual void _set(float percent) = 0;
};

#endif /* MOTOR_H_ */
