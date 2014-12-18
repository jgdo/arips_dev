#ifndef _ROS_actionlib_tutorials_FibonacciFeedback_h
#define _ROS_actionlib_tutorials_FibonacciFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace actionlib_tutorials
{

  class FibonacciFeedback : public ros::Msg
  {
    public:
      std::vector<int32_t> sequence;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned sequence_length = sequence.size();
      outbuffer[offset++] = (sequence_length >> 0) & 0xFF;
      outbuffer[offset++] = (sequence_length >> 8) & 0xFF;
      outbuffer[offset++] = (sequence_length >> 16) & 0xFF;
      outbuffer[offset++] = (sequence_length >> 24) & 0xFF;
      for( unsigned i = 0; i < sequence_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->sequence[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->sequence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned sequence_length = inbuffer[offset++];
      sequence_length |= inbuffer[offset++] << 8;
      sequence_length |= inbuffer[offset++] << 16;
      sequence_length |= inbuffer[offset++] << 24;
      sequence.clear();
      sequence.reserve(sequence_length);
      for( unsigned i = 0; i < sequence_length; i++){
      sequence.emplace_back();
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
      this->sequence.back() = u_.real;
      }
      offset += sizeof(this->sequence.back());
      }
     return offset;
    }

    const char * getType(){ return "actionlib_tutorials/FibonacciFeedback"; };
    const char * getMD5(){ return "b81e37d2a31925a0e8ae261a8699cb79"; };

  };

}
#endif