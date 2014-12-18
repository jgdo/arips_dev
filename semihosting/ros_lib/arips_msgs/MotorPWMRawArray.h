#ifndef _ROS_arips_msgs_MotorPWMRawArray_h
#define _ROS_arips_msgs_MotorPWMRawArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_msgs/MotorPWMRaw.h"
#include <vector>

namespace arips_msgs
{

  class MotorPWMRawArray : public ros::Msg
  {
    public:
      std::vector<arips_msgs::MotorPWMRaw> motor_pwm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned motor_pwm_length = motor_pwm.size();
      outbuffer[offset++] = (motor_pwm_length >> 0) & 0xFF;
      outbuffer[offset++] = (motor_pwm_length >> 8) & 0xFF;
      outbuffer[offset++] = (motor_pwm_length >> 16) & 0xFF;
      outbuffer[offset++] = (motor_pwm_length >> 24) & 0xFF;
      for( unsigned i = 0; i < motor_pwm_length; i++){
      offset += this->motor_pwm[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned motor_pwm_length = inbuffer[offset++];
      motor_pwm_length |= inbuffer[offset++] << 8;
      motor_pwm_length |= inbuffer[offset++] << 16;
      motor_pwm_length |= inbuffer[offset++] << 24;
      motor_pwm.clear();
      motor_pwm.reserve(motor_pwm_length);
      for( unsigned i = 0; i < motor_pwm_length; i++){
      motor_pwm.emplace_back();
      offset += this->motor_pwm.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/MotorPWMRawArray"; };
    const char * getMD5(){ return "2c0cb1c741eca47347b739f5f254a77c"; };

  };

}
#endif