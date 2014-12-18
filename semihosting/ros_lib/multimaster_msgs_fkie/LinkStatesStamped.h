#ifndef _ROS_multimaster_msgs_fkie_LinkStatesStamped_h
#define _ROS_multimaster_msgs_fkie_LinkStatesStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "multimaster_msgs_fkie/LinkState.h"
#include <vector>

namespace multimaster_msgs_fkie
{

  class LinkStatesStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<multimaster_msgs_fkie::LinkState> links;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned links_length = links.size();
      outbuffer[offset++] = (links_length >> 0) & 0xFF;
      outbuffer[offset++] = (links_length >> 8) & 0xFF;
      outbuffer[offset++] = (links_length >> 16) & 0xFF;
      outbuffer[offset++] = (links_length >> 24) & 0xFF;
      for( unsigned i = 0; i < links_length; i++){
      offset += this->links[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned links_length = inbuffer[offset++];
      links_length |= inbuffer[offset++] << 8;
      links_length |= inbuffer[offset++] << 16;
      links_length |= inbuffer[offset++] << 24;
      links.clear();
      links.reserve(links_length);
      for( unsigned i = 0; i < links_length; i++){
      links.emplace_back();
      offset += this->links.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/LinkStatesStamped"; };
    const char * getMD5(){ return "b7c41a46488485ec6593097b0cabe904"; };

  };

}
#endif