/*
 * XV11Lidar.h
 *
 *  Created on: Aug 16, 2014
 *      Author: jgdo
 */

#ifndef XV11LIDAR_H_
#define XV11LIDAR_H_

#include <lib/Motor.h>
#include <lib/InterruptQueue.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/LaserScan.h>

class XV11Lidar {
public:
	XV11Lidar(Motor& motor);
	
	void turnOn();
	void turnOff();

	void checkData();

	static void uartByteReceived(unsigned char c);

private:
	static InterruptQueue<unsigned char, 128> uart_queue;
	
	int byte_count = 0, rpm_valid_count = 0;
	unsigned char data_buffer[22];
	int last_packet_index = 0;

	Motor& motor;
	float motor_voltage = 0.0;
	float last_rpm_estimate = 0;

	std_msgs::Float32 rpm_msg;
	ros::Publisher rpm_pub;

	sensor_msgs::LaserScan scan_msg;
	ros::Publisher scan_pub;

	float scan_dist[360], scan_intensities[360];

	void processPacket();
	
	int computeChecksum() const;
	
	void publishMesssageAndControlMotor();
	
	void controlMotor();

	inline uint16_t getShort(int index) const {
		return (data_buffer[index + 1] << 8) + data_buffer[index];
	}
};

#endif /* XV11LIDAR_H_ */
