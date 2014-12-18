#ifndef _ROS_controller_manager_msgs_ControllerState_h
#define _ROS_controller_manager_msgs_ControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace controller_manager_msgs
{

  class ControllerState : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * state = nullptr;
      char * type = nullptr;
      char * hardware_interface = nullptr;
      std::vector<char*> resources;

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
      uint32_t length_ = strlen( (const char*) this->state);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_);
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
      uint32_t length_ = strlen( (const char*) this->hardware_interface);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_interface, length_);
      offset += length_;
      }
      unsigned resources_length = resources.size();
      outbuffer[offset++] = (resources_length >> 0) & 0xFF;
      outbuffer[offset++] = (resources_length >> 8) & 0xFF;
      outbuffer[offset++] = (resources_length >> 16) & 0xFF;
      outbuffer[offset++] = (resources_length >> 24) & 0xFF;
      for( unsigned i = 0; i < resources_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->resources[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->resources[i], length_);
      offset += length_;
      }
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
      this->state = (char *)(inbuffer + offset-1);
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
      this->hardware_interface = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned resources_length = inbuffer[offset++];
      resources_length |= inbuffer[offset++] << 8;
      resources_length |= inbuffer[offset++] << 16;
      resources_length |= inbuffer[offset++] << 24;
      resources.clear();
      resources.reserve(resources_length);
      for( unsigned i = 0; i < resources_length; i++){
      resources.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->resources.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "controller_manager_msgs/ControllerState"; };
    const char * getMD5(){ return "cac963cc68f4f5836765c108de0fc446"; };

  };

}
#endif