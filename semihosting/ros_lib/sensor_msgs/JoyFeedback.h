#ifndef _ROS_sensor_msgs_JoyFeedback_h
#define _ROS_sensor_msgs_JoyFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

  class JoyFeedback : public ros::Msg
  {
    public:
      uint8_t type = 0;
      uint8_t id = 0;
      float intensity = 0;
      enum { TYPE_LED =  0 };
      enum { TYPE_RUMBLE =  1 };
      enum { TYPE_BUZZER =  2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->intensity;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->intensity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
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
      this->intensity = u_.real;
      }
      offset += sizeof(this->intensity);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/JoyFeedback"; };
    const char * getMD5(){ return "f4dcd73460360d98f36e55ee7f2e46f1"; };

  };

}
#endif