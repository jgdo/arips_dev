#ifndef _ROS_SERVICE_Subscribers_h
#define _ROS_SERVICE_Subscribers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char SUBSCRIBERS[] = "rosapi/Subscribers";

  class SubscribersRequest : public ros::Msg
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

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class SubscribersResponse : public ros::Msg
  {
    public:
      std::vector<char*> subscribers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned subscribers_length = subscribers.size();
      outbuffer[offset++] = (subscribers_length >> 0) & 0xFF;
      outbuffer[offset++] = (subscribers_length >> 8) & 0xFF;
      outbuffer[offset++] = (subscribers_length >> 16) & 0xFF;
      outbuffer[offset++] = (subscribers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < subscribers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->subscribers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->subscribers[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned subscribers_length = inbuffer[offset++];
      subscribers_length |= inbuffer[offset++] << 8;
      subscribers_length |= inbuffer[offset++] << 16;
      subscribers_length |= inbuffer[offset++] << 24;
      subscribers.clear();
      subscribers.reserve(subscribers_length);
      for( unsigned i = 0; i < subscribers_length; i++){
      subscribers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->subscribers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "22418cab5ba9531d8c2b738b4e56153b"; };

  };

  class Subscribers {
    public:
    typedef SubscribersRequest Request;
    typedef SubscribersResponse Response;
  };

}
#endif
