#ifndef _ROS_SERVICE_DiscoverMasters_h
#define _ROS_SERVICE_DiscoverMasters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/ROSMaster.h"
#include <vector>

namespace multimaster_msgs_fkie
{

static const char DISCOVERMASTERS[] = "multimaster_msgs_fkie/DiscoverMasters";

  class DiscoverMastersRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return DISCOVERMASTERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DiscoverMastersResponse : public ros::Msg
  {
    public:
      std::vector<multimaster_msgs_fkie::ROSMaster> masters;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned masters_length = masters.size();
      outbuffer[offset++] = (masters_length >> 0) & 0xFF;
      outbuffer[offset++] = (masters_length >> 8) & 0xFF;
      outbuffer[offset++] = (masters_length >> 16) & 0xFF;
      outbuffer[offset++] = (masters_length >> 24) & 0xFF;
      for( unsigned i = 0; i < masters_length; i++){
      offset += this->masters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned masters_length = inbuffer[offset++];
      masters_length |= inbuffer[offset++] << 8;
      masters_length |= inbuffer[offset++] << 16;
      masters_length |= inbuffer[offset++] << 24;
      masters.clear();
      masters.reserve(masters_length);
      for( unsigned i = 0; i < masters_length; i++){
      masters.emplace_back();
      offset += this->masters.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return DISCOVERMASTERS; };
    const char * getMD5(){ return "bc7525cc24dd3b880f044a2cdfb95aad"; };

  };

  class DiscoverMasters {
    public:
    typedef DiscoverMastersRequest Request;
    typedef DiscoverMastersResponse Response;
  };

}
#endif
