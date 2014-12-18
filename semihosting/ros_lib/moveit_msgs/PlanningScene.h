#ifndef _ROS_moveit_msgs_PlanningScene_h
#define _ROS_moveit_msgs_PlanningScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "geometry_msgs/TransformStamped.h"
#include <vector>
#include "moveit_msgs/AllowedCollisionMatrix.h"
#include "moveit_msgs/LinkPadding.h"
#include "moveit_msgs/LinkScale.h"
#include "moveit_msgs/ObjectColor.h"
#include "moveit_msgs/PlanningSceneWorld.h"

namespace moveit_msgs
{

  class PlanningScene : public ros::Msg
  {
    public:
      char * name = nullptr;
      moveit_msgs::RobotState robot_state;
      char * robot_model_name = nullptr;
      std::vector<geometry_msgs::TransformStamped> fixed_frame_transforms;
      moveit_msgs::AllowedCollisionMatrix allowed_collision_matrix;
      std::vector<moveit_msgs::LinkPadding> link_padding;
      std::vector<moveit_msgs::LinkScale> link_scale;
      std::vector<moveit_msgs::ObjectColor> object_colors;
      moveit_msgs::PlanningSceneWorld world;
      bool is_diff = 0;

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
      offset += this->robot_state.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->robot_model_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_model_name, length_);
      offset += length_;
      }
      unsigned fixed_frame_transforms_length = fixed_frame_transforms.size();
      outbuffer[offset++] = (fixed_frame_transforms_length >> 0) & 0xFF;
      outbuffer[offset++] = (fixed_frame_transforms_length >> 8) & 0xFF;
      outbuffer[offset++] = (fixed_frame_transforms_length >> 16) & 0xFF;
      outbuffer[offset++] = (fixed_frame_transforms_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->fixed_frame_transforms[i].serialize(outbuffer + offset);
      }
      offset += this->allowed_collision_matrix.serialize(outbuffer + offset);
      unsigned link_padding_length = link_padding.size();
      outbuffer[offset++] = (link_padding_length >> 0) & 0xFF;
      outbuffer[offset++] = (link_padding_length >> 8) & 0xFF;
      outbuffer[offset++] = (link_padding_length >> 16) & 0xFF;
      outbuffer[offset++] = (link_padding_length >> 24) & 0xFF;
      for( unsigned i = 0; i < link_padding_length; i++){
      offset += this->link_padding[i].serialize(outbuffer + offset);
      }
      unsigned link_scale_length = link_scale.size();
      outbuffer[offset++] = (link_scale_length >> 0) & 0xFF;
      outbuffer[offset++] = (link_scale_length >> 8) & 0xFF;
      outbuffer[offset++] = (link_scale_length >> 16) & 0xFF;
      outbuffer[offset++] = (link_scale_length >> 24) & 0xFF;
      for( unsigned i = 0; i < link_scale_length; i++){
      offset += this->link_scale[i].serialize(outbuffer + offset);
      }
      unsigned object_colors_length = object_colors.size();
      outbuffer[offset++] = (object_colors_length >> 0) & 0xFF;
      outbuffer[offset++] = (object_colors_length >> 8) & 0xFF;
      outbuffer[offset++] = (object_colors_length >> 16) & 0xFF;
      outbuffer[offset++] = (object_colors_length >> 24) & 0xFF;
      for( unsigned i = 0; i < object_colors_length; i++){
      offset += this->object_colors[i].serialize(outbuffer + offset);
      }
      offset += this->world.serialize(outbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_diff;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_diff);
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
      offset += this->robot_state.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->robot_model_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned fixed_frame_transforms_length = inbuffer[offset++];
      fixed_frame_transforms_length |= inbuffer[offset++] << 8;
      fixed_frame_transforms_length |= inbuffer[offset++] << 16;
      fixed_frame_transforms_length |= inbuffer[offset++] << 24;
      fixed_frame_transforms.clear();
      fixed_frame_transforms.reserve(fixed_frame_transforms_length);
      for( unsigned i = 0; i < fixed_frame_transforms_length; i++){
      fixed_frame_transforms.emplace_back();
      offset += this->fixed_frame_transforms.back().deserialize(inbuffer + offset);
      }
      offset += this->allowed_collision_matrix.deserialize(inbuffer + offset);
      unsigned link_padding_length = inbuffer[offset++];
      link_padding_length |= inbuffer[offset++] << 8;
      link_padding_length |= inbuffer[offset++] << 16;
      link_padding_length |= inbuffer[offset++] << 24;
      link_padding.clear();
      link_padding.reserve(link_padding_length);
      for( unsigned i = 0; i < link_padding_length; i++){
      link_padding.emplace_back();
      offset += this->link_padding.back().deserialize(inbuffer + offset);
      }
      unsigned link_scale_length = inbuffer[offset++];
      link_scale_length |= inbuffer[offset++] << 8;
      link_scale_length |= inbuffer[offset++] << 16;
      link_scale_length |= inbuffer[offset++] << 24;
      link_scale.clear();
      link_scale.reserve(link_scale_length);
      for( unsigned i = 0; i < link_scale_length; i++){
      link_scale.emplace_back();
      offset += this->link_scale.back().deserialize(inbuffer + offset);
      }
      unsigned object_colors_length = inbuffer[offset++];
      object_colors_length |= inbuffer[offset++] << 8;
      object_colors_length |= inbuffer[offset++] << 16;
      object_colors_length |= inbuffer[offset++] << 24;
      object_colors.clear();
      object_colors.reserve(object_colors_length);
      for( unsigned i = 0; i < object_colors_length; i++){
      object_colors.emplace_back();
      offset += this->object_colors.back().deserialize(inbuffer + offset);
      }
      offset += this->world.deserialize(inbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_diff = u_.real;
      }
      offset += sizeof(this->is_diff);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningScene"; };
    const char * getMD5(){ return "89aac6d20db967ba716cba5a86b1b9d5"; };

  };

}
#endif