#ifndef _ROS_trajectory_msgs_MultiDOFJointTrajectory_h
#define _ROS_trajectory_msgs_MultiDOFJointTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "trajectory_msgs/MultiDOFJointTrajectoryPoint.h"

namespace trajectory_msgs
{

  class MultiDOFJointTrajectory : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<char*> joint_names;
      std::vector<trajectory_msgs::MultiDOFJointTrajectoryPoint> points;

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
      unsigned points_length = points.size();
      outbuffer[offset++] = (points_length >> 0) & 0xFF;
      outbuffer[offset++] = (points_length >> 8) & 0xFF;
      outbuffer[offset++] = (points_length >> 16) & 0xFF;
      outbuffer[offset++] = (points_length >> 24) & 0xFF;
      for( unsigned i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
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
      unsigned points_length = inbuffer[offset++];
      points_length |= inbuffer[offset++] << 8;
      points_length |= inbuffer[offset++] << 16;
      points_length |= inbuffer[offset++] << 24;
      points.clear();
      points.reserve(points_length);
      for( unsigned i = 0; i < points_length; i++){
      points.emplace_back();
      offset += this->points.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "trajectory_msgs/MultiDOFJointTrajectory"; };
    const char * getMD5(){ return "ef145a45a5f47b77b7f5cdde4b16c942"; };

  };

}
#endif