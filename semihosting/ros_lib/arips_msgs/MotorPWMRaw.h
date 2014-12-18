#ifndef _ROS_arips_msgs_MotorPWMRaw_h
#define _ROS_arips_msgs_MotorPWMRaw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_msgs
{

  class MotorPWMRaw : public ros::Msg
  {
    public:
      uint8_t motor_index = 0;
      float pwm_value = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_index);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->pwm_value;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->pwm_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->motor_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_index);
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
      this->pwm_value = u_.real;
      }
      offset += sizeof(this->pwm_value);
     return offset;
    }

    const char * getType(){ return "arips_msgs/MotorPWMRaw"; };
    const char * getMD5(){ return "6c43e82666517db1192bb2942b510d3f"; };

  };

}
#endif