#ifndef _ROS_SERVICE_ServiceProviders_h
#define _ROS_SERVICE_ServiceProviders_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char SERVICEPROVIDERS[] = "rosapi/ServiceProviders";

  class ServiceProvidersRequest : public ros::Msg
  {
    public:
      char * service = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->service);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->service, length_);
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
      this->service = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SERVICEPROVIDERS; };
    const char * getMD5(){ return "1cbcfa13b08f6d36710b9af8741e6112"; };

  };

  class ServiceProvidersResponse : public ros::Msg
  {
    public:
      std::vector<char*> providers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned providers_length = providers.size();
      outbuffer[offset++] = (providers_length >> 0) & 0xFF;
      outbuffer[offset++] = (providers_length >> 8) & 0xFF;
      outbuffer[offset++] = (providers_length >> 16) & 0xFF;
      outbuffer[offset++] = (providers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < providers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->providers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->providers[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned providers_length = inbuffer[offset++];
      providers_length |= inbuffer[offset++] << 8;
      providers_length |= inbuffer[offset++] << 16;
      providers_length |= inbuffer[offset++] << 24;
      providers.clear();
      providers.reserve(providers_length);
      for( unsigned i = 0; i < providers_length; i++){
      providers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->providers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return SERVICEPROVIDERS; };
    const char * getMD5(){ return "945f6849f44f061c178ab393b12c1358"; };

  };

  class ServiceProviders {
    public:
    typedef ServiceProvidersRequest Request;
    typedef ServiceProvidersResponse Response;
  };

}
#endif
