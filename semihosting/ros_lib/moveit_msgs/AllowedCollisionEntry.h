#ifndef _ROS_moveit_msgs_AllowedCollisionEntry_h
#define _ROS_moveit_msgs_AllowedCollisionEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace moveit_msgs
{

  class AllowedCollisionEntry : public ros::Msg
  {
    public:
      std::vector<bool> enabled;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned enabled_length = enabled.size();
      outbuffer[offset++] = (enabled_length >> 0) & 0xFF;
      outbuffer[offset++] = (enabled_length >> 8) & 0xFF;
      outbuffer[offset++] = (enabled_length >> 16) & 0xFF;
      outbuffer[offset++] = (enabled_length >> 24) & 0xFF;
      for( unsigned i = 0; i < enabled_length; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->enabled[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->enabled[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned enabled_length = inbuffer[offset++];
      enabled_length |= inbuffer[offset++] << 8;
      enabled_length |= inbuffer[offset++] << 16;
      enabled_length |= inbuffer[offset++] << 24;
      enabled.clear();
      enabled.reserve(enabled_length);
      for( unsigned i = 0; i < enabled_length; i++){
      enabled.emplace_back();
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled.back() = u_.real;
      }
      offset += sizeof(this->enabled.back());
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionEntry"; };
    const char * getMD5(){ return "90d1ae1850840724bb043562fe3285fc"; };

  };

}
#endif