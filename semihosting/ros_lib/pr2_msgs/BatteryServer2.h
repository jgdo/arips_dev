#ifndef _ROS_pr2_msgs_BatteryServer2_h
#define _ROS_pr2_msgs_BatteryServer2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "ros/duration.h"
#include "pr2_msgs/BatteryState2.h"
#include <vector>

namespace pr2_msgs
{

  class BatteryServer2 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t id = 0;
      ros::Time last_system_update;
      ros::Duration time_left;
      int32_t average_charge = 0;
      char * message = nullptr;
      ros::Time last_controller_update;
      std::vector<pr2_msgs::BatteryState2> battery;
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
      *(outbuffer + offset + 0) = (this->last_system_update.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_system_update.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_system_update.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_system_update.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_system_update.sec);
      *(outbuffer + offset + 0) = (this->last_system_update.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_system_update.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_system_update.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_system_update.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_system_update.nsec);
      *(outbuffer + offset + 0) = (this->time_left.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_left.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_left.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_left.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_left.sec);
      *(outbuffer + offset + 0) = (this->time_left.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_left.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_left.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_left.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_left.nsec);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->average_charge;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->average_charge);
      {
      uint32_t length_ = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->last_controller_update.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_controller_update.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_controller_update.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_controller_update.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_controller_update.sec);
      *(outbuffer + offset + 0) = (this->last_controller_update.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_controller_update.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_controller_update.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_controller_update.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_controller_update.nsec);
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
      this->last_system_update.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_system_update.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_system_update.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_system_update.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_system_update.sec);
      this->last_system_update.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_system_update.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_system_update.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_system_update.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_system_update.nsec);
      this->time_left.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_left.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_left.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_left.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_left.sec);
      this->time_left.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_left.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_left.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_left.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_left.nsec);
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
      this->average_charge = u_.real;
      }
      offset += sizeof(this->average_charge);
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
      this->last_controller_update.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_controller_update.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_controller_update.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_controller_update.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_controller_update.sec);
      this->last_controller_update.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_controller_update.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_controller_update.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_controller_update.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_controller_update.nsec);
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

    const char * getType(){ return "pr2_msgs/BatteryServer2"; };
    const char * getMD5(){ return "5f2cec7d06c312d756189db96c1f3819"; };

  };

}
#endif