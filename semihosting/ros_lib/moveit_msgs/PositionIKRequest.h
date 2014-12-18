#ifndef _ROS_moveit_msgs_PositionIKRequest_h
#define _ROS_moveit_msgs_PositionIKRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/Constraints.h"
#include "geometry_msgs/PoseStamped.h"
#include <vector>
#include "ros/duration.h"

namespace moveit_msgs
{

  class PositionIKRequest : public ros::Msg
  {
    public:
      char * group_name = nullptr;
      moveit_msgs::RobotState robot_state;
      moveit_msgs::Constraints constraints;
      bool avoid_collisions = 0;
      char * ik_link_name = nullptr;
      geometry_msgs::PoseStamped pose_stamped;
      std::vector<char*> ik_link_names;
      std::vector<geometry_msgs::PoseStamped> pose_stamped_vector;
      ros::Duration timeout;
      int32_t attempts = 0;

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
      offset += this->robot_state.serialize(outbuffer + offset);
      offset += this->constraints.serialize(outbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->avoid_collisions;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->avoid_collisions);
      {
      uint32_t length_ = strlen( (const char*) this->ik_link_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ik_link_name, length_);
      offset += length_;
      }
      offset += this->pose_stamped.serialize(outbuffer + offset);
      unsigned ik_link_names_length = ik_link_names.size();
      outbuffer[offset++] = (ik_link_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (ik_link_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (ik_link_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (ik_link_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ik_link_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->ik_link_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ik_link_names[i], length_);
      offset += length_;
      }
      }
      unsigned pose_stamped_vector_length = pose_stamped_vector.size();
      outbuffer[offset++] = (pose_stamped_vector_length >> 0) & 0xFF;
      outbuffer[offset++] = (pose_stamped_vector_length >> 8) & 0xFF;
      outbuffer[offset++] = (pose_stamped_vector_length >> 16) & 0xFF;
      outbuffer[offset++] = (pose_stamped_vector_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pose_stamped_vector_length; i++){
      offset += this->pose_stamped_vector[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->attempts;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->attempts);
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
      offset += this->robot_state.deserialize(inbuffer + offset);
      offset += this->constraints.deserialize(inbuffer + offset);
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
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->ik_link_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->pose_stamped.deserialize(inbuffer + offset);
      unsigned ik_link_names_length = inbuffer[offset++];
      ik_link_names_length |= inbuffer[offset++] << 8;
      ik_link_names_length |= inbuffer[offset++] << 16;
      ik_link_names_length |= inbuffer[offset++] << 24;
      ik_link_names.clear();
      ik_link_names.reserve(ik_link_names_length);
      for( unsigned i = 0; i < ik_link_names_length; i++){
      ik_link_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->ik_link_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned pose_stamped_vector_length = inbuffer[offset++];
      pose_stamped_vector_length |= inbuffer[offset++] << 8;
      pose_stamped_vector_length |= inbuffer[offset++] << 16;
      pose_stamped_vector_length |= inbuffer[offset++] << 24;
      pose_stamped_vector.clear();
      pose_stamped_vector.reserve(pose_stamped_vector_length);
      for( unsigned i = 0; i < pose_stamped_vector_length; i++){
      pose_stamped_vector.emplace_back();
      offset += this->pose_stamped_vector.back().deserialize(inbuffer + offset);
      }
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
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
      this->attempts = u_.real;
      }
      offset += sizeof(this->attempts);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PositionIKRequest"; };
    const char * getMD5(){ return "9936dc239c90af180ec94a51596c96f2"; };

  };

}
#endif