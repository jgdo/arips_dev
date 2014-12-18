#ifndef _ROS_SERVICE_PublishMap_h
#define _ROS_SERVICE_PublishMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace map_store
{

static const char PUBLISHMAP[] = "map_store/PublishMap";

  class PublishMapRequest : public ros::Msg
  {
    public:
      char * map_id = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->map_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->map_id, length_);
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
      this->map_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return PUBLISHMAP; };
    const char * getMD5(){ return "d742ddbd5e3e8937162044ae4b300275"; };

  };

  class PublishMapResponse : public ros::Msg
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

    const char * getType(){ return PUBLISHMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PublishMap {
    public:
    typedef PublishMapRequest Request;
    typedef PublishMapResponse Response;
  };

}
#endif
