#ifndef _ROS_SERVICE_Services_h
#define _ROS_SERVICE_Services_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char SERVICES[] = "rosapi/Services";

  class ServicesRequest : public ros::Msg
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

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ServicesResponse : public ros::Msg
  {
    public:
      std::vector<char*> services;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned services_length = services.size();
      outbuffer[offset++] = (services_length >> 0) & 0xFF;
      outbuffer[offset++] = (services_length >> 8) & 0xFF;
      outbuffer[offset++] = (services_length >> 16) & 0xFF;
      outbuffer[offset++] = (services_length >> 24) & 0xFF;
      for( unsigned i = 0; i < services_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->services[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->services[i], length_);
      offset += length_;
      }
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
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->services.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "e44a7e7bcb900acadbcc28b132378f0c"; };

  };

  class Services {
    public:
    typedef ServicesRequest Request;
    typedef ServicesResponse Response;
  };

}
#endif
