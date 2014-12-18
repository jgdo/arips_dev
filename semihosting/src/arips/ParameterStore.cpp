/*
 * ParameterStore.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: jgdo
 */

#include <arips/ParameterStore.h>

#include <iostream>

using namespace std;

#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */
#define FLASH_DATA_START ADDR_FLASH_SECTOR_11

std::map<std::string, float> ParameterStore::paramMap, ParameterStore::sayMap;

arips_msgs::ParameterArray ParameterStore::pub_msg;
arips_msgs::Parameter ParameterStore::sub_msg;

ros::Publisher ParameterStore::param_pub("/parameters", &ParameterStore::pub_msg);
ros::Subscriber<arips_msgs::Parameter> ParameterStore::param_sub("set_parameter", &ParameterStore::onParameterReceived);
ros::Subscriber<std_msgs::String> ParameterStore::cmd_sub("param_cmd", &ParameterStore::onCommandReceived);

void ParameterStore::publishOutParameters() {
	pub_msg.parameters.clear();
	pub_msg.parameters.reserve(sayMap.size());
	
	arips_msgs::Parameter param;
	for (auto& entry : sayMap) {
		param.name = (char*) entry.first.c_str();
		param.value = entry.second;
		pub_msg.parameters.push_back(param);
	}
	
	param_pub.publish(&pub_msg);
}

void ParameterStore::registerPubSub() {
	nodeHandle.subscribe(param_sub);
	nodeHandle.subscribe(cmd_sub);
	nodeHandle.advertise(param_pub);
}

void ParameterStore::onParameterReceived(const arips_msgs::Parameter& param) {
	paramMap[param.name] = param.value;
}

void ParameterStore::onCommandReceived(const std_msgs::String& cmd) {
	if (!strcmp(cmd.data, "save") || !strcmp(cmd.data, "flash") || !strcmp(cmd.data, "write")) {
		writeToFlash();
	} else if (!strcmp(cmd.data, "load") || !strcmp(cmd.data, "read")) {
		readFromFlash(true);
	} else if (!strcmp(cmd.data, "reset") || !strcmp(cmd.data, "default")) {
		readFromFlash(false);
	}
}

bool checkIntHiLowOk(int& i) {
	int low = i & 0xFFFF;
	int hi = (i >> 16) & 0xffFF;
	i = low;
	return (((~hi) & 0xFFFF) == low);
}

void writeFlashString(uint32_t& addr, const std::string& str) {
	int len = str.size();
	FLASH_ProgramWord(addr, len | ((~(len << 16))&0xFFFF0000));
	auto bytes = str.c_str();
	
	addr += 4;
	for (auto i = 0; i < len; i++)
		FLASH_ProgramByte(addr++, bytes[i]);
	
	addr = (addr + 3) & 0xFFFFFFFC; // align to 4 bytes
}

void writeFlashFloat(uint32_t& addr, float f) {
	FLASH_ProgramWord(addr, *(uint32_t*) &f);
	addr += 4;
}

void writeFlashInt(uint32_t& addr, int i) {
	FLASH_ProgramWord(addr, *(uint32_t*) &i);
	addr += 4;
}

void ParameterStore::writeToFlash() {
	cout << "saving parameters to flash" << endl;
	
	// see http://micromouseusa.com/?p=1556
	
	FLASH_Unlock(); // you need to unlcok flash first
	/* Clear All pending flags */
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
	
	//you need to erase entire sector before write anything
	FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);
	
	//VoltageRange_1        ((uint8_t)0x00)  /*!< Device operating range: 1.8V to 2.1V */
	//VoltageRange_2        ((uint8_t)0x01)  /*!<Device operating range: 2.1V to 2.7V */
	//VoltageRange_3        ((uint8_t)0x02)  /*!<Device operating range: 2.7V to 3.6V */
	//VoltageRange_4        ((uint8_t)0x03)  /*!<Device operating range: 2.7V to 3.6V +   External Vpp */
	//mSize = 16 for full size micromouse maze
	//int16_t mazeWalls[mSize][mSize]  to hold wall information.
	
	//start to copy wall information into flash, the address must exceed every 32bit
	
	//for STM32F4 even if you are only writing 16 bit or 8 bit data
	
	//You only need to exceed 16bit per address by calling the same	
	uint32_t addr = FLASH_DATA_START;
	writeFlashInt(addr, paramMap.size() | ((~(paramMap.size() << 16))&0xFFFF0000));
	
	for (auto& iter : paramMap) {
		writeFlashString(addr, iter.first);
		writeFlashFloat(addr, iter.second);
	}
	
	FLASH_Lock(); //lock flash at the end
}

int readFlashInt(uint32_t& addr) {
	int i = *(int*) addr;
	addr += 4;
	return i;
}

char readFlashChar(uint32_t& addr) {
	char c = *(char*) addr;
	addr += 1;
	return c;
}

std::string readFlashString(uint32_t& addr) {
	int len = readFlashInt(addr);
	if (checkIntHiLowOk(len)) {
		char strdata[len + 1];
		
		for (auto i = 0; i < len; i++)
			strdata[i] = readFlashChar(addr);
		
		strdata[len] = 0;
		
		addr = (addr + 3) & 0xFFFFFFFC; // align to 4 bytes
		        
		return std::string(strdata);
	} else
		return "";
}

float readFlashFloat(uint32_t& addr) {
	float f = *(float*) addr;
	addr += 4;
	return f;
}

void ParameterStore::readFromFlash(bool clear_before) {
	uint32_t addr = FLASH_DATA_START;
	int numParams = readFlashInt(addr);
		
	if (checkIntHiLowOk(numParams)) { // simple consistency check
		cout << "Num params: " << numParams << endl;
		
		if (clear_before)
			paramMap.clear();
		
		for (int i = 0; i < numParams; i++) {
			std::string name = readFlashString(addr);
			if (name.empty())
				break;
			
			float f = readFlashFloat(addr);
			paramMap[name] = f;
			
			// cout << "[" << name << "]: " << f << endl;
		}
	} else {
		cout << "flash not set" << endl;
	}
}

