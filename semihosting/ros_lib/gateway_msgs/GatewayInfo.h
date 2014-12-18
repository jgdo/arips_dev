#ifndef _ROS_gateway_msgs_GatewayInfo_h
#define _ROS_gateway_msgs_GatewayInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "gateway_msgs/Rule.h"
#include "gateway_msgs/RemoteRule.h"

namespace gateway_msgs
{

  class GatewayInfo : public ros::Msg
  {
    public:
      char * name = nullptr;
      bool connected = 0;
      char * ip = nullptr;
      std::vector<char*> hub_names;
      std::vector<char*> hub_uris;
      bool firewall = 0;
      std::vector<gateway_msgs::Rule> public_watchlist;
      std::vector<gateway_msgs::Rule> public_interface;
      std::vector<gateway_msgs::RemoteRule> flipped_connections;
      std::vector<gateway_msgs::RemoteRule> flip_watchlist;
      std::vector<gateway_msgs::RemoteRule> flipped_in_connections;
      std::vector<gateway_msgs::RemoteRule> pull_watchlist;
      std::vector<gateway_msgs::RemoteRule> pulled_connections;

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
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->connected;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->connected);
      {
      uint32_t length_ = strlen( (const char*) this->ip);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ip, length_);
      offset += length_;
      }
      unsigned hub_names_length = hub_names.size();
      outbuffer[offset++] = (hub_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (hub_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (hub_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (hub_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < hub_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->hub_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hub_names[i], length_);
      offset += length_;
      }
      }
      unsigned hub_uris_length = hub_uris.size();
      outbuffer[offset++] = (hub_uris_length >> 0) & 0xFF;
      outbuffer[offset++] = (hub_uris_length >> 8) & 0xFF;
      outbuffer[offset++] = (hub_uris_length >> 16) & 0xFF;
      outbuffer[offset++] = (hub_uris_length >> 24) & 0xFF;
      for( unsigned i = 0; i < hub_uris_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->hub_uris[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hub_uris[i], length_);
      offset += length_;
      }
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
      unsigned public_watchlist_length = public_watchlist.size();
      outbuffer[offset++] = (public_watchlist_length >> 0) & 0xFF;
      outbuffer[offset++] = (public_watchlist_length >> 8) & 0xFF;
      outbuffer[offset++] = (public_watchlist_length >> 16) & 0xFF;
      outbuffer[offset++] = (public_watchlist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < public_watchlist_length; i++){
      offset += this->public_watchlist[i].serialize(outbuffer + offset);
      }
      unsigned public_interface_length = public_interface.size();
      outbuffer[offset++] = (public_interface_length >> 0) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 8) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 16) & 0xFF;
      outbuffer[offset++] = (public_interface_length >> 24) & 0xFF;
      for( unsigned i = 0; i < public_interface_length; i++){
      offset += this->public_interface[i].serialize(outbuffer + offset);
      }
      unsigned flipped_connections_length = flipped_connections.size();
      outbuffer[offset++] = (flipped_connections_length >> 0) & 0xFF;
      outbuffer[offset++] = (flipped_connections_length >> 8) & 0xFF;
      outbuffer[offset++] = (flipped_connections_length >> 16) & 0xFF;
      outbuffer[offset++] = (flipped_connections_length >> 24) & 0xFF;
      for( unsigned i = 0; i < flipped_connections_length; i++){
      offset += this->flipped_connections[i].serialize(outbuffer + offset);
      }
      unsigned flip_watchlist_length = flip_watchlist.size();
      outbuffer[offset++] = (flip_watchlist_length >> 0) & 0xFF;
      outbuffer[offset++] = (flip_watchlist_length >> 8) & 0xFF;
      outbuffer[offset++] = (flip_watchlist_length >> 16) & 0xFF;
      outbuffer[offset++] = (flip_watchlist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < flip_watchlist_length; i++){
      offset += this->flip_watchlist[i].serialize(outbuffer + offset);
      }
      unsigned flipped_in_connections_length = flipped_in_connections.size();
      outbuffer[offset++] = (flipped_in_connections_length >> 0) & 0xFF;
      outbuffer[offset++] = (flipped_in_connections_length >> 8) & 0xFF;
      outbuffer[offset++] = (flipped_in_connections_length >> 16) & 0xFF;
      outbuffer[offset++] = (flipped_in_connections_length >> 24) & 0xFF;
      for( unsigned i = 0; i < flipped_in_connections_length; i++){
      offset += this->flipped_in_connections[i].serialize(outbuffer + offset);
      }
      unsigned pull_watchlist_length = pull_watchlist.size();
      outbuffer[offset++] = (pull_watchlist_length >> 0) & 0xFF;
      outbuffer[offset++] = (pull_watchlist_length >> 8) & 0xFF;
      outbuffer[offset++] = (pull_watchlist_length >> 16) & 0xFF;
      outbuffer[offset++] = (pull_watchlist_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pull_watchlist_length; i++){
      offset += this->pull_watchlist[i].serialize(outbuffer + offset);
      }
      unsigned pulled_connections_length = pulled_connections.size();
      outbuffer[offset++] = (pulled_connections_length >> 0) & 0xFF;
      outbuffer[offset++] = (pulled_connections_length >> 8) & 0xFF;
      outbuffer[offset++] = (pulled_connections_length >> 16) & 0xFF;
      outbuffer[offset++] = (pulled_connections_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pulled_connections_length; i++){
      offset += this->pulled_connections[i].serialize(outbuffer + offset);
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
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->connected = u_.real;
      }
      offset += sizeof(this->connected);
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
      unsigned hub_names_length = inbuffer[offset++];
      hub_names_length |= inbuffer[offset++] << 8;
      hub_names_length |= inbuffer[offset++] << 16;
      hub_names_length |= inbuffer[offset++] << 24;
      hub_names.clear();
      hub_names.reserve(hub_names_length);
      for( unsigned i = 0; i < hub_names_length; i++){
      hub_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->hub_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned hub_uris_length = inbuffer[offset++];
      hub_uris_length |= inbuffer[offset++] << 8;
      hub_uris_length |= inbuffer[offset++] << 16;
      hub_uris_length |= inbuffer[offset++] << 24;
      hub_uris.clear();
      hub_uris.reserve(hub_uris_length);
      for( unsigned i = 0; i < hub_uris_length; i++){
      hub_uris.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->hub_uris.back() = (char *)(inbuffer + offset-1);
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
      this->firewall = u_.real;
      }
      offset += sizeof(this->firewall);
      unsigned public_watchlist_length = inbuffer[offset++];
      public_watchlist_length |= inbuffer[offset++] << 8;
      public_watchlist_length |= inbuffer[offset++] << 16;
      public_watchlist_length |= inbuffer[offset++] << 24;
      public_watchlist.clear();
      public_watchlist.reserve(public_watchlist_length);
      for( unsigned i = 0; i < public_watchlist_length; i++){
      public_watchlist.emplace_back();
      offset += this->public_watchlist.back().deserialize(inbuffer + offset);
      }
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
      unsigned flipped_connections_length = inbuffer[offset++];
      flipped_connections_length |= inbuffer[offset++] << 8;
      flipped_connections_length |= inbuffer[offset++] << 16;
      flipped_connections_length |= inbuffer[offset++] << 24;
      flipped_connections.clear();
      flipped_connections.reserve(flipped_connections_length);
      for( unsigned i = 0; i < flipped_connections_length; i++){
      flipped_connections.emplace_back();
      offset += this->flipped_connections.back().deserialize(inbuffer + offset);
      }
      unsigned flip_watchlist_length = inbuffer[offset++];
      flip_watchlist_length |= inbuffer[offset++] << 8;
      flip_watchlist_length |= inbuffer[offset++] << 16;
      flip_watchlist_length |= inbuffer[offset++] << 24;
      flip_watchlist.clear();
      flip_watchlist.reserve(flip_watchlist_length);
      for( unsigned i = 0; i < flip_watchlist_length; i++){
      flip_watchlist.emplace_back();
      offset += this->flip_watchlist.back().deserialize(inbuffer + offset);
      }
      unsigned flipped_in_connections_length = inbuffer[offset++];
      flipped_in_connections_length |= inbuffer[offset++] << 8;
      flipped_in_connections_length |= inbuffer[offset++] << 16;
      flipped_in_connections_length |= inbuffer[offset++] << 24;
      flipped_in_connections.clear();
      flipped_in_connections.reserve(flipped_in_connections_length);
      for( unsigned i = 0; i < flipped_in_connections_length; i++){
      flipped_in_connections.emplace_back();
      offset += this->flipped_in_connections.back().deserialize(inbuffer + offset);
      }
      unsigned pull_watchlist_length = inbuffer[offset++];
      pull_watchlist_length |= inbuffer[offset++] << 8;
      pull_watchlist_length |= inbuffer[offset++] << 16;
      pull_watchlist_length |= inbuffer[offset++] << 24;
      pull_watchlist.clear();
      pull_watchlist.reserve(pull_watchlist_length);
      for( unsigned i = 0; i < pull_watchlist_length; i++){
      pull_watchlist.emplace_back();
      offset += this->pull_watchlist.back().deserialize(inbuffer + offset);
      }
      unsigned pulled_connections_length = inbuffer[offset++];
      pulled_connections_length |= inbuffer[offset++] << 8;
      pulled_connections_length |= inbuffer[offset++] << 16;
      pulled_connections_length |= inbuffer[offset++] << 24;
      pulled_connections.clear();
      pulled_connections.reserve(pulled_connections_length);
      for( unsigned i = 0; i < pulled_connections_length; i++){
      pulled_connections.emplace_back();
      offset += this->pulled_connections.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gateway_msgs/GatewayInfo"; };
    const char * getMD5(){ return "dd256c395b10a23239961795b562f6bd"; };

  };

}
#endif