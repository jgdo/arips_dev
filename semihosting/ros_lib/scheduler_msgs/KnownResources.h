#ifndef _ROS_scheduler_msgs_KnownResources_h
#define _ROS_scheduler_msgs_KnownResources_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "scheduler_msgs/CurrentStatus.h"
#include <vector>

namespace scheduler_msgs
{

  class KnownResources : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<scheduler_msgs::CurrentStatus> resources;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned resources_length = resources.size();
      outbuffer[offset++] = (resources_length >> 0) & 0xFF;
      outbuffer[offset++] = (resources_length >> 8) & 0xFF;
      outbuffer[offset++] = (resources_length >> 16) & 0xFF;
      outbuffer[offset++] = (resources_length >> 24) & 0xFF;
      for( unsigned i = 0; i < resources_length; i++){
      offset += this->resources[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned resources_length = inbuffer[offset++];
      resources_length |= inbuffer[offset++] << 8;
      resources_length |= inbuffer[offset++] << 16;
      resources_length |= inbuffer[offset++] << 24;
      resources.clear();
      resources.reserve(resources_length);
      for( unsigned i = 0; i < resources_length; i++){
      resources.emplace_back();
      offset += this->resources.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/KnownResources"; };
    const char * getMD5(){ return "87a28a11a352f2b3315663c14ec4547c"; };

  };

}
#endif