#ifndef _ROS_sr_ronex_msgs_ImpulseSample_h
#define _ROS_sr_ronex_msgs_ImpulseSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_ronex_msgs
{

  class ImpulseSample : public ros::Msg
  {
    public:
      int16_t real = 0;
      int16_t imaginary = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->real;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->real);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->imaginary;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->imaginary);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->real = u_.real;
      }
      offset += sizeof(this->real);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imaginary = u_.real;
      }
      offset += sizeof(this->imaginary);
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/ImpulseSample"; };
    const char * getMD5(){ return "1a6cc52cb69fe83d58c1fc831cda158d"; };

  };

}
#endif