/*
 * PDController.h
 *
 *  Created on: Aug 25, 2014
 *      Author: jgdo
 */

#ifndef PDCONTROLLER_H_
#define PDCONTROLLER_H_

#include <arm_controller/Controller.h>

class PDController: public Controller {
public:
	PDController();
	virtual ~PDController();

	virtual inline int defaultControllerFrequency() const {
		return 100;
	}
	
	virtual ml::Mat22f computeVoltage(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& q_des,
	        const ml::Vec2f& qd_des, const ml::Vec2f& qdd_des);
};

#endif /* PDCONTROLLER_H_ */
