#ifndef _ROS_moveit_msgs_PlaceLocation_h
#define _ROS_moveit_msgs_PlaceLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "geometry_msgs/PoseStamped.h"
#include "moveit_msgs/GripperTranslation.h"
#include <vector>

namespace moveit_msgs
{

  class PlaceLocation : public ros::Msg
  {
    public:
      char * id = nullptr;
      trajectory_msgs::JointTrajectory post_place_posture;
      geometry_msgs::PoseStamped place_pose;
      moveit_msgs::GripperTranslation pre_place_approach;
      moveit_msgs::GripperTranslation post_place_retreat;
      std::vector<char*> allowed_touch_objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_);
      offset += length_;
      }
      offset += this->post_place_posture.serialize(outbuffer + offset);
      offset += this->place_pose.serialize(outbuffer + offset);
      offset += this->pre_place_approach.serialize(outbuffer + offset);
      offset += this->post_place_retreat.serialize(outbuffer + offset);
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
      this->id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->post_place_posture.deserialize(inbuffer + offset);
      offset += this->place_pose.deserialize(inbuffer + offset);
      offset += this->pre_place_approach.deserialize(inbuffer + offset);
      offset += this->post_place_retreat.deserialize(inbuffer + offset);
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
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlaceLocation"; };
    const char * getMD5(){ return "f3dbcaca40fb29ede2af78b3e1831128"; };

  };

}
#endif