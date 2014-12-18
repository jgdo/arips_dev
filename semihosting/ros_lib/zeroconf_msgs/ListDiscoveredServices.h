#ifndef _ROS_SERVICE_ListDiscoveredServices_h
#define _ROS_SERVICE_ListDiscoveredServices_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "zeroconf_msgs/DiscoveredService.h"

namespace zeroconf_msgs
{

static const char LISTDISCOVEREDSERVICES[] = "zeroconf_msgs/ListDiscoveredServices";

  class ListDiscoveredServicesRequest : public ros::Msg
  {
    public:
      char * service_type = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->service_type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->service_type, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->service_type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return LISTDISCOVEREDSERVICES; };
    const char * getMD5(){ return "e1bf1fd6519c823d87c16f342a193a85"; };

  };

  class ListDiscoveredServicesResponse : public ros::Msg
  {
    public:
      std::vector<zeroconf_msgs::DiscoveredService> services;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned services_length = services.size();
      outbuffer[offset++] = (services_length >> 0) & 0xFF;
      outbuffer[offset++] = (services_length >> 8) & 0xFF;
      outbuffer[offset++] = (services_length >> 16) & 0xFF;
      outbuffer[offset++] = (services_length >> 24) & 0xFF;
      for( unsigned i = 0; i < services_length; i++){
      offset += this->services[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned services_length = inbuffer[offset++];
      services_length |= inbuffer[offset++] << 8;
      services_length |= inbuffer[offset++] << 16;
      services_length |= inbuffer[offset++] << 24;
      services.clear();
      services.reserve(services_length);
      for( unsigned i = 0; i < services_length; i++){
      services.emplace_back();
      offset += this->services.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return LISTDISCOVEREDSERVICES; };
    const char * getMD5(){ return "5e5ad0f4eb44cd96b6518cfd53715bb5"; };

  };

  class ListDiscoveredServices {
    public:
    typedef ListDiscoveredServicesRequest Request;
    typedef ListDiscoveredServicesResponse Response;
  };

}
#endif
