#ifndef _ROS_sensor_msgs_LaserEcho_h
#define _ROS_sensor_msgs_LaserEcho_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace sensor_msgs
{

  class LaserEcho : public ros::Msg
  {
    public:
      std::vector<float> echoes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned echoes_length = echoes.size();
      outbuffer[offset++] = (echoes_length >> 0) & 0xFF;
      outbuffer[offset++] = (echoes_length >> 8) & 0xFF;
      outbuffer[offset++] = (echoes_length >> 16) & 0xFF;
      outbuffer[offset++] = (echoes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < echoes_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->echoes[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->echoes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned echoes_length = inbuffer[offset++];
      echoes_length |= inbuffer[offset++] << 8;
      echoes_length |= inbuffer[offset++] << 16;
      echoes_length |= inbuffer[offset++] << 24;
      echoes.clear();
      echoes.reserve(echoes_length);
      for( unsigned i = 0; i < echoes_length; i++){
      echoes.emplace_back();
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->echoes.back() = u_.real;
      }
      offset += sizeof(this->echoes.back());
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/LaserEcho"; };
    const char * getMD5(){ return "8bc5ae449b200fba4d552b4225586696"; };

  };

}
#endif