#ifndef _ROS_theora_image_transport_Packet_h
#define _ROS_theora_image_transport_Packet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace theora_image_transport
{

  class Packet : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<uint8_t> data;
      int32_t b_o_s = 0;
      int32_t e_o_s = 0;
      int64_t granulepos = 0;
      int64_t packetno = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->b_o_s;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->b_o_s);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->e_o_s;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->e_o_s);
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.real = this->granulepos;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_.base >> (8 * 7)) & 0xFF;
      }
      offset += sizeof(this->granulepos);
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.real = this->packetno;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_.base >> (8 * 7)) & 0xFF;
      }
      offset += sizeof(this->packetno);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b_o_s = u_.real;
      }
      offset += sizeof(this->b_o_s);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->e_o_s = u_.real;
      }
      offset += sizeof(this->e_o_s);
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->granulepos = u_.real;
      }
      offset += sizeof(this->granulepos);
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->packetno = u_.real;
      }
      offset += sizeof(this->packetno);
     return offset;
    }

    const char * getType(){ return "theora_image_transport/Packet"; };
    const char * getMD5(){ return "33ac4e14a7cff32e7e0d65f18bb410f3"; };

  };

}
#endif