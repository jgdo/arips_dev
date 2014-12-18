#ifndef _ROS_SERVICE_QueryTrajectoryState_h
#define _ROS_SERVICE_QueryTrajectoryState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "ros/time.h"

namespace control_msgs
{

static const char QUERYTRAJECTORYSTATE[] = "control_msgs/QueryTrajectoryState";

  class QueryTrajectoryStateRequest : public ros::Msg
  {
    public:
      ros::Time time;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.sec);
      *(outbuffer + offset + 0) = (this->time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.sec);
      this->time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.nsec);
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "556a4fb76023a469987922359d08a844"; };

  };

  class QueryTrajectoryStateResponse : public ros::Msg
  {
    public:
      std::vector<char*> name;
      std::vector<float> position;
      std::vector<float> velocity;
      std::vector<float> acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      unsigned acceleration_length = acceleration.size();
      outbuffer[offset++] = (acceleration_length >> 0) & 0xFF;
      outbuffer[offset++] = (acceleration_length >> 8) & 0xFF;
      outbuffer[offset++] = (acceleration_length >> 16) & 0xFF;
      outbuffer[offset++] = (acceleration_length >> 24) & 0xFF;
      for( unsigned i = 0; i < acceleration_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->acceleration[i]);
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
      if(this->acceleration[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      unsigned acceleration_length = inbuffer[offset++];
      acceleration_length |= inbuffer[offset++] << 8;
      acceleration_length |= inbuffer[offset++] << 16;
      acceleration_length |= inbuffer[offset++] << 24;
      acceleration.clear();
      acceleration.reserve(acceleration_length);
      for( unsigned i = 0; i < acceleration_length; i++){
      acceleration.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->acceleration.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->acceleration.back() = -this->acceleration.back();
      }
      }
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "1f1a6554ad060f44d013e71868403c1a"; };

  };

  class QueryTrajectoryState {
    public:
    typedef QueryTrajectoryStateRequest Request;
    typedef QueryTrajectoryStateResponse Response;
  };

}
#endif
