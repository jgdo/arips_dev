#ifndef _ROS_SERVICE_GetParamNames_h
#define _ROS_SERVICE_GetParamNames_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char GETPARAMNAMES[] = "rosapi/GetParamNames";

  class GetParamNamesRequest : public ros::Msg
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

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetParamNamesResponse : public ros::Msg
  {
    public:
      std::vector<char*> names;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned names_length = names.size();
      outbuffer[offset++] = (names_length >> 0) & 0xFF;
      outbuffer[offset++] = (names_length >> 8) & 0xFF;
      outbuffer[offset++] = (names_length >> 16) & 0xFF;
      outbuffer[offset++] = (names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned names_length = inbuffer[offset++];
      names_length |= inbuffer[offset++] << 8;
      names_length |= inbuffer[offset++] << 16;
      names_length |= inbuffer[offset++] << 24;
      names.clear();
      names.reserve(names_length);
      for( unsigned i = 0; i < names_length; i++){
      names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "dc7ae3609524b18034e49294a4ce670e"; };

  };

  class GetParamNames {
    public:
    typedef GetParamNamesRequest Request;
    typedef GetParamNamesResponse Response;
  };

}
#endif
