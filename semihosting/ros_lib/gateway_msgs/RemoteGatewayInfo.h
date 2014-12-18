#ifndef _ROS_SERVICE_RemoteGatewayInfo_h
#define _ROS_SERVICE_RemoteGatewayInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "gateway_msgs/RemoteGateway.h"

namespace gateway_msgs
{

static const char REMOTEGATEWAYINFO[] = "gateway_msgs/RemoteGatewayInfo";

  class RemoteGatewayInfoRequest : public ros::Msg
  {
    public:
      std::vector<char*> gateways;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned gateways_length = gateways.size();
      outbuffer[offset++] = (gateways_length >> 0) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 8) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 16) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 24) & 0xFF;
      for( unsigned i = 0; i < gateways_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->gateways[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gateways[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned gateways_length = inbuffer[offset++];
      gateways_length |= inbuffer[offset++] << 8;
      gateways_length |= inbuffer[offset++] << 16;
      gateways_length |= inbuffer[offset++] << 24;
      gateways.clear();
      gateways.reserve(gateways_length);
      for( unsigned i = 0; i < gateways_length; i++){
      gateways.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->gateways.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return REMOTEGATEWAYINFO; };
    const char * getMD5(){ return "e005eaac1f4b29980f211758e562aa6e"; };

  };

  class RemoteGatewayInfoResponse : public ros::Msg
  {
    public:
      std::vector<gateway_msgs::RemoteGateway> gateways;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned gateways_length = gateways.size();
      outbuffer[offset++] = (gateways_length >> 0) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 8) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 16) & 0xFF;
      outbuffer[offset++] = (gateways_length >> 24) & 0xFF;
      for( unsigned i = 0; i < gateways_length; i++){
      offset += this->gateways[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned gateways_length = inbuffer[offset++];
      gateways_length |= inbuffer[offset++] << 8;
      gateways_length |= inbuffer[offset++] << 16;
      gateways_length |= inbuffer[offset++] << 24;
      gateways.clear();
      gateways.reserve(gateways_length);
      for( unsigned i = 0; i < gateways_length; i++){
      gateways.emplace_back();
      offset += this->gateways.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return REMOTEGATEWAYINFO; };
    const char * getMD5(){ return "303a0993450751ffdd331454ee056fe0"; };

  };

  class RemoteGatewayInfo {
    public:
    typedef RemoteGatewayInfoRequest Request;
    typedef RemoteGatewayInfoResponse Response;
  };

}
#endif
