#ifndef _ROS_pr2_msgs_BatteryServer_h
#define _ROS_pr2_msgs_BatteryServer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pr2_msgs/BatteryState.h"
#include <vector>

namespace pr2_msgs
{

  class BatteryServer : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t id = 0;
      int32_t lastTimeSystem = 0;
      uint16_t timeLeft = 0;
      uint16_t averageCharge = 0;
      char * message = nullptr;
      int32_t lastTimeController = 0;
      uint16_t present = 0;
      uint16_t charging = 0;
      uint16_t discharging = 0;
      uint16_t reserved = 0;
      uint16_t powerPresent = 0;
      uint16_t powerNG = 0;
      uint16_t inhibited = 0;
      std::vector<pr2_msgs::BatteryState> battery;
      enum { MAX_BAT_COUNT = 4 };
      enum { MAX_BAT_REG = 48 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->id);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->lastTimeSystem;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->lastTimeSystem);
      *(outbuffer + offset + 0) = (this->timeLeft >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeLeft >> (8 * 1)) & 0xFF;
      offset += sizeof(this->timeLeft);
      *(outbuffer + offset + 0) = (this->averageCharge >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->averageCharge >> (8 * 1)) & 0xFF;
      offset += sizeof(this->averageCharge);
      {
      uint32_t length_ = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->lastTimeController;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->lastTimeController);
      *(outbuffer + offset + 0) = (this->present >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->present >> (8 * 1)) & 0xFF;
      offset += sizeof(this->present);
      *(outbuffer + offset + 0) = (this->charging >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charging >> (8 * 1)) & 0xFF;
      offset += sizeof(this->charging);
      *(outbuffer + offset + 0) = (this->discharging >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->discharging >> (8 * 1)) & 0xFF;
      offset += sizeof(this->discharging);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved);
      *(outbuffer + offset + 0) = (this->powerPresent >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->powerPresent >> (8 * 1)) & 0xFF;
      offset += sizeof(this->powerPresent);
      *(outbuffer + offset + 0) = (this->powerNG >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->powerNG >> (8 * 1)) & 0xFF;
      offset += sizeof(this->powerNG);
      *(outbuffer + offset + 0) = (this->inhibited >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->inhibited >> (8 * 1)) & 0xFF;
      offset += sizeof(this->inhibited);
      unsigned battery_length = battery.size();
      outbuffer[offset++] = (battery_length >> 0) & 0xFF;
      outbuffer[offset++] = (battery_length >> 8) & 0xFF;
      outbuffer[offset++] = (battery_length >> 16) & 0xFF;
      outbuffer[offset++] = (battery_length >> 24) & 0xFF;
      for( unsigned i = 0; i < battery_length; i++){
      offset += this->battery[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      this->id = u_.real;
      }
      offset += sizeof(this->id);
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
      this->lastTimeSystem = u_.real;
      }
      offset += sizeof(this->lastTimeSystem);
      this->timeLeft =  ((uint16_t) (*(inbuffer + offset)));
      this->timeLeft |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->timeLeft);
      this->averageCharge =  ((uint16_t) (*(inbuffer + offset)));
      this->averageCharge |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->averageCharge);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
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
      this->lastTimeController = u_.real;
      }
      offset += sizeof(this->lastTimeController);
      this->present =  ((uint16_t) (*(inbuffer + offset)));
      this->present |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->present);
      this->charging =  ((uint16_t) (*(inbuffer + offset)));
      this->charging |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->charging);
      this->discharging =  ((uint16_t) (*(inbuffer + offset)));
      this->discharging |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->discharging);
      this->reserved =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved);
      this->powerPresent =  ((uint16_t) (*(inbuffer + offset)));
      this->powerPresent |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->powerPresent);
      this->powerNG =  ((uint16_t) (*(inbuffer + offset)));
      this->powerNG |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->powerNG);
      this->inhibited =  ((uint16_t) (*(inbuffer + offset)));
      this->inhibited |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->inhibited);
      unsigned battery_length = inbuffer[offset++];
      battery_length |= inbuffer[offset++] << 8;
      battery_length |= inbuffer[offset++] << 16;
      battery_length |= inbuffer[offset++] << 24;
      battery.clear();
      battery.reserve(battery_length);
      for( unsigned i = 0; i < battery_length; i++){
      battery.emplace_back();
      offset += this->battery.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/BatteryServer"; };
    const char * getMD5(){ return "4f6d6e54c9581beb1df7ea408c0727be"; };

  };

}
#endif