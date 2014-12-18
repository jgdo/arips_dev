#ifndef _ROS_SERVICE_MuxList_h
#define _ROS_SERVICE_MuxList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace topic_tools
{

static const char MUXLIST[] = "topic_tools/MuxList";

  class MuxListRequest : public ros::Msg
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

    const char * getType(){ return MUXLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MuxListResponse : public ros::Msg
  {
    public:
      std::vector<char*> topics;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned topics_length = topics.size();
      outbuffer[offset++] = (topics_length >> 0) & 0xFF;
      outbuffer[offset++] = (topics_length >> 8) & 0xFF;
      outbuffer[offset++] = (topics_length >> 16) & 0xFF;
      outbuffer[offset++] = (topics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < topics_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->topics[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned topics_length = inbuffer[offset++];
      topics_length |= inbuffer[offset++] << 8;
      topics_length |= inbuffer[offset++] << 16;
      topics_length |= inbuffer[offset++] << 24;
      topics.clear();
      topics.reserve(topics_length);
      for( unsigned i = 0; i < topics_length; i++){
      topics.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->topics.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return MUXLIST; };
    const char * getMD5(){ return "b0eef9a05d4e829092fc2f2c3c2aad3d"; };

  };

  class MuxList {
    public:
    typedef MuxListRequest Request;
    typedef MuxListResponse Response;
  };

}
#endif
