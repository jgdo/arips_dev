/*
 * PDController.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: jgdo
 */

#include <arm_controller/PDController.h>

using namespace ml;

PDController::PDController() {
}

PDController::~PDController() {
}

ml::Mat22f PDController::computeVoltage(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& q_des,
        const ml::Vec2f& qd_des, const ml::Vec2f& qdd_des) {
	
	float tolerance = 1.0f / 200.0f;
	Vec2f pos_diff = q_des - q;
	
	Vec2f voltage = Vec2f::zeros();
	
	
//	if (fabs(pos_diff(0)) > tolerance) {
//		if (pos_diff(0) > 0)
//			voltage(0) = 0.4;
//		else
//			voltage(0) = -0.4;
//	}
//	
//	if (fabs(pos_diff(1)) > tolerance) {
//		if (pos_diff(1) > 0)
//			voltage(1) = 0.4;
//		else
//			voltage(1) = -0.4;
//	}
	
	Mat22f mat;
	mat(0, 0) = voltage(0);
	mat(1, 0) = voltage(1);
	mat(0, 1) = voltage(0);
	mat(1, 1) = voltage(1);
	
	return mat;
}
