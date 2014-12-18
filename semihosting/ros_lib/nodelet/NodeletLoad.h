#ifndef _ROS_SERVICE_NodeletLoad_h
#define _ROS_SERVICE_NodeletLoad_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace nodelet
{

static const char NODELETLOAD[] = "nodelet/NodeletLoad";

  class NodeletLoadRequest : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * type = nullptr;
      std::vector<char*> remap_source_args;
      std::vector<char*> remap_target_args;
      std::vector<char*> my_argv;
      char * bond_id = nullptr;

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
      unsigned remap_source_args_length = remap_source_args.size();
      outbuffer[offset++] = (remap_source_args_length >> 0) & 0xFF;
      outbuffer[offset++] = (remap_source_args_length >> 8) & 0xFF;
      outbuffer[offset++] = (remap_source_args_length >> 16) & 0xFF;
      outbuffer[offset++] = (remap_source_args_length >> 24) & 0xFF;
      for( unsigned i = 0; i < remap_source_args_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->remap_source_args[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->remap_source_args[i], length_);
      offset += length_;
      }
      }
      unsigned remap_target_args_length = remap_target_args.size();
      outbuffer[offset++] = (remap_target_args_length >> 0) & 0xFF;
      outbuffer[offset++] = (remap_target_args_length >> 8) & 0xFF;
      outbuffer[offset++] = (remap_target_args_length >> 16) & 0xFF;
      outbuffer[offset++] = (remap_target_args_length >> 24) & 0xFF;
      for( unsigned i = 0; i < remap_target_args_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->remap_target_args[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->remap_target_args[i], length_);
      offset += length_;
      }
      }
      unsigned my_argv_length = my_argv.size();
      outbuffer[offset++] = (my_argv_length >> 0) & 0xFF;
      outbuffer[offset++] = (my_argv_length >> 8) & 0xFF;
      outbuffer[offset++] = (my_argv_length >> 16) & 0xFF;
      outbuffer[offset++] = (my_argv_length >> 24) & 0xFF;
      for( unsigned i = 0; i < my_argv_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->my_argv[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->my_argv[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->bond_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->bond_id, length_);
      offset += length_;
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
      this->type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned remap_source_args_length = inbuffer[offset++];
      remap_source_args_length |= inbuffer[offset++] << 8;
      remap_source_args_length |= inbuffer[offset++] << 16;
      remap_source_args_length |= inbuffer[offset++] << 24;
      remap_source_args.clear();
      remap_source_args.reserve(remap_source_args_length);
      for( unsigned i = 0; i < remap_source_args_length; i++){
      remap_source_args.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->remap_source_args.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned remap_target_args_length = inbuffer[offset++];
      remap_target_args_length |= inbuffer[offset++] << 8;
      remap_target_args_length |= inbuffer[offset++] << 16;
      remap_target_args_length |= inbuffer[offset++] << 24;
      remap_target_args.clear();
      remap_target_args.reserve(remap_target_args_length);
      for( unsigned i = 0; i < remap_target_args_length; i++){
      remap_target_args.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->remap_target_args.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned my_argv_length = inbuffer[offset++];
      my_argv_length |= inbuffer[offset++] << 8;
      my_argv_length |= inbuffer[offset++] << 16;
      my_argv_length |= inbuffer[offset++] << 24;
      my_argv.clear();
      my_argv.reserve(my_argv_length);
      for( unsigned i = 0; i < my_argv_length; i++){
      my_argv.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->my_argv.back() = (char *)(inbuffer + offset-1);
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
      this->bond_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return NODELETLOAD; };
    const char * getMD5(){ return "c6e28cc4d2e259249d96cfb50658fbec"; };

  };

  class NodeletLoadResponse : public ros::Msg
  {
    public:
      bool success = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_.real;
      }
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return NODELETLOAD; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class NodeletLoad {
    public:
    typedef NodeletLoadRequest Request;
    typedef NodeletLoadResponse Response;
  };

}
#endif
