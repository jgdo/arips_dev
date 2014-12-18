#ifndef _ROS_rocon_app_manager_msgs_App_h
#define _ROS_rocon_app_manager_msgs_App_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_app_manager_msgs/Icon.h"
#include "rocon_app_manager_msgs/PairingClient.h"
#include <vector>

namespace rocon_app_manager_msgs
{

  class App : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * display_name = nullptr;
      char * description = nullptr;
      char * platform = nullptr;
      char * status = nullptr;
      rocon_app_manager_msgs::Icon icon;
      std::vector<rocon_app_manager_msgs::PairingClient> pairing_clients;

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
      uint32_t length_ = strlen( (const char*) this->display_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->display_name, length_);
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
      uint32_t length_ = strlen( (const char*) this->platform);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->platform, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->status);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_);
      offset += length_;
      }
      offset += this->icon.serialize(outbuffer + offset);
      unsigned pairing_clients_length = pairing_clients.size();
      outbuffer[offset++] = (pairing_clients_length >> 0) & 0xFF;
      outbuffer[offset++] = (pairing_clients_length >> 8) & 0xFF;
      outbuffer[offset++] = (pairing_clients_length >> 16) & 0xFF;
      outbuffer[offset++] = (pairing_clients_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pairing_clients_length; i++){
      offset += this->pairing_clients[i].serialize(outbuffer + offset);
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
      this->display_name = (char *)(inbuffer + offset-1);
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
      this->platform = (char *)(inbuffer + offset-1);
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
      this->status = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->icon.deserialize(inbuffer + offset);
      unsigned pairing_clients_length = inbuffer[offset++];
      pairing_clients_length |= inbuffer[offset++] << 8;
      pairing_clients_length |= inbuffer[offset++] << 16;
      pairing_clients_length |= inbuffer[offset++] << 24;
      pairing_clients.clear();
      pairing_clients.reserve(pairing_clients_length);
      for( unsigned i = 0; i < pairing_clients_length; i++){
      pairing_clients.emplace_back();
      offset += this->pairing_clients.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "rocon_app_manager_msgs/App"; };
    const char * getMD5(){ return "f7c3d8107b83b0a0871d32ad56957836"; };

  };

}
#endif