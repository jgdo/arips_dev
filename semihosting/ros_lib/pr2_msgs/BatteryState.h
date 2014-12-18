#ifndef _ROS_pr2_msgs_BatteryState_h
#define _ROS_pr2_msgs_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace pr2_msgs
{

  class BatteryState : public ros::Msg
  {
    public:
      int32_t lastTimeBattery = 0;
      uint16_t batReg[48];
      static const unsigned batReg_length = 48;
      uint16_t batRegFlag[48];
      static const unsigned batRegFlag_length = 48;
      int32_t batRegTime[48];
      static const unsigned batRegTime_length = 48;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->lastTimeBattery;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->lastTimeBattery);
      for( unsigned i = 0; i < 48; i++){
      *(outbuffer + offset + 0) = (this->batReg[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->batReg[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->batReg[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      *(outbuffer + offset + 0) = (this->batRegFlag[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->batRegFlag[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->batRegFlag[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->batRegTime[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->batRegTime[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lastTimeBattery = u_.real;
      }
      offset += sizeof(this->lastTimeBattery);
      for( unsigned i = 0; i < 48; i++){
      this->batReg[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->batReg[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->batReg[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      this->batRegFlag[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->batRegFlag[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->batRegFlag[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batRegTime[i] = u_.real;
      }
      offset += sizeof(this->batRegTime[i]);
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/BatteryState"; };
    const char * getMD5(){ return "00e9f996c2fc26700fd25abcd8422db0"; };

  };

}
#endif