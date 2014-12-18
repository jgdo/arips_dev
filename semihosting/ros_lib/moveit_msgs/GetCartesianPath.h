#ifndef _ROS_SERVICE_GetCartesianPath_h
#define _ROS_SERVICE_GetCartesianPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "geometry_msgs/Pose.h"
#include <vector>
#include "moveit_msgs/Constraints.h"

namespace moveit_msgs
{

static const char GETCARTESIANPATH[] = "moveit_msgs/GetCartesianPath";

  class GetCartesianPathRequest : public ros::Msg
  {
    public:
      std_msgs::Header header;
      moveit_msgs::RobotState start_state;
      char * group_name = nullptr;
      char * link_name = nullptr;
      std::vector<geometry_msgs::Pose> waypoints;
      float max_step = 0;
      float jump_threshold = 0;
      bool avoid_collisions = 0;
      moveit_msgs::Constraints path_constraints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->start_state.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->group_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->link_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_);
      offset += length_;
      }
      unsigned waypoints_length = waypoints.size();
      outbuffer[offset++] = (waypoints_length >> 0) & 0xFF;
      outbuffer[offset++] = (waypoints_length >> 8) & 0xFF;
      outbuffer[offset++] = (waypoints_length >> 16) & 0xFF;
      outbuffer[offset++] = (waypoints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < waypoints_length; i++){
      offset += this->waypoints[i].serialize(outbuffer + offset);
      }
      {
      int32_t * val_= (int32_t *) &(this->max_step);
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
      if(this->max_step < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->jump_threshold);
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
      if(this->jump_threshold < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->avoid_collisions;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->avoid_collisions);
      offset += this->path_constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->start_state.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
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
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned waypoints_length = inbuffer[offset++];
      waypoints_length |= inbuffer[offset++] << 8;
      waypoints_length |= inbuffer[offset++] << 16;
      waypoints_length |= inbuffer[offset++] << 24;
      waypoints.clear();
      waypoints.reserve(waypoints_length);
      for( unsigned i = 0; i < waypoints_length; i++){
      waypoints.emplace_back();
      offset += this->waypoints.back().deserialize(inbuffer + offset);
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->max_step);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_step = -this->max_step;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->jump_threshold);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->jump_threshold = -this->jump_threshold;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->avoid_collisions = u_.real;
      }
      offset += sizeof(this->avoid_collisions);
      offset += this->path_constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCARTESIANPATH; };
    const char * getMD5(){ return "b37c16ad7ed838d811a270a8054276b6"; };

  };

  class GetCartesianPathResponse : public ros::Msg
  {
    public:
      moveit_msgs::RobotState start_state;
      moveit_msgs::RobotTrajectory solution;
      float fraction = 0;
      moveit_msgs::MoveItErrorCodes error_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start_state.serialize(outbuffer + offset);
      offset += this->solution.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->fraction);
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
      if(this->fraction < 0) *(outbuffer + offset -1) |= 0x80;
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start_state.deserialize(inbuffer + offset);
      offset += this->solution.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->fraction);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->fraction = -this->fraction;
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCARTESIANPATH; };
    const char * getMD5(){ return "45414110461a45eb0e273e013924ce59"; };

  };

  class GetCartesianPath {
    public:
    typedef GetCartesianPathRequest Request;
    typedef GetCartesianPathResponse Response;
  };

}
#endif
