#ifndef _ROS_moveit_msgs_KinematicSolverInfo_h
#define _ROS_moveit_msgs_KinematicSolverInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "moveit_msgs/JointLimits.h"

namespace moveit_msgs
{

  class KinematicSolverInfo : public ros::Msg
  {
    public:
      std::vector<char*> joint_names;
      std::vector<moveit_msgs::JointLimits> limits;
      std::vector<char*> link_names;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned joint_names_length = joint_names.size();
      outbuffer[offset++] = (joint_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->joint_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_);
      offset += length_;
      }
      }
      unsigned limits_length = limits.size();
      outbuffer[offset++] = (limits_length >> 0) & 0xFF;
      outbuffer[offset++] = (limits_length >> 8) & 0xFF;
      outbuffer[offset++] = (limits_length >> 16) & 0xFF;
      outbuffer[offset++] = (limits_length >> 24) & 0xFF;
      for( unsigned i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      unsigned link_names_length = link_names.size();
      outbuffer[offset++] = (link_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (link_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (link_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (link_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < link_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->link_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned joint_names_length = inbuffer[offset++];
      joint_names_length |= inbuffer[offset++] << 8;
      joint_names_length |= inbuffer[offset++] << 16;
      joint_names_length |= inbuffer[offset++] << 24;
      joint_names.clear();
      joint_names.reserve(joint_names_length);
      for( unsigned i = 0; i < joint_names_length; i++){
      joint_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->joint_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned limits_length = inbuffer[offset++];
      limits_length |= inbuffer[offset++] << 8;
      limits_length |= inbuffer[offset++] << 16;
      limits_length |= inbuffer[offset++] << 24;
      limits.clear();
      limits.reserve(limits_length);
      for( unsigned i = 0; i < limits_length; i++){
      limits.emplace_back();
      offset += this->limits.back().deserialize(inbuffer + offset);
      }
      unsigned link_names_length = inbuffer[offset++];
      link_names_length |= inbuffer[offset++] << 8;
      link_names_length |= inbuffer[offset++] << 16;
      link_names_length |= inbuffer[offset++] << 24;
      link_names.clear();
      link_names.reserve(link_names_length);
      for( unsigned i = 0; i < link_names_length; i++){
      link_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->link_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/KinematicSolverInfo"; };
    const char * getMD5(){ return "cc048557c0f9795c392dd80f8bb00489"; };

  };

}
#endif