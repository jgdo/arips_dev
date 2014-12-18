#ifndef _ROS_std_msgs_Bool_h
#define _ROS_std_msgs_Bool_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

  class Bool : public ros::Msg
  {
    public:
      bool data = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->data;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_.real;
      }
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "std_msgs/Bool"; };
    const char * getMD5(){ return "8b94c1b53db61fb6aed406028ad6332a"; };

  };

}
#endif