#ifndef _ROS_sensor_msgs_MultiDOFJointState_h
#define _ROS_sensor_msgs_MultiDOFJointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Wrench.h"

namespace sensor_msgs
{

  class MultiDOFJointState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<char*> joint_names;
      std::vector<geometry_msgs::Transform> transforms;
      std::vector<geometry_msgs::Twist> twist;
      std::vector<geometry_msgs::Wrench> wrench;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      unsigned transforms_length = transforms.size();
      outbuffer[offset++] = (transforms_length >> 0) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 8) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 16) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 24) & 0xFF;
      for( unsigned i = 0; i < transforms_length; i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
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
      unsigned transforms_length = inbuffer[offset++];
      transforms_length |= inbuffer[offset++] << 8;
      transforms_length |= inbuffer[offset++] << 16;
      transforms_length |= inbuffer[offset++] << 24;
      transforms.clear();
      transforms.reserve(transforms_length);
      for( unsigned i = 0; i < transforms_length; i++){
      transforms.emplace_back();
      offset += this->transforms.back().deserialize(inbuffer + offset);
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

    const char * getType(){ return "sensor_msgs/MultiDOFJointState"; };
    const char * getMD5(){ return "690f272f0640d2631c305eeb8301e59d"; };

  };

}
#endif