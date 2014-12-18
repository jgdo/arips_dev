#ifndef _ROS_SERVICE_ListPublishedServices_h
#define _ROS_SERVICE_ListPublishedServices_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "zeroconf_msgs/PublishedService.h"
#include <vector>

namespace zeroconf_msgs
{

static const char LISTPUBLISHEDSERVICES[] = "zeroconf_msgs/ListPublishedServices";

  class ListPublishedServicesRequest : public ros::Msg
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

    const char * getType(){ return LISTPUBLISHEDSERVICES; };
    const char * getMD5(){ return "e1bf1fd6519c823d87c16f342a193a85"; };

  };

  class ListPublishedServicesResponse : public ros::Msg
  {
    public:
      std::vector<zeroconf_msgs::PublishedService> services;

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

    const char * getType(){ return LISTPUBLISHEDSERVICES; };
    const char * getMD5(){ return "12aaabf9e3957c5a3d8c742745b6d97d"; };

  };

  class ListPublishedServices {
    public:
    typedef ListPublishedServicesRequest Request;
    typedef ListPublishedServicesResponse Response;
  };

}
#endif
