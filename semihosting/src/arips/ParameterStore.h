/*
 * ParameterStore.h
 *
 *  Created on: Sep 12, 2014
 *      Author: jgdo
 */

#ifndef PARAMETERSTORE_H_
#define PARAMETERSTORE_H_

#include <map>

#include <m/Matrix.h>

#include <ros.h>
#include <std_msgs/String.h>
#include <arips_msgs/ParameterArray.h>

class ParameterStore {
public:
	static inline float get(const char* name, float default_value) {
		auto iter = paramMap.find(name);
		if (iter == paramMap.end())
			return default_value;
		else
			return iter->second;
	}
	
	static void say(const char* name, float value) {
		sayMap[name] = value;
	}
	
	template<unsigned R, unsigned C>
	static void say(const char* name, const ml::Matf<R, C>& m) {
		std::string ns = std::string(name) + "(0,0)";
		unsigned off = ns.size() - 4;
		
		for (unsigned r = 0; r < R; r++) {
			for (unsigned c = 0; c < C; c++) {
				ns[off] = '0' + r;
				ns[off + 2] = '0' + c;
				sayMap[ns] = m(r, c);
			}
		}
	}
	
	template<unsigned R>
	static void say(const char* name, const ml::Vecf<R>& m) {
		std::string ns = std::string(name) + "(0)";
		unsigned off = ns.size() - 2;
		
		for (unsigned r = 0; r < R; r++) {
			ns[off] = '0' + r;
			sayMap[ns] = m(r);
		}
	}
	
	static void writeToFlash();
	
	static void readFromFlash(bool clear_before);
	
	static void registerPubSub();

	static void publishOutParameters();

private:
	static std::map<std::string, float> paramMap, sayMap;

	static arips_msgs::ParameterArray pub_msg;
	static arips_msgs::Parameter sub_msg;

	static ros::Publisher param_pub;
	static ros::Subscriber<arips_msgs::Parameter> param_sub;
	static ros::Subscriber<std_msgs::String> cmd_sub;
	
	static void onParameterReceived(const arips_msgs::Parameter& param);
	
	static void onCommandReceived(const std_msgs::String& cmd);
};

#endif /* PARAMETERSTORE_H_ */
