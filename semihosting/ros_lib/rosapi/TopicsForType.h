#ifndef _ROS_SERVICE_TopicsForType_h
#define _ROS_SERVICE_TopicsForType_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char TOPICSFORTYPE[] = "rosapi/TopicsForType";

  class TopicsForTypeRequest : public ros::Msg
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

    const char * getType(){ return TOPICSFORTYPE; };
    const char * getMD5(){ return "dc67331de85cf97091b7d45e5c64ab75"; };

  };

  class TopicsForTypeResponse : public ros::Msg
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

    const char * getType(){ return TOPICSFORTYPE; };
    const char * getMD5(){ return "b0eef9a05d4e829092fc2f2c3c2aad3d"; };

  };

  class TopicsForType {
    public:
    typedef TopicsForTypeRequest Request;
    typedef TopicsForTypeResponse Response;
  };

}
#endif
