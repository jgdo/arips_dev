#ifndef _ROS_std_msgs_Byte_h
#define _ROS_std_msgs_Byte_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

  class Byte : public ros::Msg
  {
    public:
      int8_t data = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int8_t real;
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
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_.real;
      }
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "std_msgs/Byte"; };
    const char * getMD5(){ return "ad736a2e8818154c487bb80fe42ce43b"; };

  };

}
#endif