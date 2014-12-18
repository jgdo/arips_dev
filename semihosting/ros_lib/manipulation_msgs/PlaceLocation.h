#ifndef _ROS_manipulation_msgs_PlaceLocation_h
#define _ROS_manipulation_msgs_PlaceLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PoseStamped.h"
#include "manipulation_msgs/GripperTranslation.h"
#include <vector>

namespace manipulation_msgs
{

  class PlaceLocation : public ros::Msg
  {
    public:
      char * id = nullptr;
      sensor_msgs::JointState post_place_posture;
      geometry_msgs::PoseStamped place_pose;
      manipulation_msgs::GripperTranslation approach;
      manipulation_msgs::GripperTranslation retreat;
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
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->retreat.serialize(outbuffer + offset);
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
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->retreat.deserialize(inbuffer + offset);
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

    const char * getType(){ return "manipulation_msgs/PlaceLocation"; };
    const char * getMD5(){ return "0139dab9852add0e64233c5fb3b8a25a"; };

  };

}
#endif