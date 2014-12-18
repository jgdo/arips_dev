#ifndef _ROS_moveit_msgs_MotionPlanRequest_h
#define _ROS_moveit_msgs_MotionPlanRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/WorkspaceParameters.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/Constraints.h"
#include <vector>
#include "moveit_msgs/TrajectoryConstraints.h"

namespace moveit_msgs
{

  class MotionPlanRequest : public ros::Msg
  {
    public:
      moveit_msgs::WorkspaceParameters workspace_parameters;
      moveit_msgs::RobotState start_state;
      std::vector<moveit_msgs::Constraints> goal_constraints;
      moveit_msgs::Constraints path_constraints;
      moveit_msgs::TrajectoryConstraints trajectory_constraints;
      char * planner_id = nullptr;
      char * group_name = nullptr;
      int32_t num_planning_attempts = 0;
      float allowed_planning_time = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->workspace_parameters.serialize(outbuffer + offset);
      offset += this->start_state.serialize(outbuffer + offset);
      unsigned goal_constraints_length = goal_constraints.size();
      outbuffer[offset++] = (goal_constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (goal_constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (goal_constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (goal_constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < goal_constraints_length; i++){
      offset += this->goal_constraints[i].serialize(outbuffer + offset);
      }
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->trajectory_constraints.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->planner_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->group_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->num_planning_attempts;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->num_planning_attempts);
      {
      int32_t * val_= (int32_t *) &(this->allowed_planning_time);
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
      if(this->allowed_planning_time < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->workspace_parameters.deserialize(inbuffer + offset);
      offset += this->start_state.deserialize(inbuffer + offset);
      unsigned goal_constraints_length = inbuffer[offset++];
      goal_constraints_length |= inbuffer[offset++] << 8;
      goal_constraints_length |= inbuffer[offset++] << 16;
      goal_constraints_length |= inbuffer[offset++] << 24;
      goal_constraints.clear();
      goal_constraints.reserve(goal_constraints_length);
      for( unsigned i = 0; i < goal_constraints_length; i++){
      goal_constraints.emplace_back();
      offset += this->goal_constraints.back().deserialize(inbuffer + offset);
      }
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->trajectory_constraints.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->planner_id = (char *)(inbuffer + offset-1);
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
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_planning_attempts = u_.real;
      }
      offset += sizeof(this->num_planning_attempts);
      {
      uint32_t * val_ = (uint32_t*) &(this->allowed_planning_time);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->allowed_planning_time = -this->allowed_planning_time;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionPlanRequest"; };
    const char * getMD5(){ return "7cd790e04c3a55f6742ec387a72a02d6"; };

  };

}
#endif