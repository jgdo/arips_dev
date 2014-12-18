#ifndef _ROS_moveit_msgs_Constraints_h
#define _ROS_moveit_msgs_Constraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/JointConstraint.h"
#include <vector>
#include "moveit_msgs/PositionConstraint.h"
#include "moveit_msgs/OrientationConstraint.h"
#include "moveit_msgs/VisibilityConstraint.h"

namespace moveit_msgs
{

  class Constraints : public ros::Msg
  {
    public:
      char * name = nullptr;
      std::vector<moveit_msgs::JointConstraint> joint_constraints;
      std::vector<moveit_msgs::PositionConstraint> position_constraints;
      std::vector<moveit_msgs::OrientationConstraint> orientation_constraints;
      std::vector<moveit_msgs::VisibilityConstraint> visibility_constraints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      unsigned joint_constraints_length = joint_constraints.size();
      outbuffer[offset++] = (joint_constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_constraints_length; i++){
      offset += this->joint_constraints[i].serialize(outbuffer + offset);
      }
      unsigned position_constraints_length = position_constraints.size();
      outbuffer[offset++] = (position_constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (position_constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (position_constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (position_constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < position_constraints_length; i++){
      offset += this->position_constraints[i].serialize(outbuffer + offset);
      }
      unsigned orientation_constraints_length = orientation_constraints.size();
      outbuffer[offset++] = (orientation_constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (orientation_constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (orientation_constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (orientation_constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < orientation_constraints_length; i++){
      offset += this->orientation_constraints[i].serialize(outbuffer + offset);
      }
      unsigned visibility_constraints_length = visibility_constraints.size();
      outbuffer[offset++] = (visibility_constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (visibility_constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (visibility_constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (visibility_constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < visibility_constraints_length; i++){
      offset += this->visibility_constraints[i].serialize(outbuffer + offset);
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
      this->name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned joint_constraints_length = inbuffer[offset++];
      joint_constraints_length |= inbuffer[offset++] << 8;
      joint_constraints_length |= inbuffer[offset++] << 16;
      joint_constraints_length |= inbuffer[offset++] << 24;
      joint_constraints.clear();
      joint_constraints.reserve(joint_constraints_length);
      for( unsigned i = 0; i < joint_constraints_length; i++){
      joint_constraints.emplace_back();
      offset += this->joint_constraints.back().deserialize(inbuffer + offset);
      }
      unsigned position_constraints_length = inbuffer[offset++];
      position_constraints_length |= inbuffer[offset++] << 8;
      position_constraints_length |= inbuffer[offset++] << 16;
      position_constraints_length |= inbuffer[offset++] << 24;
      position_constraints.clear();
      position_constraints.reserve(position_constraints_length);
      for( unsigned i = 0; i < position_constraints_length; i++){
      position_constraints.emplace_back();
      offset += this->position_constraints.back().deserialize(inbuffer + offset);
      }
      unsigned orientation_constraints_length = inbuffer[offset++];
      orientation_constraints_length |= inbuffer[offset++] << 8;
      orientation_constraints_length |= inbuffer[offset++] << 16;
      orientation_constraints_length |= inbuffer[offset++] << 24;
      orientation_constraints.clear();
      orientation_constraints.reserve(orientation_constraints_length);
      for( unsigned i = 0; i < orientation_constraints_length; i++){
      orientation_constraints.emplace_back();
      offset += this->orientation_constraints.back().deserialize(inbuffer + offset);
      }
      unsigned visibility_constraints_length = inbuffer[offset++];
      visibility_constraints_length |= inbuffer[offset++] << 8;
      visibility_constraints_length |= inbuffer[offset++] << 16;
      visibility_constraints_length |= inbuffer[offset++] << 24;
      visibility_constraints.clear();
      visibility_constraints.reserve(visibility_constraints_length);
      for( unsigned i = 0; i < visibility_constraints_length; i++){
      visibility_constraints.emplace_back();
      offset += this->visibility_constraints.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/Constraints"; };
    const char * getMD5(){ return "8d5ce8d34ef26c65fb5d43c9e99bf6e0"; };

  };

}
#endif