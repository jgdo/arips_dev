#ifndef _ROS_wifi_ddwrt_SiteSurvey_h
#define _ROS_wifi_ddwrt_SiteSurvey_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "wifi_ddwrt/Network.h"
#include <vector>

namespace wifi_ddwrt
{

  class SiteSurvey : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<wifi_ddwrt::Network> networks;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned networks_length = networks.size();
      outbuffer[offset++] = (networks_length >> 0) & 0xFF;
      outbuffer[offset++] = (networks_length >> 8) & 0xFF;
      outbuffer[offset++] = (networks_length >> 16) & 0xFF;
      outbuffer[offset++] = (networks_length >> 24) & 0xFF;
      for( unsigned i = 0; i < networks_length; i++){
      offset += this->networks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned networks_length = inbuffer[offset++];
      networks_length |= inbuffer[offset++] << 8;
      networks_length |= inbuffer[offset++] << 16;
      networks_length |= inbuffer[offset++] << 24;
      networks.clear();
      networks.reserve(networks_length);
      for( unsigned i = 0; i < networks_length; i++){
      networks.emplace_back();
      offset += this->networks.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "wifi_ddwrt/SiteSurvey"; };
    const char * getMD5(){ return "f1063b16bb121ef190ae5edfe09d94ec"; };

  };

}
#endif