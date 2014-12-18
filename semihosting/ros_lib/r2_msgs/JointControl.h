#ifndef _ROS_r2_msgs_JointControl_h
#define _ROS_r2_msgs_JointControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace r2_msgs
{

  class JointControl : public ros::Msg
  {
    public:
      char * publisher = nullptr;
      float timeStamp = 0;
      char * joint = nullptr;
      uint32_t registerValue = 0;
      bool enableBridge = 0;
      bool enableMotor = 0;
      bool releaseBrake = 0;
      bool embeddedMotCom = 0;
      uint16_t controlMode = 0;
      bool clearFaults = 0;

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
      int32_t * val_= (int32_t *) &(this->timeStamp);
      int32_t exp_ = (((*val_)>>23)&255);
      if(exp_ != 0)
        exp_ += 1023-127;
      int32_t sig_ = *val_;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_<<5) & 0xff;
      *(outbuffer + offset++) = (sig_>>3) & 0xff;
      *(outbuffer + offset++) = (sig_>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_<<4) & 0xF0) | ((sig_>>19)&0x0F);
      *(outbuffer + offset++) = (exp_>>4) & 0x7F;
      if(this->timeStamp < 0) *(outbuffer + offset -1) |= 0x80;
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
      u_.real = this->enableBridge;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->enableBridge);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->enableMotor;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->enableMotor);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->releaseBrake;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->releaseBrake);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->embeddedMotCom;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->embeddedMotCom);
      *(outbuffer + offset + 0) = (this->controlMode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->controlMode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->controlMode);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->clearFaults;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->clearFaults);
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
      uint32_t * val_ = (uint32_t*) &(this->timeStamp);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->timeStamp = -this->timeStamp;
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
      this->enableBridge = u_.real;
      }
      offset += sizeof(this->enableBridge);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enableMotor = u_.real;
      }
      offset += sizeof(this->enableMotor);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->releaseBrake = u_.real;
      }
      offset += sizeof(this->releaseBrake);
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
      this->controlMode =  ((uint16_t) (*(inbuffer + offset)));
      this->controlMode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->controlMode);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clearFaults = u_.real;
      }
      offset += sizeof(this->clearFaults);
     return offset;
    }

    const char * getType(){ return "r2_msgs/JointControl"; };
    const char * getMD5(){ return "e38c02f4ffdedb57646a4576b7e0ccf6"; };

  };

}
#endif