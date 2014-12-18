#ifndef _ROS_pr2_msgs_PowerState_h
#define _ROS_pr2_msgs_PowerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace pr2_msgs
{

  class PowerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float power_consumption = 0;
      ros::Duration time_remaining;
      char * prediction_method = nullptr;
      int8_t relative_capacity = 0;
      int8_t AC_present = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->power_consumption);
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
      if(this->power_consumption < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset + 0) = (this->time_remaining.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_remaining.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_remaining.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_remaining.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_remaining.sec);
      *(outbuffer + offset + 0) = (this->time_remaining.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_remaining.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_remaining.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_remaining.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_remaining.nsec);
      {
      uint32_t length_ = strlen( (const char*) this->prediction_method);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->prediction_method, length_);
      offset += length_;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->relative_capacity;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->relative_capacity);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->AC_present;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->AC_present);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->power_consumption);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->power_consumption = -this->power_consumption;
      }
      this->time_remaining.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_remaining.sec);
      this->time_remaining.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_remaining.nsec);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->prediction_method = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->relative_capacity = u_.real;
      }
      offset += sizeof(this->relative_capacity);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->AC_present = u_.real;
      }
      offset += sizeof(this->AC_present);
     return offset;
    }

    const char * getType(){ return "pr2_msgs/PowerState"; };
    const char * getMD5(){ return "e6fa46a387cad0b7a80959a21587a6c9"; };

  };

}
#endif