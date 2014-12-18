#ifndef _ROS_arips_msgs_ServoPosition_h
#define _ROS_arips_msgs_ServoPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace arips_msgs
{

  class ServoPosition : public ros::Msg
  {
    public:
      uint32_t mask = 0;
      std::vector<float> positions;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mask);
      unsigned positions_length = positions.size();
      outbuffer[offset++] = (positions_length >> 0) & 0xFF;
      outbuffer[offset++] = (positions_length >> 8) & 0xFF;
      outbuffer[offset++] = (positions_length >> 16) & 0xFF;
      outbuffer[offset++] = (positions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < positions_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->positions[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->positions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mask =  ((uint32_t) (*(inbuffer + offset)));
      this->mask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mask);
      unsigned positions_length = inbuffer[offset++];
      positions_length |= inbuffer[offset++] << 8;
      positions_length |= inbuffer[offset++] << 16;
      positions_length |= inbuffer[offset++] << 24;
      positions.clear();
      positions.reserve(positions_length);
      for( unsigned i = 0; i < positions_length; i++){
      positions.emplace_back();
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
      this->positions.back() = u_.real;
      }
      offset += sizeof(this->positions.back());
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/ServoPosition"; };
    const char * getMD5(){ return "1259631a2889d030eef29382ca1d6de3"; };

  };

}
#endif