#ifndef _ROS_sr_ronex_msgs_BoolArray_h
#define _ROS_sr_ronex_msgs_BoolArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace sr_ronex_msgs
{

  class BoolArray : public ros::Msg
  {
    public:
      std::vector<bool> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->data[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned data_length = inbuffer[offset++];
      data_length |= inbuffer[offset++] << 8;
      data_length |= inbuffer[offset++] << 16;
      data_length |= inbuffer[offset++] << 24;
      data.clear();
      data.reserve(data_length);
      for( unsigned i = 0; i < data_length; i++){
      data.emplace_back();
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data.back() = u_.real;
      }
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/BoolArray"; };
    const char * getMD5(){ return "403a16d9294b908e45c67a6f3c3a5b27"; };

  };

}
#endif