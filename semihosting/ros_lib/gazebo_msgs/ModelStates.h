#ifndef _ROS_gazebo_msgs_ModelStates_h
#define _ROS_gazebo_msgs_ModelStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace gazebo_msgs
{

  class ModelStates : public ros::Msg
  {
    public:
      std::vector<char*> name;
      std::vector<geometry_msgs::Pose> pose;
      std::vector<geometry_msgs::Twist> twist;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned name_length = name.size();
      outbuffer[offset++] = (name_length >> 0) & 0xFF;
      outbuffer[offset++] = (name_length >> 8) & 0xFF;
      outbuffer[offset++] = (name_length >> 16) & 0xFF;
      outbuffer[offset++] = (name_length >> 24) & 0xFF;
      for( unsigned i = 0; i < name_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->name[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_);
      offset += length_;
      }
      }
      unsigned pose_length = pose.size();
      outbuffer[offset++] = (pose_length >> 0) & 0xFF;
      outbuffer[offset++] = (pose_length >> 8) & 0xFF;
      outbuffer[offset++] = (pose_length >> 16) & 0xFF;
      outbuffer[offset++] = (pose_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pose_length; i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
      unsigned twist_length = twist.size();
      outbuffer[offset++] = (twist_length >> 0) & 0xFF;
      outbuffer[offset++] = (twist_length >> 8) & 0xFF;
      outbuffer[offset++] = (twist_length >> 16) & 0xFF;
      outbuffer[offset++] = (twist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < twist_length; i++){
      offset += this->twist[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned name_length = inbuffer[offset++];
      name_length |= inbuffer[offset++] << 8;
      name_length |= inbuffer[offset++] << 16;
      name_length |= inbuffer[offset++] << 24;
      name.clear();
      name.reserve(name_length);
      for( unsigned i = 0; i < name_length; i++){
      name.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->name.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned pose_length = inbuffer[offset++];
      pose_length |= inbuffer[offset++] << 8;
      pose_length |= inbuffer[offset++] << 16;
      pose_length |= inbuffer[offset++] << 24;
      pose.clear();
      pose.reserve(pose_length);
      for( unsigned i = 0; i < pose_length; i++){
      pose.emplace_back();
      offset += this->pose.back().deserialize(inbuffer + offset);
      }
      unsigned twist_length = inbuffer[offset++];
      twist_length |= inbuffer[offset++] << 8;
      twist_length |= inbuffer[offset++] << 16;
      twist_length |= inbuffer[offset++] << 24;
      twist.clear();
      twist.reserve(twist_length);
      for( unsigned i = 0; i < twist_length; i++){
      twist.emplace_back();
      offset += this->twist.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ModelStates"; };
    const char * getMD5(){ return "48c080191eb15c41858319b4d8a609c2"; };

  };

}
#endif