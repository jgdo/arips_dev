#ifndef _ROS_moveit_msgs_PlaceGoal_h
#define _ROS_moveit_msgs_PlaceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlaceLocation.h"
#include <vector>
#include "moveit_msgs/Constraints.h"
#include "moveit_msgs/PlanningOptions.h"

namespace moveit_msgs
{

  class PlaceGoal : public ros::Msg
  {
    public:
      char * group_name = nullptr;
      char * attached_object_name = nullptr;
      std::vector<moveit_msgs::PlaceLocation> place_locations;
      bool place_eef = 0;
      char * support_surface_name = nullptr;
      bool allow_gripper_support_collision = 0;
      moveit_msgs::Constraints path_constraints;
      char * planner_id = nullptr;
      std::vector<char*> allowed_touch_objects;
      float allowed_planning_time = 0;
      moveit_msgs::PlanningOptions planning_options;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->group_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->attached_object_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->attached_object_name, length_);
      offset += length_;
      }
      unsigned place_locations_length = place_locations.size();
      outbuffer[offset++] = (place_locations_length >> 0) & 0xFF;
      outbuffer[offset++] = (place_locations_length >> 8) & 0xFF;
      outbuffer[offset++] = (place_locations_length >> 16) & 0xFF;
      outbuffer[offset++] = (place_locations_length >> 24) & 0xFF;
      for( unsigned i = 0; i < place_locations_length; i++){
      offset += this->place_locations[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->place_eef;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->place_eef);
      {
      uint32_t length_ = strlen( (const char*) this->support_surface_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->support_surface_name, length_);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->allow_gripper_support_collision;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->allow_gripper_support_collision);
      offset += this->path_constraints.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->planner_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_);
      offset += length_;
      }
      unsigned allowed_touch_objects_length = allowed_touch_objects.size();
      outbuffer[offset++] = (allowed_touch_objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < allowed_touch_objects_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->allowed_touch_objects[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->allowed_touch_objects[i], length_);
      offset += length_;
      }
      }
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
      offset += this->planning_options.serialize(outbuffer + offset);
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
      this->attached_object_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned place_locations_length = inbuffer[offset++];
      place_locations_length |= inbuffer[offset++] << 8;
      place_locations_length |= inbuffer[offset++] << 16;
      place_locations_length |= inbuffer[offset++] << 24;
      place_locations.clear();
      place_locations.reserve(place_locations_length);
      for( unsigned i = 0; i < place_locations_length; i++){
      place_locations.emplace_back();
      offset += this->place_locations.back().deserialize(inbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->place_eef = u_.real;
      }
      offset += sizeof(this->place_eef);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->support_surface_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_gripper_support_collision = u_.real;
      }
      offset += sizeof(this->allow_gripper_support_collision);
      offset += this->path_constraints.deserialize(inbuffer + offset);
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
      unsigned allowed_touch_objects_length = inbuffer[offset++];
      allowed_touch_objects_length |= inbuffer[offset++] << 8;
      allowed_touch_objects_length |= inbuffer[offset++] << 16;
      allowed_touch_objects_length |= inbuffer[offset++] << 24;
      allowed_touch_objects.clear();
      allowed_touch_objects.reserve(allowed_touch_objects_length);
      for( unsigned i = 0; i < allowed_touch_objects_length; i++){
      allowed_touch_objects.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->allowed_touch_objects.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
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
      offset += this->planning_options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlaceGoal"; };
    const char * getMD5(){ return "e3f3e956e536ccd313fd8f23023f0a94"; };

  };

}
#endif