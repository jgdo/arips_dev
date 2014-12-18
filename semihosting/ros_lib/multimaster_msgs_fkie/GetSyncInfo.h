#ifndef _ROS_SERVICE_GetSyncInfo_h
#define _ROS_SERVICE_GetSyncInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "multimaster_msgs_fkie/SyncMasterInfo.h"

namespace multimaster_msgs_fkie
{

static const char GETSYNCINFO[] = "multimaster_msgs_fkie/GetSyncInfo";

  class GetSyncInfoRequest : public ros::Msg
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

    const char * getType(){ return GETSYNCINFO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetSyncInfoResponse : public ros::Msg
  {
    public:
      std::vector<multimaster_msgs_fkie::SyncMasterInfo> hosts;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned hosts_length = hosts.size();
      outbuffer[offset++] = (hosts_length >> 0) & 0xFF;
      outbuffer[offset++] = (hosts_length >> 8) & 0xFF;
      outbuffer[offset++] = (hosts_length >> 16) & 0xFF;
      outbuffer[offset++] = (hosts_length >> 24) & 0xFF;
      for( unsigned i = 0; i < hosts_length; i++){
      offset += this->hosts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned hosts_length = inbuffer[offset++];
      hosts_length |= inbuffer[offset++] << 8;
      hosts_length |= inbuffer[offset++] << 16;
      hosts_length |= inbuffer[offset++] << 24;
      hosts.clear();
      hosts.reserve(hosts_length);
      for( unsigned i = 0; i < hosts_length; i++){
      hosts.emplace_back();
      offset += this->hosts.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETSYNCINFO; };
    const char * getMD5(){ return "d5261ec56e202860a07fb47b41e1b2a8"; };

  };

  class GetSyncInfo {
    public:
    typedef GetSyncInfoRequest Request;
    typedef GetSyncInfoResponse Response;
  };

}
#endif
