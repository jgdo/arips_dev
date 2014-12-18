#ifndef _ROS_smach_msgs_SmachContainerStructure_h
#define _ROS_smach_msgs_SmachContainerStructure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace smach_msgs
{

  class SmachContainerStructure : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * path = nullptr;
      std::vector<char*> children;
      std::vector<char*> internal_outcomes;
      std::vector<char*> outcomes_from;
      std::vector<char*> outcomes_to;
      std::vector<char*> container_outcomes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->path);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->path, length_);
      offset += length_;
      }
      unsigned children_length = children.size();
      outbuffer[offset++] = (children_length >> 0) & 0xFF;
      outbuffer[offset++] = (children_length >> 8) & 0xFF;
      outbuffer[offset++] = (children_length >> 16) & 0xFF;
      outbuffer[offset++] = (children_length >> 24) & 0xFF;
      for( unsigned i = 0; i < children_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->children[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->children[i], length_);
      offset += length_;
      }
      }
      unsigned internal_outcomes_length = internal_outcomes.size();
      outbuffer[offset++] = (internal_outcomes_length >> 0) & 0xFF;
      outbuffer[offset++] = (internal_outcomes_length >> 8) & 0xFF;
      outbuffer[offset++] = (internal_outcomes_length >> 16) & 0xFF;
      outbuffer[offset++] = (internal_outcomes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < internal_outcomes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->internal_outcomes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->internal_outcomes[i], length_);
      offset += length_;
      }
      }
      unsigned outcomes_from_length = outcomes_from.size();
      outbuffer[offset++] = (outcomes_from_length >> 0) & 0xFF;
      outbuffer[offset++] = (outcomes_from_length >> 8) & 0xFF;
      outbuffer[offset++] = (outcomes_from_length >> 16) & 0xFF;
      outbuffer[offset++] = (outcomes_from_length >> 24) & 0xFF;
      for( unsigned i = 0; i < outcomes_from_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->outcomes_from[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->outcomes_from[i], length_);
      offset += length_;
      }
      }
      unsigned outcomes_to_length = outcomes_to.size();
      outbuffer[offset++] = (outcomes_to_length >> 0) & 0xFF;
      outbuffer[offset++] = (outcomes_to_length >> 8) & 0xFF;
      outbuffer[offset++] = (outcomes_to_length >> 16) & 0xFF;
      outbuffer[offset++] = (outcomes_to_length >> 24) & 0xFF;
      for( unsigned i = 0; i < outcomes_to_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->outcomes_to[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->outcomes_to[i], length_);
      offset += length_;
      }
      }
      unsigned container_outcomes_length = container_outcomes.size();
      outbuffer[offset++] = (container_outcomes_length >> 0) & 0xFF;
      outbuffer[offset++] = (container_outcomes_length >> 8) & 0xFF;
      outbuffer[offset++] = (container_outcomes_length >> 16) & 0xFF;
      outbuffer[offset++] = (container_outcomes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < container_outcomes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->container_outcomes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->container_outcomes[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->path = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned children_length = inbuffer[offset++];
      children_length |= inbuffer[offset++] << 8;
      children_length |= inbuffer[offset++] << 16;
      children_length |= inbuffer[offset++] << 24;
      children.clear();
      children.reserve(children_length);
      for( unsigned i = 0; i < children_length; i++){
      children.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->children.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned internal_outcomes_length = inbuffer[offset++];
      internal_outcomes_length |= inbuffer[offset++] << 8;
      internal_outcomes_length |= inbuffer[offset++] << 16;
      internal_outcomes_length |= inbuffer[offset++] << 24;
      internal_outcomes.clear();
      internal_outcomes.reserve(internal_outcomes_length);
      for( unsigned i = 0; i < internal_outcomes_length; i++){
      internal_outcomes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->internal_outcomes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned outcomes_from_length = inbuffer[offset++];
      outcomes_from_length |= inbuffer[offset++] << 8;
      outcomes_from_length |= inbuffer[offset++] << 16;
      outcomes_from_length |= inbuffer[offset++] << 24;
      outcomes_from.clear();
      outcomes_from.reserve(outcomes_from_length);
      for( unsigned i = 0; i < outcomes_from_length; i++){
      outcomes_from.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->outcomes_from.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned outcomes_to_length = inbuffer[offset++];
      outcomes_to_length |= inbuffer[offset++] << 8;
      outcomes_to_length |= inbuffer[offset++] << 16;
      outcomes_to_length |= inbuffer[offset++] << 24;
      outcomes_to.clear();
      outcomes_to.reserve(outcomes_to_length);
      for( unsigned i = 0; i < outcomes_to_length; i++){
      outcomes_to.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->outcomes_to.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned container_outcomes_length = inbuffer[offset++];
      container_outcomes_length |= inbuffer[offset++] << 8;
      container_outcomes_length |= inbuffer[offset++] << 16;
      container_outcomes_length |= inbuffer[offset++] << 24;
      container_outcomes.clear();
      container_outcomes.reserve(container_outcomes_length);
      for( unsigned i = 0; i < container_outcomes_length; i++){
      container_outcomes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->container_outcomes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "smach_msgs/SmachContainerStructure"; };
    const char * getMD5(){ return "3d3d1e0d0f99779ee9e58101a5dcf7ea"; };

  };

}
#endif