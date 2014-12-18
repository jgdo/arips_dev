#ifndef _ROS_SERVICE_ServiceResponseDetails_h
#define _ROS_SERVICE_ServiceResponseDetails_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosapi/TypeDef.h"
#include <vector>

namespace rosapi
{

static const char SERVICERESPONSEDETAILS[] = "rosapi/ServiceResponseDetails";

  class ServiceResponseDetailsRequest : public ros::Msg
  {
    public:
      char * type = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_);
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
      this->type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SERVICERESPONSEDETAILS; };
    const char * getMD5(){ return "dc67331de85cf97091b7d45e5c64ab75"; };

  };

  class ServiceResponseDetailsResponse : public ros::Msg
  {
    public:
      std::vector<rosapi::TypeDef> typedefs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned typedefs_length = typedefs.size();
      outbuffer[offset++] = (typedefs_length >> 0) & 0xFF;
      outbuffer[offset++] = (typedefs_length >> 8) & 0xFF;
      outbuffer[offset++] = (typedefs_length >> 16) & 0xFF;
      outbuffer[offset++] = (typedefs_length >> 24) & 0xFF;
      for( unsigned i = 0; i < typedefs_length; i++){
      offset += this->typedefs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned typedefs_length = inbuffer[offset++];
      typedefs_length |= inbuffer[offset++] << 8;
      typedefs_length |= inbuffer[offset++] << 16;
      typedefs_length |= inbuffer[offset++] << 24;
      typedefs.clear();
      typedefs.reserve(typedefs_length);
      for( unsigned i = 0; i < typedefs_length; i++){
      typedefs.emplace_back();
      offset += this->typedefs.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return SERVICERESPONSEDETAILS; };
    const char * getMD5(){ return "d088db0da260a2cde072246a5f577519"; };

  };

  class ServiceResponseDetails {
    public:
    typedef ServiceResponseDetailsRequest Request;
    typedef ServiceResponseDetailsResponse Response;
  };

}
#endif
