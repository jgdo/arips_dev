#ifndef _ROS_SERVICE_Remote_h
#define _ROS_SERVICE_Remote_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gateway_msgs/RemoteRule.h"
#include <vector>

namespace gateway_msgs
{

static const char REMOTE[] = "gateway_msgs/Remote";

  class RemoteRequest : public ros::Msg
  {
    public:
      std::vector<gateway_msgs::RemoteRule> remotes;
      bool cancel = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned remotes_length = remotes.size();
      outbuffer[offset++] = (remotes_length >> 0) & 0xFF;
      outbuffer[offset++] = (remotes_length >> 8) & 0xFF;
      outbuffer[offset++] = (remotes_length >> 16) & 0xFF;
      outbuffer[offset++] = (remotes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < remotes_length; i++){
      offset += this->remotes[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->cancel;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->cancel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned remotes_length = inbuffer[offset++];
      remotes_length |= inbuffer[offset++] << 8;
      remotes_length |= inbuffer[offset++] << 16;
      remotes_length |= inbuffer[offset++] << 24;
      remotes.clear();
      remotes.reserve(remotes_length);
      for( unsigned i = 0; i < remotes_length; i++){
      remotes.emplace_back();
      offset += this->remotes.back().deserialize(inbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cancel = u_.real;
      }
      offset += sizeof(this->cancel);
     return offset;
    }

    const char * getType(){ return REMOTE; };
    const char * getMD5(){ return "e9d79fdaee662b9f88ad5ffedb506465"; };

  };

  class RemoteResponse : public ros::Msg
  {
    public:
      int8_t result = 0;
      char * error_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->result;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->result);
      {
      uint32_t length_ = strlen( (const char*) this->error_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_.real;
      }
      offset += sizeof(this->result);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return REMOTE; };
    const char * getMD5(){ return "cb1e85ae0c5f4b1c31221493724cc5aa"; };

  };

  class Remote {
    public:
    typedef RemoteRequest Request;
    typedef RemoteResponse Response;
  };

}
#endif
