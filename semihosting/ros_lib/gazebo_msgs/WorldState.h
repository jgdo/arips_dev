#ifndef _ROS_gazebo_msgs_WorldState_h
#define _ROS_gazebo_msgs_WorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Wrench.h"

namespace gazebo_msgs
{

  class WorldState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<char*> name;
      std::vector<geometry_msgs::Pose> pose;
      std::vector<geometry_msgs::Twist> twist;
      std::vector<geometry_msgs::Wrench> wrench;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      unsigned wrench_length = wrench.size();
      outbuffer[offset++] = (wrench_length >> 0) & 0xFF;
      outbuffer[offset++] = (wrench_length >> 8) & 0xFF;
      outbuffer[offset++] = (wrench_length >> 16) & 0xFF;
      outbuffer[offset++] = (wrench_length >> 24) & 0xFF;
      for( unsigned i = 0; i < wrench_length; i++){
      offset += this->wrench[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      unsigned wrench_length = inbuffer[offset++];
      wrench_length |= inbuffer[offset++] << 8;
      wrench_length |= inbuffer[offset++] << 16;
      wrench_length |= inbuffer[offset++] << 24;
      wrench.clear();
      wrench.reserve(wrench_length);
      for( unsigned i = 0; i < wrench_length; i++){
      wrench.emplace_back();
      offset += this->wrench.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/WorldState"; };
    const char * getMD5(){ return "de1a9de3ab7ba97ac0e9ec01a4eb481e"; };

  };

}
#endif