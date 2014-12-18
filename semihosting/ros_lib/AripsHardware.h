/*
 * AripsHardware.h
 *
 *  Created on: Aug 9, 2014
 *      Author: jgdo
 */

#ifndef ARIPSHARDWARE_H_
#define ARIPSHARDWARE_H_

#include "usbd_cdc_vcp.h"
#include "lib/Timer.h"

class AripsHardware {
public:
	AripsHardware() {
	}
	
	void init() {
	}
	
	int read() {
		return VCP_GetNextReceivedByte();
	}
	
	void write(uint8_t* data, int length) {
		VCP_SendBuf(data, length);
	}
	
	double time() {
		return SystemMillisDouble();
	}
};

#endif /* ARIPSHARDWARE_H_ */
