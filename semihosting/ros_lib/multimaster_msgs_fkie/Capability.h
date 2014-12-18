#ifndef _ROS_multimaster_msgs_fkie_Capability_h
#define _ROS_multimaster_msgs_fkie_Capability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace multimaster_msgs_fkie
{

  class Capability : public ros::Msg
  {
    public:
      char * namespace = nullptr;
      char * name = nullptr;
      char * type = nullptr;
      std::vector<char*> images;
      char * description = nullptr;
      std::vector<char*> nodes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->namespace);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->namespace, length_);
      offset += length_;
      }
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
      unsigned images_length = images.size();
      outbuffer[offset++] = (images_length >> 0) & 0xFF;
      outbuffer[offset++] = (images_length >> 8) & 0xFF;
      outbuffer[offset++] = (images_length >> 16) & 0xFF;
      outbuffer[offset++] = (images_length >> 24) & 0xFF;
      for( unsigned i = 0; i < images_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->images[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->images[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->description);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_);
      offset += length_;
      }
      unsigned nodes_length = nodes.size();
      outbuffer[offset++] = (nodes_length >> 0) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 8) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 16) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < nodes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->nodes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_);
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
      this->namespace = (char *)(inbuffer + offset-1);
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
      unsigned images_length = inbuffer[offset++];
      images_length |= inbuffer[offset++] << 8;
      images_length |= inbuffer[offset++] << 16;
      images_length |= inbuffer[offset++] << 24;
      images.clear();
      images.reserve(images_length);
      for( unsigned i = 0; i < images_length; i++){
      images.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->images.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
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
      unsigned nodes_length = inbuffer[offset++];
      nodes_length |= inbuffer[offset++] << 8;
      nodes_length |= inbuffer[offset++] << 16;
      nodes_length |= inbuffer[offset++] << 24;
      nodes.clear();
      nodes.reserve(nodes_length);
      for( unsigned i = 0; i < nodes_length; i++){
      nodes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->nodes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/Capability"; };
    const char * getMD5(){ return "ca248f1a2644e7372795bf788ed1941b"; };

  };

}
#endif