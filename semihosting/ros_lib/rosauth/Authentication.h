#ifndef _ROS_SERVICE_Authentication_h
#define _ROS_SERVICE_Authentication_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rosauth
{

static const char AUTHENTICATION[] = "rosauth/Authentication";

  class AuthenticationRequest : public ros::Msg
  {
    public:
      char * mac = nullptr;
      char * client = nullptr;
      char * dest = nullptr;
      char * rand = nullptr;
      ros::Time t;
      char * level = nullptr;
      ros::Time end;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->mac);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mac, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->client);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->client, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->dest);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dest, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->rand);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rand, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->t.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.sec);
      *(outbuffer + offset + 0) = (this->t.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.nsec);
      {
      uint32_t length_ = strlen( (const char*) this->level);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->level, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->end.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.sec);
      *(outbuffer + offset + 0) = (this->end.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.nsec);
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
      this->mac = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->client = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->dest = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->rand = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->t.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.sec);
      this->t.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.nsec);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->level = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->end.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.sec);
      this->end.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.nsec);
     return offset;
    }

    const char * getType(){ return AUTHENTICATION; };
    const char * getMD5(){ return "cad474945b8be70807460ba22a018b32"; };

  };

  class AuthenticationResponse : public ros::Msg
  {
    public:
      bool authenticated = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->authenticated;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->authenticated);
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
      this->authenticated = u_.real;
      }
      offset += sizeof(this->authenticated);
     return offset;
    }

    const char * getType(){ return AUTHENTICATION; };
    const char * getMD5(){ return "7eb9cf569b3e4581e3eff49da1ca4f39"; };

  };

  class Authentication {
    public:
    typedef AuthenticationRequest Request;
    typedef AuthenticationResponse Response;
  };

}
#endif