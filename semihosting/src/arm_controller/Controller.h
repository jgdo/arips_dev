/*
 * Controller.h
 *
 *  Created on: Aug 25, 2014
 *      Author: jgdo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <m/Matrix.h>

class Controller {
public:
	Controller();
	virtual ~Controller();

	virtual int defaultControllerFrequency() const = 0;

	virtual ml::Mat22f computeVoltage(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& q_des,
	        const ml::Vec2f& qd_des, const ml::Vec2f& qdd_des) = 0;
private:
};

#endif /* CONTROLLER_H_ */
