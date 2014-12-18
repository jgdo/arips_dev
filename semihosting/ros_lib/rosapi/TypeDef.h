#ifndef _ROS_rosapi_TypeDef_h
#define _ROS_rosapi_TypeDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

  class TypeDef : public ros::Msg
  {
    public:
      char * type = nullptr;
      std::vector<char*> fieldnames;
      std::vector<char*> fieldtypes;
      std::vector<int32_t> fieldarraylen;
      std::vector<char*> examples;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_);
      offset += length_;
      }
      unsigned fieldnames_length = fieldnames.size();
      outbuffer[offset++] = (fieldnames_length >> 0) & 0xFF;
      outbuffer[offset++] = (fieldnames_length >> 8) & 0xFF;
      outbuffer[offset++] = (fieldnames_length >> 16) & 0xFF;
      outbuffer[offset++] = (fieldnames_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fieldnames_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->fieldnames[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fieldnames[i], length_);
      offset += length_;
      }
      }
      unsigned fieldtypes_length = fieldtypes.size();
      outbuffer[offset++] = (fieldtypes_length >> 0) & 0xFF;
      outbuffer[offset++] = (fieldtypes_length >> 8) & 0xFF;
      outbuffer[offset++] = (fieldtypes_length >> 16) & 0xFF;
      outbuffer[offset++] = (fieldtypes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fieldtypes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->fieldtypes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fieldtypes[i], length_);
      offset += length_;
      }
      }
      unsigned fieldarraylen_length = fieldarraylen.size();
      outbuffer[offset++] = (fieldarraylen_length >> 0) & 0xFF;
      outbuffer[offset++] = (fieldarraylen_length >> 8) & 0xFF;
      outbuffer[offset++] = (fieldarraylen_length >> 16) & 0xFF;
      outbuffer[offset++] = (fieldarraylen_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fieldarraylen_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->fieldarraylen[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->fieldarraylen[i]);
      }
      unsigned examples_length = examples.size();
      outbuffer[offset++] = (examples_length >> 0) & 0xFF;
      outbuffer[offset++] = (examples_length >> 8) & 0xFF;
      outbuffer[offset++] = (examples_length >> 16) & 0xFF;
      outbuffer[offset++] = (examples_length >> 24) & 0xFF;
      for( unsigned i = 0; i < examples_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->examples[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->examples[i], length_);
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
      this->type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned fieldnames_length = inbuffer[offset++];
      fieldnames_length |= inbuffer[offset++] << 8;
      fieldnames_length |= inbuffer[offset++] << 16;
      fieldnames_length |= inbuffer[offset++] << 24;
      fieldnames.clear();
      fieldnames.reserve(fieldnames_length);
      for( unsigned i = 0; i < fieldnames_length; i++){
      fieldnames.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->fieldnames.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned fieldtypes_length = inbuffer[offset++];
      fieldtypes_length |= inbuffer[offset++] << 8;
      fieldtypes_length |= inbuffer[offset++] << 16;
      fieldtypes_length |= inbuffer[offset++] << 24;
      fieldtypes.clear();
      fieldtypes.reserve(fieldtypes_length);
      for( unsigned i = 0; i < fieldtypes_length; i++){
      fieldtypes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->fieldtypes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned fieldarraylen_length = inbuffer[offset++];
      fieldarraylen_length |= inbuffer[offset++] << 8;
      fieldarraylen_length |= inbuffer[offset++] << 16;
      fieldarraylen_length |= inbuffer[offset++] << 24;
      fieldarraylen.clear();
      fieldarraylen.reserve(fieldarraylen_length);
      for( unsigned i = 0; i < fieldarraylen_length; i++){
      fieldarraylen.emplace_back();
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
      this->fieldarraylen.back() = u_.real;
      }
      offset += sizeof(this->fieldarraylen.back());
      }
      unsigned examples_length = inbuffer[offset++];
      examples_length |= inbuffer[offset++] << 8;
      examples_length |= inbuffer[offset++] << 16;
      examples_length |= inbuffer[offset++] << 24;
      examples.clear();
      examples.reserve(examples_length);
      for( unsigned i = 0; i < examples_length; i++){
      examples.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->examples.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "rosapi/TypeDef"; };
    const char * getMD5(){ return "bd8529b0edb168fde8dd58032743f1f7"; };

  };

}
#endif