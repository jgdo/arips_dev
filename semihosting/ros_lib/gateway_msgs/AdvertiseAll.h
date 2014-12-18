#ifndef _ROS_SERVICE_AdvertiseAll_h
#define _ROS_SERVICE_AdvertiseAll_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gateway_msgs/Rule.h"
#include <vector>

namespace gateway_msgs
{

static const char ADVERTISEALL[] = "gateway_msgs/AdvertiseAll";

  class AdvertiseAllRequest : public ros::Msg
  {
    public:
      bool cancel = 0;
      std::vector<gateway_msgs::Rule> blacklist;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->cancel;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->cancel);
      unsigned blacklist_length = blacklist.size();
      outbuffer[offset++] = (blacklist_length >> 0) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 8) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 16) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < blacklist_length; i++){
      offset += this->blacklist[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      unsigned blacklist_length = inbuffer[offset++];
      blacklist_length |= inbuffer[offset++] << 8;
      blacklist_length |= inbuffer[offset++] << 16;
      blacklist_length |= inbuffer[offset++] << 24;
      blacklist.clear();
      blacklist.reserve(blacklist_length);
      for( unsigned i = 0; i < blacklist_length; i++){
      blacklist.emplace_back();
      offset += this->blacklist.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return ADVERTISEALL; };
    const char * getMD5(){ return "b9886afdbeb585f0929f1fe1334dd03e"; };

  };

  class AdvertiseAllResponse : public ros::Msg
  {
    public:
      int8_t result = 0;
      char * error_message = nullptr;
      std::vector<gateway_msgs::Rule> blacklist;

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
      unsigned blacklist_length = blacklist.size();
      outbuffer[offset++] = (blacklist_length >> 0) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 8) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 16) & 0xFF;
      outbuffer[offset++] = (blacklist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < blacklist_length; i++){
      offset += this->blacklist[i].serialize(outbuffer + offset);
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
      unsigned blacklist_length = inbuffer[offset++];
      blacklist_length |= inbuffer[offset++] << 8;
      blacklist_length |= inbuffer[offset++] << 16;
      blacklist_length |= inbuffer[offset++] << 24;
      blacklist.clear();
      blacklist.reserve(blacklist_length);
      for( unsigned i = 0; i < blacklist_length; i++){
      blacklist.emplace_back();
      offset += this->blacklist.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return ADVERTISEALL; };
    const char * getMD5(){ return "d9c8370d5d4ea835b3dd7ba52feee140"; };

  };

  class AdvertiseAll {
    public:
    typedef AdvertiseAllRequest Request;
    typedef AdvertiseAllResponse Response;
  };

}
#endif
