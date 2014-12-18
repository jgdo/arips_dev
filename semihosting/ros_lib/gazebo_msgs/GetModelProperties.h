#ifndef _ROS_SERVICE_GetModelProperties_h
#define _ROS_SERVICE_GetModelProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace gazebo_msgs
{

static const char GETMODELPROPERTIES[] = "gazebo_msgs/GetModelProperties";

  class GetModelPropertiesRequest : public ros::Msg
  {
    public:
      char * model_name = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->model_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_);
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
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELPROPERTIES; };
    const char * getMD5(){ return "ea31c8eab6fc401383cf528a7c0984ba"; };

  };

  class GetModelPropertiesResponse : public ros::Msg
  {
    public:
      char * parent_model_name = nullptr;
      char * canonical_body_name = nullptr;
      std::vector<char*> body_names;
      std::vector<char*> geom_names;
      std::vector<char*> joint_names;
      std::vector<char*> child_model_names;
      bool is_static = 0;
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->parent_model_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parent_model_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->canonical_body_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->canonical_body_name, length_);
      offset += length_;
      }
      unsigned body_names_length = body_names.size();
      outbuffer[offset++] = (body_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (body_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (body_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (body_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < body_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->body_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->body_names[i], length_);
      offset += length_;
      }
      }
      unsigned geom_names_length = geom_names.size();
      outbuffer[offset++] = (geom_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (geom_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (geom_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (geom_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < geom_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->geom_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->geom_names[i], length_);
      offset += length_;
      }
      }
      unsigned joint_names_length = joint_names.size();
      outbuffer[offset++] = (joint_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->joint_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_);
      offset += length_;
      }
      }
      unsigned child_model_names_length = child_model_names.size();
      outbuffer[offset++] = (child_model_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (child_model_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (child_model_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (child_model_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < child_model_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->child_model_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->child_model_names[i], length_);
      offset += length_;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_static;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_static);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
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
      this->parent_model_name = (char *)(inbuffer + offset-1);
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
      this->canonical_body_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned body_names_length = inbuffer[offset++];
      body_names_length |= inbuffer[offset++] << 8;
      body_names_length |= inbuffer[offset++] << 16;
      body_names_length |= inbuffer[offset++] << 24;
      body_names.clear();
      body_names.reserve(body_names_length);
      for( unsigned i = 0; i < body_names_length; i++){
      body_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->body_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned geom_names_length = inbuffer[offset++];
      geom_names_length |= inbuffer[offset++] << 8;
      geom_names_length |= inbuffer[offset++] << 16;
      geom_names_length |= inbuffer[offset++] << 24;
      geom_names.clear();
      geom_names.reserve(geom_names_length);
      for( unsigned i = 0; i < geom_names_length; i++){
      geom_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->geom_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned joint_names_length = inbuffer[offset++];
      joint_names_length |= inbuffer[offset++] << 8;
      joint_names_length |= inbuffer[offset++] << 16;
      joint_names_length |= inbuffer[offset++] << 24;
      joint_names.clear();
      joint_names.reserve(joint_names_length);
      for( unsigned i = 0; i < joint_names_length; i++){
      joint_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->joint_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned child_model_names_length = inbuffer[offset++];
      child_model_names_length |= inbuffer[offset++] << 8;
      child_model_names_length |= inbuffer[offset++] << 16;
      child_model_names_length |= inbuffer[offset++] << 24;
      child_model_names.clear();
      child_model_names.reserve(child_model_names_length);
      for( unsigned i = 0; i < child_model_names_length; i++){
      child_model_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->child_model_names.back() = (char *)(inbuffer + offset-1);
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
      this->is_static = u_.real;
      }
      offset += sizeof(this->is_static);
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
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELPROPERTIES; };
    const char * getMD5(){ return "b7f370938ef77b464b95f1bab3ec5028"; };

  };

  class GetModelProperties {
    public:
    typedef GetModelPropertiesRequest Request;
    typedef GetModelPropertiesResponse Response;
  };

}
#endif
