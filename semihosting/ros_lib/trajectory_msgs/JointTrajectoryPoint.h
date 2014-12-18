#ifndef _ROS_trajectory_msgs_JointTrajectoryPoint_h
#define _ROS_trajectory_msgs_JointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "ros/duration.h"

namespace trajectory_msgs
{

  class JointTrajectoryPoint : public ros::Msg
  {
    public:
      std::vector<float> positions;
      std::vector<float> velocities;
      std::vector<float> accelerations;
      std::vector<float> effort;
      ros::Duration time_from_start;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned positions_length = positions.size();
      outbuffer[offset++] = (positions_length >> 0) & 0xFF;
      outbuffer[offset++] = (positions_length >> 8) & 0xFF;
      outbuffer[offset++] = (positions_length >> 16) & 0xFF;
      outbuffer[offset++] = (positions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < positions_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->positions[i]);
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
      if(this->positions[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned velocities_length = velocities.size();
      outbuffer[offset++] = (velocities_length >> 0) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 8) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 16) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 24) & 0xFF;
      for( unsigned i = 0; i < velocities_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->velocities[i]);
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
      if(this->velocities[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned accelerations_length = accelerations.size();
      outbuffer[offset++] = (accelerations_length >> 0) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 8) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 16) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 24) & 0xFF;
      for( unsigned i = 0; i < accelerations_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->accelerations[i]);
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
      if(this->accelerations[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned positions_length = inbuffer[offset++];
      positions_length |= inbuffer[offset++] << 8;
      positions_length |= inbuffer[offset++] << 16;
      positions_length |= inbuffer[offset++] << 24;
      positions.clear();
      positions.reserve(positions_length);
      for( unsigned i = 0; i < positions_length; i++){
      positions.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->positions.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->positions.back() = -this->positions.back();
      }
      }
      unsigned velocities_length = inbuffer[offset++];
      velocities_length |= inbuffer[offset++] << 8;
      velocities_length |= inbuffer[offset++] << 16;
      velocities_length |= inbuffer[offset++] << 24;
      velocities.clear();
      velocities.reserve(velocities_length);
      for( unsigned i = 0; i < velocities_length; i++){
      velocities.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->velocities.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->velocities.back() = -this->velocities.back();
      }
      }
      unsigned accelerations_length = inbuffer[offset++];
      accelerations_length |= inbuffer[offset++] << 8;
      accelerations_length |= inbuffer[offset++] << 16;
      accelerations_length |= inbuffer[offset++] << 24;
      accelerations.clear();
      accelerations.reserve(accelerations_length);
      for( unsigned i = 0; i < accelerations_length; i++){
      accelerations.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->accelerations.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->accelerations.back() = -this->accelerations.back();
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
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
     return offset;
    }

    const char * getType(){ return "trajectory_msgs/JointTrajectoryPoint"; };
    const char * getMD5(){ return "f3cd1e1c4d320c79d6985c904ae5dcd3"; };

  };

}
#endif