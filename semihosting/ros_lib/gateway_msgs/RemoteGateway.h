#ifndef _ROS_gateway_msgs_RemoteGateway_h
#define _ROS_gateway_msgs_RemoteGateway_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gateway_msgs/Rule.h"
#include <vector>
#include "gateway_msgs/RemoteRule.h"

namespace gateway_msgs
{

  class RemoteGateway : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * ip = nullptr;
      bool firewall = 0;
      std::vector<gateway_msgs::Rule> public_interface;
      std::vector<gateway_msgs::RemoteRule> flipped_interface;
      std::vector<gateway_msgs::RemoteRule> pulled_interface;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->ip);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ip, length_);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->firewall;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->firewall);
      unsigned public_interface_length = public_interface.size();
      outbuffer[offset++] = (public_interface_length >> 0) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 8) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 16) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 24) & 0xFF;
      for( unsigned i = 0; i < public_interface_length; i++){
      offset += this->public_interface[i].serialize(outbuffer + offset);
      }
      unsigned flipped_interface_length = flipped_interface.size();
      outbuffer[offset++] = (flipped_interface_length >> 0) & 0xFF;
      outbuffer[offset++] = (flipped_interface_length >> 8) & 0xFF;
      outbuffer[offset++] = (flipped_interface_length >> 16) & 0xFF;
      outbuffer[offset++] = (flipped_interface_length >> 24) & 0xFF;
      for( unsigned i = 0; i < flipped_interface_length; i++){
      offset += this->flipped_interface[i].serialize(outbuffer + offset);
      }
      unsigned pulled_interface_length = pulled_interface.size();
      outbuffer[offset++] = (pulled_interface_length >> 0) & 0xFF;
      outbuffer[offset++] = (pulled_interface_length >> 8) & 0xFF;
      outbuffer[offset++] = (pulled_interface_length >> 16) & 0xFF;
      outbuffer[offset++] = (pulled_interface_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pulled_interface_length; i++){
      offset += this->pulled_interface[i].serialize(outbuffer + offset);
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
      this->name = (char *)(inbuffer + offset-1);
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
      this->ip = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->firewall = u_.real;
      }
      offset += sizeof(this->firewall);
      unsigned public_interface_length = inbuffer[offset++];
      public_interface_length |= inbuffer[offset++] << 8;
      public_interface_length |= inbuffer[offset++] << 16;
      public_interface_length |= inbuffer[offset++] << 24;
      public_interface.clear();
      public_interface.reserve(public_interface_length);
      for( unsigned i = 0; i < public_interface_length; i++){
      public_interface.emplace_back();
      offset += this->public_interface.back().deserialize(inbuffer + offset);
      }
      unsigned flipped_interface_length = inbuffer[offset++];
      flipped_interface_length |= inbuffer[offset++] << 8;
      flipped_interface_length |= inbuffer[offset++] << 16;
      flipped_interface_length |= inbuffer[offset++] << 24;
      flipped_interface.clear();
      flipped_interface.reserve(flipped_interface_length);
      for( unsigned i = 0; i < flipped_interface_length; i++){
      flipped_interface.emplace_back();
      offset += this->flipped_interface.back().deserialize(inbuffer + offset);
      }
      unsigned pulled_interface_length = inbuffer[offset++];
      pulled_interface_length |= inbuffer[offset++] << 8;
      pulled_interface_length |= inbuffer[offset++] << 16;
      pulled_interface_length |= inbuffer[offset++] << 24;
      pulled_interface.clear();
      pulled_interface.reserve(pulled_interface_length);
      for( unsigned i = 0; i < pulled_interface_length; i++){
      pulled_interface.emplace_back();
      offset += this->pulled_interface.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gateway_msgs/RemoteGateway"; };
    const char * getMD5(){ return "c2825a110d4bc0a2e94421a89778e5f4"; };

  };

}
#endif