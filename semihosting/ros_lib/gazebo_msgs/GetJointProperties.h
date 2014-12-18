#ifndef _ROS_SERVICE_GetJointProperties_h
#define _ROS_SERVICE_GetJointProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace gazebo_msgs
{

static const char GETJOINTPROPERTIES[] = "gazebo_msgs/GetJointProperties";

  class GetJointPropertiesRequest : public ros::Msg
  {
    public:
      char * joint_name = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->joint_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_);
      offset += length_;
      }
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
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETJOINTPROPERTIES; };
    const char * getMD5(){ return "0be1351618e1dc030eb7959d9a4902de"; };

  };

  class GetJointPropertiesResponse : public ros::Msg
  {
    public:
      uint8_t type = 0;
      std::vector<float> damping;
      std::vector<float> position;
      std::vector<float> rate;
      bool success = 0;
      char * status_message = nullptr;
      enum { REVOLUTE =  0                 };
      enum { CONTINUOUS =  1                 };
      enum { PRISMATIC =  2                 };
      enum { FIXED =  3                 };
      enum { BALL =  4                 };
      enum { UNIVERSAL =  5                 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      unsigned damping_length = damping.size();
      outbuffer[offset++] = (damping_length >> 0) & 0xFF;
      outbuffer[offset++] = (damping_length >> 8) & 0xFF;
      outbuffer[offset++] = (damping_length >> 16) & 0xFF;
      outbuffer[offset++] = (damping_length >> 24) & 0xFF;
      for( unsigned i = 0; i < damping_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->damping[i]);
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
      if(this->damping[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned position_length = position.size();
      outbuffer[offset++] = (position_length >> 0) & 0xFF;
      outbuffer[offset++] = (position_length >> 8) & 0xFF;
      outbuffer[offset++] = (position_length >> 16) & 0xFF;
      outbuffer[offset++] = (position_length >> 24) & 0xFF;
      for( unsigned i = 0; i < position_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->position[i]);
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
      if(this->position[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned rate_length = rate.size();
      outbuffer[offset++] = (rate_length >> 0) & 0xFF;
      outbuffer[offset++] = (rate_length >> 8) & 0xFF;
      outbuffer[offset++] = (rate_length >> 16) & 0xFF;
      outbuffer[offset++] = (rate_length >> 24) & 0xFF;
      for( unsigned i = 0; i < rate_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->rate[i]);
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
      if(this->rate[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      unsigned damping_length = inbuffer[offset++];
      damping_length |= inbuffer[offset++] << 8;
      damping_length |= inbuffer[offset++] << 16;
      damping_length |= inbuffer[offset++] << 24;
      damping.clear();
      damping.reserve(damping_length);
      for( unsigned i = 0; i < damping_length; i++){
      damping.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->damping.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->damping.back() = -this->damping.back();
      }
      }
      unsigned position_length = inbuffer[offset++];
      position_length |= inbuffer[offset++] << 8;
      position_length |= inbuffer[offset++] << 16;
      position_length |= inbuffer[offset++] << 24;
      position.clear();
      position.reserve(position_length);
      for( unsigned i = 0; i < position_length; i++){
      position.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->position.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->position.back() = -this->position.back();
      }
      }
      unsigned rate_length = inbuffer[offset++];
      rate_length |= inbuffer[offset++] << 8;
      rate_length |= inbuffer[offset++] << 16;
      rate_length |= inbuffer[offset++] << 24;
      rate.clear();
      rate.reserve(rate_length);
      for( unsigned i = 0; i < rate_length; i++){
      rate.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->rate.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->rate.back() = -this->rate.back();
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_.real;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETJOINTPROPERTIES; };
    const char * getMD5(){ return "cd7b30a39faa372283dc94c5f6457f82"; };

  };

  class GetJointProperties {
    public:
    typedef GetJointPropertiesRequest Request;
    typedef GetJointPropertiesResponse Response;
  };

}
#endif
