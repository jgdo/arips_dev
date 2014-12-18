#ifndef _ROS_geometry_msgs_PoseArray_h
#define _ROS_geometry_msgs_PoseArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include <vector>

namespace geometry_msgs
{

  class PoseArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<geometry_msgs::Pose> poses;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned poses_length = poses.size();
      outbuffer[offset++] = (poses_length >> 0) & 0xFF;
      outbuffer[offset++] = (poses_length >> 8) & 0xFF;
      outbuffer[offset++] = (poses_length >> 16) & 0xFF;
      outbuffer[offset++] = (poses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned poses_length = inbuffer[offset++];
      poses_length |= inbuffer[offset++] << 8;
      poses_length |= inbuffer[offset++] << 16;
      poses_length |= inbuffer[offset++] << 24;
      poses.clear();
      poses.reserve(poses_length);
      for( unsigned i = 0; i < poses_length; i++){
      poses.emplace_back();
      offset += this->poses.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/PoseArray"; };
    const char * getMD5(){ return "916c28c5764443f268b296bb671b9d97"; };

  };

}
#endif