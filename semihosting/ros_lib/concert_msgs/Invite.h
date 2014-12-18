#ifndef _ROS_SERVICE_Invite_h
#define _ROS_SERVICE_Invite_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace concert_msgs
{

static const char INVITE[] = "concert_msgs/Invite";

  class InviteRequest : public ros::Msg
  {
    public:
      char * mastername = nullptr;
      std::vector<char*> clientnames;
      bool ok_flag = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->mastername);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mastername, length_);
      offset += length_;
      }
      unsigned clientnames_length = clientnames.size();
      outbuffer[offset++] = (clientnames_length >> 0) & 0xFF;
      outbuffer[offset++] = (clientnames_length >> 8) & 0xFF;
      outbuffer[offset++] = (clientnames_length >> 16) & 0xFF;
      outbuffer[offset++] = (clientnames_length >> 24) & 0xFF;
      for( unsigned i = 0; i < clientnames_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->clientnames[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->clientnames[i], length_);
      offset += length_;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->ok_flag;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->ok_flag);
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
      this->mastername = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned clientnames_length = inbuffer[offset++];
      clientnames_length |= inbuffer[offset++] << 8;
      clientnames_length |= inbuffer[offset++] << 16;
      clientnames_length |= inbuffer[offset++] << 24;
      clientnames.clear();
      clientnames.reserve(clientnames_length);
      for( unsigned i = 0; i < clientnames_length; i++){
      clientnames.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->clientnames.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok_flag = u_.real;
      }
      offset += sizeof(this->ok_flag);
     return offset;
    }

    const char * getType(){ return INVITE; };
    const char * getMD5(){ return "082cfd7cce8a75992c90b91803aba9c4"; };

  };

  class InviteResponse : public ros::Msg
  {
    public:
      char * result = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->result);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_);
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
      this->result = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return INVITE; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class Invite {
    public:
    typedef InviteRequest Request;
    typedef InviteResponse Response;
  };

}
#endif
