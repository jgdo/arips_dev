#ifndef _ROS_SERVICE_Advertise_h
#define _ROS_SERVICE_Advertise_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gateway_msgs/Rule.h"
#include <vector>

namespace gateway_msgs
{

static const char ADVERTISE[] = "gateway_msgs/Advertise";

  class AdvertiseRequest : public ros::Msg
  {
    public:
      bool cancel = 0;
      std::vector<gateway_msgs::Rule> rules;

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
      unsigned rules_length = rules.size();
      outbuffer[offset++] = (rules_length >> 0) & 0xFF;
      outbuffer[offset++] = (rules_length >> 8) & 0xFF;
      outbuffer[offset++] = (rules_length >> 16) & 0xFF;
      outbuffer[offset++] = (rules_length >> 24) & 0xFF;
      for( unsigned i = 0; i < rules_length; i++){
      offset += this->rules[i].serialize(outbuffer + offset);
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
      unsigned rules_length = inbuffer[offset++];
      rules_length |= inbuffer[offset++] << 8;
      rules_length |= inbuffer[offset++] << 16;
      rules_length |= inbuffer[offset++] << 24;
      rules.clear();
      rules.reserve(rules_length);
      for( unsigned i = 0; i < rules_length; i++){
      rules.emplace_back();
      offset += this->rules.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return ADVERTISE; };
    const char * getMD5(){ return "85ef604243258e1594c5a7401f5e0339"; };

  };

  class AdvertiseResponse : public ros::Msg
  {
    public:
      int8_t result = 0;
      char * error_message = nullptr;
      std::vector<gateway_msgs::Rule> watchlist;

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
      unsigned watchlist_length = watchlist.size();
      outbuffer[offset++] = (watchlist_length >> 0) & 0xFF;
      outbuffer[offset++] = (watchlist_length >> 8) & 0xFF;
      outbuffer[offset++] = (watchlist_length >> 16) & 0xFF;
      outbuffer[offset++] = (watchlist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < watchlist_length; i++){
      offset += this->watchlist[i].serialize(outbuffer + offset);
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
      unsigned watchlist_length = inbuffer[offset++];
      watchlist_length |= inbuffer[offset++] << 8;
      watchlist_length |= inbuffer[offset++] << 16;
      watchlist_length |= inbuffer[offset++] << 24;
      watchlist.clear();
      watchlist.reserve(watchlist_length);
      for( unsigned i = 0; i < watchlist_length; i++){
      watchlist.emplace_back();
      offset += this->watchlist.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return ADVERTISE; };
    const char * getMD5(){ return "c389af2721ca403446acba93862aff4f"; };

  };

  class Advertise {
    public:
    typedef AdvertiseRequest Request;
    typedef AdvertiseResponse Response;
  };

}
#endif
