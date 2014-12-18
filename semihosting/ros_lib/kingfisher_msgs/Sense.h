#ifndef _ROS_kingfisher_msgs_Sense_h
#define _ROS_kingfisher_msgs_Sense_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kingfisher_msgs
{

  class Sense : public ros::Msg
  {
    public:
      float battery = 0;
      float current_left = 0;
      float current_right = 0;
      float pcb_temperature = 0;
      bool fan_on = 0;
      uint8_t rc = 0;
      uint16_t rc_throttle = 0;
      uint16_t rc_rotation = 0;
      uint16_t rc_enable = 0;
      enum { RC_INRANGE = 1 };
      enum { RC_INUSE = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->battery;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->battery);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->current_left;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->current_left);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->current_right;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->current_right);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->pcb_temperature;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->pcb_temperature);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->fan_on;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->fan_on);
      *(outbuffer + offset + 0) = (this->rc >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rc);
      *(outbuffer + offset + 0) = (this->rc_throttle >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc_throttle >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_throttle);
      *(outbuffer + offset + 0) = (this->rc_rotation >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc_rotation >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_rotation);
      *(outbuffer + offset + 0) = (this->rc_enable >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc_enable >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      this->battery = u_.real;
      }
      offset += sizeof(this->battery);
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
      this->current_left = u_.real;
      }
      offset += sizeof(this->current_left);
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
      this->current_right = u_.real;
      }
      offset += sizeof(this->current_right);
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
      this->pcb_temperature = u_.real;
      }
      offset += sizeof(this->pcb_temperature);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fan_on = u_.real;
      }
      offset += sizeof(this->fan_on);
      this->rc =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rc);
      this->rc_throttle =  ((uint16_t) (*(inbuffer + offset)));
      this->rc_throttle |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc_throttle);
      this->rc_rotation =  ((uint16_t) (*(inbuffer + offset)));
      this->rc_rotation |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc_rotation);
      this->rc_enable =  ((uint16_t) (*(inbuffer + offset)));
      this->rc_enable |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc_enable);
     return offset;
    }

    const char * getType(){ return "kingfisher_msgs/Sense"; };
    const char * getMD5(){ return "b0209acddc7f26d2e3dc1338d6c4df94"; };

  };

}
#endif