#ifndef _ROS_SERVICE_SendRecv_h
#define _ROS_SERVICE_SendRecv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace shared_serial
{

static const char SENDRECV[] = "shared_serial/SendRecv";

  class SendRecvRequest : public ros::Msg
  {
    public:
      uint32_t socket = 0;
      std::vector<uint8_t> send_data;
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
      unsigned send_data_length = send_data.size();
      outbuffer[offset++] = (send_data_length >> 0) & 0xFF;
      outbuffer[offset++] = (send_data_length >> 8) & 0xFF;
      outbuffer[offset++] = (send_data_length >> 16) & 0xFF;
      outbuffer[offset++] = (send_data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < send_data_length; i++){
      *(outbuffer + offset + 0) = (this->send_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->send_data[i]);
      }
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
      unsigned send_data_length = inbuffer[offset++];
      send_data_length |= inbuffer[offset++] << 8;
      send_data_length |= inbuffer[offset++] << 16;
      send_data_length |= inbuffer[offset++] << 24;
      send_data.clear();
      send_data.reserve(send_data_length);
      for( unsigned i = 0; i < send_data_length; i++){
      send_data.emplace_back();
      this->send_data.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->send_data.back());
      }
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

    const char * getType(){ return SENDRECV; };
    const char * getMD5(){ return "3fa8cb9d9b17970f1ef94f8b72f437be"; };

  };

  class SendRecvResponse : public ros::Msg
  {
    public:
      uint32_t socket = 0;
      std::vector<uint8_t> recv_data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->socket >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->socket >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->socket >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->socket >> (8 * 3)) & 0xFF;
      offset += sizeof(this->socket);
      unsigned recv_data_length = recv_data.size();
      outbuffer[offset++] = (recv_data_length >> 0) & 0xFF;
      outbuffer[offset++] = (recv_data_length >> 8) & 0xFF;
      outbuffer[offset++] = (recv_data_length >> 16) & 0xFF;
      outbuffer[offset++] = (recv_data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < recv_data_length; i++){
      *(outbuffer + offset + 0) = (this->recv_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recv_data[i]);
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
      unsigned recv_data_length = inbuffer[offset++];
      recv_data_length |= inbuffer[offset++] << 8;
      recv_data_length |= inbuffer[offset++] << 16;
      recv_data_length |= inbuffer[offset++] << 24;
      recv_data.clear();
      recv_data.reserve(recv_data_length);
      for( unsigned i = 0; i < recv_data_length; i++){
      recv_data.emplace_back();
      this->recv_data.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->recv_data.back());
      }
     return offset;
    }

    const char * getType(){ return SENDRECV; };
    const char * getMD5(){ return "85c9ca63788ec2863d436bf470432137"; };

  };

  class SendRecv {
    public:
    typedef SendRecvRequest Request;
    typedef SendRecvResponse Response;
  };

}
#endif
