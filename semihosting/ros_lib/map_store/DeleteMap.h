#ifndef _ROS_SERVICE_DeleteMap_h
#define _ROS_SERVICE_DeleteMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace map_store
{

static const char DELETEMAP[] = "map_store/DeleteMap";

  class DeleteMapRequest : public ros::Msg
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

    const char * getType(){ return DELETEMAP; };
    const char * getMD5(){ return "d742ddbd5e3e8937162044ae4b300275"; };

  };

  class DeleteMapResponse : public ros::Msg
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

    const char * getType(){ return DELETEMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteMap {
    public:
    typedef DeleteMapRequest Request;
    typedef DeleteMapResponse Response;
  };

}
#endif
