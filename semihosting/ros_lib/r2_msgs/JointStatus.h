#ifndef _ROS_r2_msgs_JointStatus_h
#define _ROS_r2_msgs_JointStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace r2_msgs
{

  class JointStatus : public ros::Msg
  {
    public:
      char * publisher = nullptr;
      char * joint = nullptr;
      uint32_t registerValue = 0;
      bool bridgeEnabled = 0;
      bool motorEnabled = 0;
      bool brakeReleased = 0;
      bool motorPowerDetected = 0;
      bool embeddedMotCom = 0;
      bool jointFaulted = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->publisher);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->publisher, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->joint);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->registerValue >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->registerValue >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->registerValue >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->registerValue >> (8 * 3)) & 0xFF;
      offset += sizeof(this->registerValue);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->bridgeEnabled;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->bridgeEnabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->motorEnabled;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->motorEnabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->brakeReleased;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->brakeReleased);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->motorPowerDetected;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->motorPowerDetected);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->embeddedMotCom;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->embeddedMotCom);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->jointFaulted;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->jointFaulted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->publisher = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->joint = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->registerValue =  ((uint32_t) (*(inbuffer + offset)));
      this->registerValue |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->registerValue |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->registerValue |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->registerValue);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bridgeEnabled = u_.real;
      }
      offset += sizeof(this->bridgeEnabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motorEnabled = u_.real;
      }
      offset += sizeof(this->motorEnabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brakeReleased = u_.real;
      }
      offset += sizeof(this->brakeReleased);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motorPowerDetected = u_.real;
      }
      offset += sizeof(this->motorPowerDetected);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->embeddedMotCom = u_.real;
      }
      offset += sizeof(this->embeddedMotCom);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->jointFaulted = u_.real;
      }
      offset += sizeof(this->jointFaulted);
     return offset;
    }

    const char * getType(){ return "r2_msgs/JointStatus"; };
    const char * getMD5(){ return "03efe3c55d2652ccbab38921d83a5f63"; };

  };

}
#endif