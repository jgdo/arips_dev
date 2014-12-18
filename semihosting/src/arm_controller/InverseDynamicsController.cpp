/*
 * InverseDynamicsController.cpp
 *
 *  Created on: Aug 23, 2014
 *      Author: jgdo
 */

#include <arm_controller/InverseDynamicsController.h>

#include <arips/ParameterStore.h>

#include <iostream>
#include <cmath>

using namespace ml;
using std::cos;
using std::sin;
using namespace std::placeholders;

InverseDynamicsController::InverseDynamicsController() :
		k_p(0.5), k_d(0.0), kp_sub("/set_kp", std::bind(&InverseDynamicsController::setKP, this, _1)), kd_sub("/set_kd",
		        std::bind(&InverseDynamicsController::setKD, this, _1)) { // TODO right parameters
	nodeHandle.subscribe(kp_sub);
	nodeHandle.subscribe(kd_sub);
}

ml::Mat22f InverseDynamicsController::computeVoltage(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& q_des,
        const ml::Vec2f& qd_des, const ml::Vec2f& qdd_des) {
	
	Vec2f qdd_ref = qdd_des + k_d * (qd_des - qd) + k_p * (q_des - q);
	Vec2f tau = tauFromConfig(q, qd, qdd_ref);
	
//	static float ki = 0.0;
//	static float i_limit = 2;
//	
//	float g_fact = 5;
//	
//	Vec2f err_p = (q_des - q);
//	i_part = i_part + err_p;
//	if (i_part(0) > i_limit)
//		i_part(0) = i_limit;
//	else if (i_part(0) < -i_limit)
//		i_part(0) = -i_limit;
//	
//	if (i_part(1) > i_limit)
//		i_part(1) = i_limit;
//	else if (i_part(1) < -i_limit)
//		i_part(1) = -i_limit;
//	
//	Vec2f qdd_ref = /*qdd_des + */k_d * (qd_des - qd) + k_p * err_p; //  + ki * i_part;
//	        
//	float limit = 0.5f;
//	
//	if (qdd_ref(0) < -limit)
//		qdd_ref(0) = -limit;
//	else if (qdd_ref(0) > limit)
//		qdd_ref(0) = limit;
//	
//	if (qdd_ref(1) < -limit)
//		qdd_ref(1) = -limit;
//	else if (qdd_ref(1) > limit)
//		qdd_ref(1) = limit;
//	
//	Vec2f gcomp = gravCompTau(q) * g_fact;
//	ParameterStore::setOutParameter("gravComp", gcomp);
//	Vec2f tau = gcomp + qdd_ref;
	
	Mat22f mat;
	mat(0, 0) = tau(0);
	mat(1, 0) = tau(1);
	mat(0, 1) = qdd_ref(0);
	mat(1, 1) = qdd_ref(1);
	
	return mat;
}

ml::Vec2f InverseDynamicsController::tauFromConfig(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& qdd) {
	Vec2f tau;
	
	const float l1 = 0.17, l2 = 0.14, lc1 = -0.085, lc2 = -0.095;
	const float g = 9.81;
	const float m1 = ParameterStore::get("m1", 0.08), m2 = ParameterStore::get("m2", 0.2);
	
	const float I1zz = 0.0481f * m1 / 12.0f, I2zz = 0.0149f * m2 / 12.0f;
	
	float s1 = sinf(q(0)), s2 = sinf(q(1));
	float c1 = cosf(q(0)), c2 = cosf(q(1));
	float s12 = sinf(q(0) + q(1)), c12 = cosf(q(0) + q(1));
	
	Mat33f R10 = Mat33f::zeros();
	R10(0, 0) = c1;
	R10(1, 0) = -s1;
	R10(0, 1) = s1;
	R10(1, 1) = c1;
	R10(2, 2) = 1;
	
	Mat33f R12 = Mat33f::zeros();
	R12(0, 0) = c2;
	R12(1, 0) = s2;
	R12(0, 1) = -s2;
	R12(1, 1) = c2;
	R12(2, 2) = 1;
	
	Vec3f r01 = makeVec3f(l1 * c1, l1 * s1, 0);
	
	// NE.1 and NE.2
	
	// i = 1
	//Vec3f w1 = makeVec3f(0, 0, qd(0));
	//Vec3f wd1 = makeVec3f(0, 0, qdd(0));
	//Vec3f v1 = makeVec3f(0, l1 * qd(0), 0);
	Vec3f vd1 = makeVec3f(s1, c1, 0) * g + makeVec3f(0, l1 * qdd(0), 0) + makeVec3f(-l1 * qd(0) * qd(0), 0, 0);
	Vec3f vdc1 = vd1 + makeVec3f(0, qdd(0) * lc1, 0) + makeVec3f(-lc1 * qd(0) * qd(0), 0, 0);
	Vec3f F1 = vdc1 * m1;
	Vec3f N1 = makeVec3f(0, 0, I1zz * qdd(0));
	
	// i = 2
	///Vec3f w2 = makeVec3f(0, 0, qd(0) + qd(1));
	//Vec3f wd2 = makeVec3f(0, 0, qdd(0) + qdd(1));
	// Vec3f v2 = makeVec3f(s2, c2, 0) * (l1 * qd(0)) + makeVec3f(0, l2 * (qd(0) + qd(1)), 0);
	Vec3f vd2 = makeVec3f(s12, c12, 0) * g + makeVec3f(s2, c2, 0) * (l1 * qdd(0))
	        + makeVec3f(-c2, s2, 0) * (l1 * qd(0) * qd(0)) + makeVec3f(0, l2 * (qdd(0) + qdd(1)), 0)
	        + makeVec3f(-l2 * (qd(0) + qd(1)) * (qd(0) + qd(1)), 0, 0);
	Vec3f vdc2 = vd2 + makeVec3f(0, lc2 * (qdd(0) + qdd(1)), 0)
	        + makeVec3f(-lc2 * (qd(0) + qd(1)) * (qd(0) + qd(1)), 0, 0);
	Vec3f F2 = m2 * vdc2;
	Vec3f N2 = makeVec3f(0, 0, I2zz * (qdd(0) + qdd(1)));
	
	// NE.3
	
	// i = 2
	Vec3f f2 = F2;
	Vec3f n2 = m2 * cross(makeVec3f(l2 + lc2, 0, 0), vdc2) + N2;
	
	tau(1) = n2(2);
	
	// i = 1
	// Vec3f f1 = R12 * f2 + F1;
	Vec3f n1 = R12 * n2 + cross(R10 * r01 + makeVec3f(lc1, 0, 0), F1) + cross(R10 * r01, R12 * f2) + N1;
	
	tau(0) = n1(2);
	
	return tau * ParameterStore::get("tauFact", 0.5);
}

void InverseDynamicsController::setKP(const std_msgs::Float32& msg) {
	k_p = msg.data;
}

void InverseDynamicsController::setKD(const std_msgs::Float32& msg) {
	k_d = msg.data;
}

ml::Vec2f InverseDynamicsController::gravCompTau(const ml::Vec2f& q) const {
	ml::Vec2f tau;
	
	const float m1 = 0.08, m2 = 0.2;
// const float m = m1 + m2;
	
	const float l1 = 0.17, lc1 = 0.085, lc2 = 0.045;
	
	float c1 = cos(q(0)), c12 = cos(q(0) + q(1));
	tau(0) = m1 * lc1 * c1 + m2 * (l1 * c1 + lc2 * c12);
	tau(1) = m2 * lc2 * c12;
	
	return tau;
}
