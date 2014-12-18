#ifndef _ROS_SERVICE_Publishers_h
#define _ROS_SERVICE_Publishers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char PUBLISHERS[] = "rosapi/Publishers";

  class PublishersRequest : public ros::Msg
  {
    public:
      char * topic = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->topic);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_);
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
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class PublishersResponse : public ros::Msg
  {
    public:
      std::vector<char*> publishers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned publishers_length = publishers.size();
      outbuffer[offset++] = (publishers_length >> 0) & 0xFF;
      outbuffer[offset++] = (publishers_length >> 8) & 0xFF;
      outbuffer[offset++] = (publishers_length >> 16) & 0xFF;
      outbuffer[offset++] = (publishers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < publishers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->publishers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->publishers[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned publishers_length = inbuffer[offset++];
      publishers_length |= inbuffer[offset++] << 8;
      publishers_length |= inbuffer[offset++] << 16;
      publishers_length |= inbuffer[offset++] << 24;
      publishers.clear();
      publishers.reserve(publishers_length);
      for( unsigned i = 0; i < publishers_length; i++){
      publishers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->publishers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "167d8030c4ca4018261dff8ae5083dc8"; };

  };

  class Publishers {
    public:
    typedef PublishersRequest Request;
    typedef PublishersResponse Response;
  };

}
#endif
