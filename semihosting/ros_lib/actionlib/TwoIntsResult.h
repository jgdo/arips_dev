#ifndef _ROS_actionlib_TwoIntsResult_h
#define _ROS_actionlib_TwoIntsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actionlib
{

  class TwoIntsResult : public ros::Msg
  {
    public:
      int64_t sum = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.real = this->sum;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_.base >> (8 * 7)) & 0xFF;
      }
      offset += sizeof(this->sum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sum = u_.real;
      }
      offset += sizeof(this->sum);
     return offset;
    }

    const char * getType(){ return "actionlib/TwoIntsResult"; };
    const char * getMD5(){ return "b88405221c77b1878a3cbbfff53428d7"; };

  };

}
#endif