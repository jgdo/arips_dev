#ifndef _ROS_shared_serial_Send_h
#define _ROS_shared_serial_Send_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace shared_serial
{

  class Send : public ros::Msg
  {
    public:
      uint32_t socket = 0;
      std::vector<uint8_t> data;
      float timeout = 0;

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
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->timeout;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->timeout);
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
      this->timeout = u_.real;
      }
      offset += sizeof(this->timeout);
     return offset;
    }

    const char * getType(){ return "shared_serial/Send"; };
    const char * getMD5(){ return "9488c54395f85f0662ca59801f32b45a"; };

  };

}
#endif