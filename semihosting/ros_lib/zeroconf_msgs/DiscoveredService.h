#ifndef _ROS_zeroconf_msgs_DiscoveredService_h
#define _ROS_zeroconf_msgs_DiscoveredService_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace zeroconf_msgs
{

  class DiscoveredService : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * type = nullptr;
      char * domain = nullptr;
      char * description = nullptr;
      char * hostname = nullptr;
      std::vector<char*> ipv4_addresses;
      std::vector<char*> ipv6_addresses;
      int32_t port = 0;
      uint32_t cookie = 0;
      bool is_local = 0;
      bool our_own = 0;
      bool wide_area = 0;
      bool multicast = 0;
      bool cached = 0;

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
      uint32_t length_ = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->domain);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->domain, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->description);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->hostname);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hostname, length_);
      offset += length_;
      }
      unsigned ipv4_addresses_length = ipv4_addresses.size();
      outbuffer[offset++] = (ipv4_addresses_length >> 0) & 0xFF;
      outbuffer[offset++] = (ipv4_addresses_length >> 8) & 0xFF;
      outbuffer[offset++] = (ipv4_addresses_length >> 16) & 0xFF;
      outbuffer[offset++] = (ipv4_addresses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ipv4_addresses_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->ipv4_addresses[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ipv4_addresses[i], length_);
      offset += length_;
      }
      }
      unsigned ipv6_addresses_length = ipv6_addresses.size();
      outbuffer[offset++] = (ipv6_addresses_length >> 0) & 0xFF;
      outbuffer[offset++] = (ipv6_addresses_length >> 8) & 0xFF;
      outbuffer[offset++] = (ipv6_addresses_length >> 16) & 0xFF;
      outbuffer[offset++] = (ipv6_addresses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ipv6_addresses_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->ipv6_addresses[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ipv6_addresses[i], length_);
      offset += length_;
      }
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->port;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->port);
      *(outbuffer + offset + 0) = (this->cookie >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cookie >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cookie >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cookie >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cookie);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_local;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_local);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->our_own;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->our_own);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->wide_area;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->wide_area);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->multicast;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->multicast);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->cached;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->cached);
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
      this->type = (char *)(inbuffer + offset-1);
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
      this->domain = (char *)(inbuffer + offset-1);
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
      this->description = (char *)(inbuffer + offset-1);
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
      this->hostname = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned ipv4_addresses_length = inbuffer[offset++];
      ipv4_addresses_length |= inbuffer[offset++] << 8;
      ipv4_addresses_length |= inbuffer[offset++] << 16;
      ipv4_addresses_length |= inbuffer[offset++] << 24;
      ipv4_addresses.clear();
      ipv4_addresses.reserve(ipv4_addresses_length);
      for( unsigned i = 0; i < ipv4_addresses_length; i++){
      ipv4_addresses.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->ipv4_addresses.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned ipv6_addresses_length = inbuffer[offset++];
      ipv6_addresses_length |= inbuffer[offset++] << 8;
      ipv6_addresses_length |= inbuffer[offset++] << 16;
      ipv6_addresses_length |= inbuffer[offset++] << 24;
      ipv6_addresses.clear();
      ipv6_addresses.reserve(ipv6_addresses_length);
      for( unsigned i = 0; i < ipv6_addresses_length; i++){
      ipv6_addresses.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->ipv6_addresses.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
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
      this->port = u_.real;
      }
      offset += sizeof(this->port);
      this->cookie =  ((uint32_t) (*(inbuffer + offset)));
      this->cookie |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cookie |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cookie |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cookie);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_local = u_.real;
      }
      offset += sizeof(this->is_local);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->our_own = u_.real;
      }
      offset += sizeof(this->our_own);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wide_area = u_.real;
      }
      offset += sizeof(this->wide_area);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->multicast = u_.real;
      }
      offset += sizeof(this->multicast);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cached = u_.real;
      }
      offset += sizeof(this->cached);
     return offset;
    }

    const char * getType(){ return "zeroconf_msgs/DiscoveredService"; };
    const char * getMD5(){ return "3aabc6dd9875ef180c75536ad9a51d86"; };

  };

}
#endif