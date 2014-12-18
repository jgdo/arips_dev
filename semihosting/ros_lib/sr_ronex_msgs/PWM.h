#ifndef _ROS_sr_ronex_msgs_PWM_h
#define _ROS_sr_ronex_msgs_PWM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_ronex_msgs
{

  class PWM : public ros::Msg
  {
    public:
      uint16_t pwm_period = 0;
      uint16_t pwm_on_time_0 = 0;
      uint16_t pwm_on_time_1 = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pwm_period >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm_period >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_period);
      *(outbuffer + offset + 0) = (this->pwm_on_time_0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm_on_time_0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_on_time_0);
      *(outbuffer + offset + 0) = (this->pwm_on_time_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm_on_time_1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_on_time_1);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pwm_period =  ((uint16_t) (*(inbuffer + offset)));
      this->pwm_period |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pwm_period);
      this->pwm_on_time_0 =  ((uint16_t) (*(inbuffer + offset)));
      this->pwm_on_time_0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pwm_on_time_0);
      this->pwm_on_time_1 =  ((uint16_t) (*(inbuffer + offset)));
      this->pwm_on_time_1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pwm_on_time_1);
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/PWM"; };
    const char * getMD5(){ return "09d4129905f63410b7c71ee5d97925f3"; };

  };

}
#endif