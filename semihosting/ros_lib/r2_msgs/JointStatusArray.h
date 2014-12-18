#ifndef _ROS_r2_msgs_JointStatusArray_h
#define _ROS_r2_msgs_JointStatusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "r2_msgs/JointStatus.h"
#include <vector>

namespace r2_msgs
{

  class JointStatusArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<r2_msgs::JointStatus> status;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned status_length = status.size();
      outbuffer[offset++] = (status_length >> 0) & 0xFF;
      outbuffer[offset++] = (status_length >> 8) & 0xFF;
      outbuffer[offset++] = (status_length >> 16) & 0xFF;
      outbuffer[offset++] = (status_length >> 24) & 0xFF;
      for( unsigned i = 0; i < status_length; i++){
      offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned status_length = inbuffer[offset++];
      status_length |= inbuffer[offset++] << 8;
      status_length |= inbuffer[offset++] << 16;
      status_length |= inbuffer[offset++] << 24;
      status.clear();
      status.reserve(status_length);
      for( unsigned i = 0; i < status_length; i++){
      status.emplace_back();
      offset += this->status.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "r2_msgs/JointStatusArray"; };
    const char * getMD5(){ return "2d3e86cb77e5d92be1bdb178712b3811"; };

  };

}
#endif