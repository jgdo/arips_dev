#ifndef _ROS_nav_msgs_Path_h
#define _ROS_nav_msgs_Path_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include <vector>

namespace nav_msgs
{

  class Path : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<geometry_msgs::PoseStamped> poses;

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

    const char * getType(){ return "nav_msgs/Path"; };
    const char * getMD5(){ return "6227e2b7e9cce15051f669a5e197bbf7"; };

  };

}
#endif