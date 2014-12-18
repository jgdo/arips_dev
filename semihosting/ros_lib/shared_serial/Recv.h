#ifndef _ROS_SERVICE_Recv_h
#define _ROS_SERVICE_Recv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace shared_serial
{

static const char RECV[] = "shared_serial/Recv";

  class RecvRequest : public ros::Msg
  {
    public:
      uint32_t socket = 0;
      uint32_t length = 0;
      float recv_timeout = 0;
      float sock_timeout = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->socket >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->socket >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->socket >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->socket >> (8 * 3)) & 0xFF;
      offset += sizeof(this->socket);
      *(outbuffer + offset + 0) = (this->length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->recv_timeout;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->recv_timeout);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->sock_timeout;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->sock_timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->socket =  ((uint32_t) (*(inbuffer + offset)));
      this->socket |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->socket |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->socket |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->socket);
      this->length =  ((uint32_t) (*(inbuffer + offset)));
      this->length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->length);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->recv_timeout = u_.real;
      }
      offset += sizeof(this->recv_timeout);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sock_timeout = u_.real;
      }
      offset += sizeof(this->sock_timeout);
     return offset;
    }

    const char * getType(){ return RECV; };
    const char * getMD5(){ return "c05d3c907840837e419db15be31d15b6"; };

  };

  class RecvResponse : public ros::Msg
  {
    public:
      uint32_t socket = 0;
      std::vector<uint8_t> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->socket >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->socket >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->socket >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->socket >> (8 * 3)) & 0xFF;
      offset += sizeof(this->socket);
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->socket =  ((uint32_t) (*(inbuffer + offset)));
      this->socket |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->socket |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->socket |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->socket);
      unsigned data_length = inbuffer[offset++];
      data_length |= inbuffer[offset++] << 8;
      data_length |= inbuffer[offset++] << 16;
      data_length |= inbuffer[offset++] << 24;
      data.clear();
      data.reserve(data_length);
      for( unsigned i = 0; i < data_length; i++){
      data.emplace_back();
      this->data.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return RECV; };
    const char * getMD5(){ return "9aa8c2746a0876552ecc2a81ad0d58a5"; };

  };

  class Recv {
    public:
    typedef RecvRequest Request;
    typedef RecvResponse Response;
  };

}
#endif
