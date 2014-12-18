/*
 * InverseDynamicsController.h
 *
 *  Created on: Aug 23, 2014
 *      Author: jgdo
 */

#ifndef INVERSEDYNAMICSCONTROLLER_H_
#define INVERSEDYNAMICSCONTROLLER_H_

#include <arm_controller/Controller.h>
#include <ros.h>
#include <std_msgs/Float32.h>

class InverseDynamicsController: public Controller {
public:
	InverseDynamicsController();

	ml::Mat22f computeVoltage(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& q_des, const ml::Vec2f& qd_des,
	        const ml::Vec2f& qdd_des);
	
	inline virtual int defaultControllerFrequency() const {
		return 100;
	}
private:
	double k_p, k_d;
	
	ros::Subscriber<std_msgs::Float32> kp_sub, kd_sub;
	
	ml::Vec2f i_part = ml::Vec2f::zeros();
	
	ml::Vec2f tauFromConfig(const ml::Vec2f& q, const ml::Vec2f& qd, const ml::Vec2f& qdd);
	
	void setKP(const std_msgs::Float32& msg);
	
	void setKD(const std_msgs::Float32& msg);
	
	ml::Vec2f gravCompTau(const ml::Vec2f& q) const;
};

#endif /* INVERSEDYNAMICSCONTROLLER_H_ */
