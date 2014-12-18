/*
 * XV11Lidar.cpp
 *
 *  Created on: Aug 16, 2014
 *      Author: jgdo
 */

#include <stm32f4xx.h>
#include <stm32f4xx_usart.h>
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "misc.h"
#include <lidar/XV11Lidar.h>

#include <stdio.h>

InterruptQueue<unsigned char, 128> XV11Lidar::uart_queue;

XV11Lidar::XV11Lidar(Motor& motor) :
		motor(motor), rpm_pub("/lidar_rpm", &rpm_msg), scan_pub("/scan", &scan_msg) {
	
	// see http://eliaselectronics.com/stm32f4-tutorials/stm32f4-usart-tutorial/
	
	/* This is a concept that has to do with the libraries provided by ST
	 * to make development easier the have made up something similar to
	 * classes, called TypeDefs, which actually just define the common
	 * parameters that every peripheral needs to work correctly
	 *
	 * They make our life easier because we don't have to mess around with
	 * the low level stuff of setting bits in the correct registers
	 */
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the UART4 initialization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)
	
	/* enable APB1 peripheral clock for USART4
	 */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	
	/* 
	 * PC11 UART 4 RX
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; // the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; // this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;	// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStruct);	// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	        
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);
	
	/* Now the UART_InitStruct is used to define the
	 * properties of UART4
	 */
	USART_InitStruct.USART_BaudRate = 115200;	// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;	// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(UART4, &USART_InitStruct); // again all the properties are passed to the USART_Init function which takes care of all the bit setting
	        
	/* Here the UART4 receive interrupt is enabled
	 * and the interrupt controller is configured
	 * to jump to the UART4_IRQHandler() function
	 * if the UART4 receive interrupt occurs
	 */
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); // enable the UART4 receive interrupt
	        
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;		 // we want to configure the UART4 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	// this sets the priority group of the UART4 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);	// the properties are passed to the NVIC_Init function which takes care of the low level stuff
	        
	// finally this enables the complete UART4 peripheral
	USART_Cmd(UART4, ENABLE);
	
	nodeHandle.advertise(rpm_pub);
	nodeHandle.advertise(scan_pub);
}

void XV11Lidar::checkData() {
	while (!uart_queue.empty()) {
		unsigned char c = uart_queue.pop();
		
		data_buffer[byte_count] = c;
		
		if (byte_count == 0) { // wait for sync
			if (c == 0xFA)
				byte_count = 1;
		} else if (byte_count == 1) { // read position
			if (c >= 0xA0 && c <= 0xF9) {
				byte_count = 2;
			} else if (c != 0xFA)
				byte_count = 0;
		} else { // data
			byte_count++;
			
			if (byte_count == 22) { // full packet received
				byte_count = 0;
				
				// process packet if checksum is ok
				if (getShort(20) == computeChecksum())
					processPacket();
				// ignore otherwise
			}
		}
	}
}

void XV11Lidar::uartByteReceived(unsigned char c) {
	uart_queue.append(c);
}

void XV11Lidar::processPacket() {
	float rpm = getShort(2) / 64.0f;
	rpm_msg.data += rpm;
	rpm_valid_count++;
	
	int index = (data_buffer[1] - 0xA0) * 4; // angle index
	        
	// if index has wrapped around it means we lost some packets
	// -> send the scan anyway, ignore unknown data
	// if (index < last_packet_index)
	//	publishMesssageAndControlMotor();
	
	last_packet_index = index;
	
	for (int i = 0; i < 4; i++) {
		int dist = getShort(i * 4 + 4) & 0x3FFF;
		int intensity = getShort(i * 4 + 6);
		
		scan_dist[index] = dist / 1000.0f;
		scan_intensities[index] = intensity;
		index++;
	}
	
	if (index >= 360) {  // scan end
		publishMesssageAndControlMotor();
		last_packet_index = 0; // avoid publishing message next time
	}
}

int XV11Lidar::computeChecksum() const {
	// see https://github.com/Xevel/NXV11/blob/master/XV-11_test_python/XV-11_test.py
	
	unsigned int chk32 = 0;
	
	for (int i = 0; i < 10; i++)
		chk32 = (chk32 << 1) + getShort(i * 2);
	
	return ((chk32 & 0x7FFF) + (chk32 >> 15)) & 0x7FFF;
}

void XV11Lidar::publishMesssageAndControlMotor() {
	scan_msg.header.stamp = ros::Time::now();
	scan_msg.header.frame_id = "/base_link";
	
	scan_msg.angle_min = 0.0;
	scan_msg.angle_max = 2.0 * M_PI;
	scan_msg.angle_increment = (2.0 * M_PI / 360.0);
	scan_msg.range_min = 0.2;
	scan_msg.range_max = 6.0;
	// TODO time_increment, scan_time
	
	scan_msg.ranges.assign(scan_dist, scan_dist + 360);
	
	scan_msg.intensities.assign(scan_intensities, scan_intensities+360);
	
	if (rpm_valid_count > 0) {
		rpm_msg.data /= rpm_valid_count;
		last_rpm_estimate = rpm_msg.data;
		rpm_pub.publish(&rpm_msg);
	}
	scan_pub.publish(&scan_msg);
	
	rpm_msg.data = 0; // reset rpm
	rpm_valid_count = 0;
	
	for (int i = 0; i < 360; i++)
		scan_dist[i] = scan_intensities[i] = 0; // mark all scans as for next time
		        
	controlMotor();
}

void XV11Lidar::turnOn() {
	motor_voltage = 0.35; // start with voltage enough to begin spinning
	motor.set(motor_voltage);
}

void XV11Lidar::turnOff() {
	motor_voltage = 0;
	motor.set(motor_voltage);
}

void XV11Lidar::controlMotor() {
	if (motor_voltage > 0) { // motor is turned on
		if (last_rpm_estimate < 270)
			motor_voltage += 0.003;
		else if (last_rpm_estimate > 280)
			motor_voltage -= 0.003;
		
		if (motor_voltage > 0.45)
			motor_voltage = 0.45; // limit voltage
			        
		motor.set(motor_voltage);
	}
}

extern "C" void UART4_IRQHandler(void) {
// check if the USART1 receive interrupt flag was set
	if (USART_GetITStatus(UART4, USART_IT_RXNE)) {
		
		unsigned char c = UART4->DR; // the character from the UART4 data register
		XV11Lidar::uartByteReceived(c);
		
		USART_ClearITPendingBit(UART4, USART_IT_RXNE);
	}
}
