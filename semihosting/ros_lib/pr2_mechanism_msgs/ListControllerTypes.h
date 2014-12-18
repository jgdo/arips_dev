#ifndef _ROS_SERVICE_ListControllerTypes_h
#define _ROS_SERVICE_ListControllerTypes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace pr2_mechanism_msgs
{

static const char LISTCONTROLLERTYPES[] = "pr2_mechanism_msgs/ListControllerTypes";

  class ListControllerTypesRequest : public ros::Msg
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

    const char * getType(){ return LISTCONTROLLERTYPES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListControllerTypesResponse : public ros::Msg
  {
    public:
      std::vector<char*> types;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned types_length = types.size();
      outbuffer[offset++] = (types_length >> 0) & 0xFF;
      outbuffer[offset++] = (types_length >> 8) & 0xFF;
      outbuffer[offset++] = (types_length >> 16) & 0xFF;
      outbuffer[offset++] = (types_length >> 24) & 0xFF;
      for( unsigned i = 0; i < types_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->types[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->types[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned types_length = inbuffer[offset++];
      types_length |= inbuffer[offset++] << 8;
      types_length |= inbuffer[offset++] << 16;
      types_length |= inbuffer[offset++] << 24;
      types.clear();
      types.reserve(types_length);
      for( unsigned i = 0; i < types_length; i++){
      types.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->types.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERTYPES; };
    const char * getMD5(){ return "80aee506387f88339842e9a93044c959"; };

  };

  class ListControllerTypes {
    public:
    typedef ListControllerTypesRequest Request;
    typedef ListControllerTypesResponse Response;
  };

}
#endif
