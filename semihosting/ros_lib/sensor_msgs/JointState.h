#ifndef _ROS_sensor_msgs_JointState_h
#define _ROS_sensor_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace sensor_msgs
{

  class JointState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<char*> name;
      std::vector<float> position;
      std::vector<float> velocity;
      std::vector<float> effort;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned name_length = name.size();
      outbuffer[offset++] = (name_length >> 0) & 0xFF;
      outbuffer[offset++] = (name_length >> 8) & 0xFF;
      outbuffer[offset++] = (name_length >> 16) & 0xFF;
      outbuffer[offset++] = (name_length >> 24) & 0xFF;
      for( unsigned i = 0; i < name_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->name[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_);
      offset += length_;
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
      unsigned velocity_length = velocity.size();
      outbuffer[offset++] = (velocity_length >> 0) & 0xFF;
      outbuffer[offset++] = (velocity_length >> 8) & 0xFF;
      outbuffer[offset++] = (velocity_length >> 16) & 0xFF;
      outbuffer[offset++] = (velocity_length >> 24) & 0xFF;
      for( unsigned i = 0; i < velocity_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->velocity[i]);
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
      if(this->velocity[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned effort_length = effort.size();
      outbuffer[offset++] = (effort_length >> 0) & 0xFF;
      outbuffer[offset++] = (effort_length >> 8) & 0xFF;
      outbuffer[offset++] = (effort_length >> 16) & 0xFF;
      outbuffer[offset++] = (effort_length >> 24) & 0xFF;
      for( unsigned i = 0; i < effort_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->effort[i]);
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
      if(this->effort[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned name_length = inbuffer[offset++];
      name_length |= inbuffer[offset++] << 8;
      name_length |= inbuffer[offset++] << 16;
      name_length |= inbuffer[offset++] << 24;
      name.clear();
      name.reserve(name_length);
      for( unsigned i = 0; i < name_length; i++){
      name.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->name.back() = (char *)(inbuffer + offset-1);
      offset += length_;
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
      unsigned velocity_length = inbuffer[offset++];
      velocity_length |= inbuffer[offset++] << 8;
      velocity_length |= inbuffer[offset++] << 16;
      velocity_length |= inbuffer[offset++] << 24;
      velocity.clear();
      velocity.reserve(velocity_length);
      for( unsigned i = 0; i < velocity_length; i++){
      velocity.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->velocity.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->velocity.back() = -this->velocity.back();
      }
      }
      unsigned effort_length = inbuffer[offset++];
      effort_length |= inbuffer[offset++] << 8;
      effort_length |= inbuffer[offset++] << 16;
      effort_length |= inbuffer[offset++] << 24;
      effort.clear();
      effort.reserve(effort_length);
      for( unsigned i = 0; i < effort_length; i++){
      effort.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->effort.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->effort.back() = -this->effort.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/JointState"; };
    const char * getMD5(){ return "3066dcd76a6cfaef579bd0f34173e9fd"; };

  };

}
#endif