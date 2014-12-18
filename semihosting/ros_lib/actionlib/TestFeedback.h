#ifndef _ROS_actionlib_TestFeedback_h
#define _ROS_actionlib_TestFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actionlib
{

  class TestFeedback : public ros::Msg
  {
    public:
      int32_t feedback = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->feedback;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->feedback);
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
      this->feedback = u_.real;
      }
      offset += sizeof(this->feedback);
     return offset;
    }

    const char * getType(){ return "actionlib/TestFeedback"; };
    const char * getMD5(){ return "49ceb5b32ea3af22073ede4a0328249e"; };

  };

}
#endif