#ifndef _ROS_moveit_msgs_MotionPlanDetailedResponse_h
#define _ROS_moveit_msgs_MotionPlanDetailedResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"
#include <vector>
#include "moveit_msgs/MoveItErrorCodes.h"

namespace moveit_msgs
{

  class MotionPlanDetailedResponse : public ros::Msg
  {
    public:
      moveit_msgs::RobotState trajectory_start;
      char * group_name = nullptr;
      std::vector<moveit_msgs::RobotTrajectory> trajectory;
      std::vector<char*> description;
      std::vector<float> processing_time;
      moveit_msgs::MoveItErrorCodes error_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory_start.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->group_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_);
      offset += length_;
      }
      unsigned trajectory_length = trajectory.size();
      outbuffer[offset++] = (trajectory_length >> 0) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 8) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 16) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 24) & 0xFF;
      for( unsigned i = 0; i < trajectory_length; i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      unsigned description_length = description.size();
      outbuffer[offset++] = (description_length >> 0) & 0xFF;
      outbuffer[offset++] = (description_length >> 8) & 0xFF;
      outbuffer[offset++] = (description_length >> 16) & 0xFF;
      outbuffer[offset++] = (description_length >> 24) & 0xFF;
      for( unsigned i = 0; i < description_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->description[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description[i], length_);
      offset += length_;
      }
      }
      unsigned processing_time_length = processing_time.size();
      outbuffer[offset++] = (processing_time_length >> 0) & 0xFF;
      outbuffer[offset++] = (processing_time_length >> 8) & 0xFF;
      outbuffer[offset++] = (processing_time_length >> 16) & 0xFF;
      outbuffer[offset++] = (processing_time_length >> 24) & 0xFF;
      for( unsigned i = 0; i < processing_time_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->processing_time[i]);
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
      if(this->processing_time[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory_start.deserialize(inbuffer + offset);
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
      unsigned trajectory_length = inbuffer[offset++];
      trajectory_length |= inbuffer[offset++] << 8;
      trajectory_length |= inbuffer[offset++] << 16;
      trajectory_length |= inbuffer[offset++] << 24;
      trajectory.clear();
      trajectory.reserve(trajectory_length);
      for( unsigned i = 0; i < trajectory_length; i++){
      trajectory.emplace_back();
      offset += this->trajectory.back().deserialize(inbuffer + offset);
      }
      unsigned description_length = inbuffer[offset++];
      description_length |= inbuffer[offset++] << 8;
      description_length |= inbuffer[offset++] << 16;
      description_length |= inbuffer[offset++] << 24;
      description.clear();
      description.reserve(description_length);
      for( unsigned i = 0; i < description_length; i++){
      description.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->description.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned processing_time_length = inbuffer[offset++];
      processing_time_length |= inbuffer[offset++] << 8;
      processing_time_length |= inbuffer[offset++] << 16;
      processing_time_length |= inbuffer[offset++] << 24;
      processing_time.clear();
      processing_time.reserve(processing_time_length);
      for( unsigned i = 0; i < processing_time_length; i++){
      processing_time.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->processing_time.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->processing_time.back() = -this->processing_time.back();
      }
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionPlanDetailedResponse"; };
    const char * getMD5(){ return "7b84c374bb2e37bdc0eba664f7636a8f"; };

  };

}
#endif