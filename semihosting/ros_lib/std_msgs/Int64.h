#ifndef _ROS_std_msgs_Int64_h
#define _ROS_std_msgs_Int64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

  class Int64 : public ros::Msg
  {
    public:
      int64_t data = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.real = this->data;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_.base >> (8 * 7)) & 0xFF;
      }
      offset += sizeof(this->data);
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
      this->data = u_.real;
      }
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "std_msgs/Int64"; };
    const char * getMD5(){ return "34add168574510e6e17f5d23ecc077ef"; };

  };

}
#endif