#ifndef _ROS_pr2_msgs_LaserTrajCmd_h
#define _ROS_pr2_msgs_LaserTrajCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "ros/duration.h"

namespace pr2_msgs
{

  class LaserTrajCmd : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * profile = nullptr;
      std::vector<float> position;
      std::vector<ros::Duration> time_from_start;
      float max_velocity = 0;
      float max_acceleration = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->profile);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->profile, length_);
      offset += length_;
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
      unsigned time_from_start_length = time_from_start.size();
      outbuffer[offset++] = (time_from_start_length >> 0) & 0xFF;
      outbuffer[offset++] = (time_from_start_length >> 8) & 0xFF;
      outbuffer[offset++] = (time_from_start_length >> 16) & 0xFF;
      outbuffer[offset++] = (time_from_start_length >> 24) & 0xFF;
      for( unsigned i = 0; i < time_from_start_length; i++){
      *(outbuffer + offset + 0) = (this->time_from_start[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start[i].sec);
      *(outbuffer + offset + 0) = (this->time_from_start[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start[i].nsec);
      }
      {
      int32_t * val_= (int32_t *) &(this->max_velocity);
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
      if(this->max_velocity < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->max_acceleration);
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
      if(this->max_acceleration < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->profile = (char *)(inbuffer + offset-1);
      offset += length_;
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
      unsigned time_from_start_length = inbuffer[offset++];
      time_from_start_length |= inbuffer[offset++] << 8;
      time_from_start_length |= inbuffer[offset++] << 16;
      time_from_start_length |= inbuffer[offset++] << 24;
      time_from_start.clear();
      time_from_start.reserve(time_from_start_length);
      for( unsigned i = 0; i < time_from_start_length; i++){
      time_from_start.emplace_back();
      this->time_from_start.back().sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.back().sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.back().sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.back().sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.back().sec);
      this->time_from_start.back().nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.back().nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.back().nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.back().nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.back().nsec);
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->max_velocity);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_velocity = -this->max_velocity;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->max_acceleration);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_acceleration = -this->max_acceleration;
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/LaserTrajCmd"; };
    const char * getMD5(){ return "68a1665e9079049dce55a0384cb2e9b5"; };

  };

}
#endif