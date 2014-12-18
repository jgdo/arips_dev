#ifndef _ROS_SERVICE_ListDescription_h
#define _ROS_SERVICE_ListDescription_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/Capability.h"
#include <vector>

namespace multimaster_msgs_fkie
{

static const char LISTDESCRIPTION[] = "multimaster_msgs_fkie/ListDescription";

  class ListDescriptionRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LISTDESCRIPTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListDescriptionResponse : public ros::Msg
  {
    public:
      char * robot_name = nullptr;
      char * robot_type = nullptr;
      std::vector<char*> robot_images;
      char * robot_descr = nullptr;
      std::vector<multimaster_msgs_fkie::Capability> capabilities;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->robot_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->robot_type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_type, length_);
      offset += length_;
      }
      unsigned robot_images_length = robot_images.size();
      outbuffer[offset++] = (robot_images_length >> 0) & 0xFF;
      outbuffer[offset++] = (robot_images_length >> 8) & 0xFF;
      outbuffer[offset++] = (robot_images_length >> 16) & 0xFF;
      outbuffer[offset++] = (robot_images_length >> 24) & 0xFF;
      for( unsigned i = 0; i < robot_images_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->robot_images[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_images[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->robot_descr);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_descr, length_);
      offset += length_;
      }
      unsigned capabilities_length = capabilities.size();
      outbuffer[offset++] = (capabilities_length >> 0) & 0xFF;
      outbuffer[offset++] = (capabilities_length >> 8) & 0xFF;
      outbuffer[offset++] = (capabilities_length >> 16) & 0xFF;
      outbuffer[offset++] = (capabilities_length >> 24) & 0xFF;
      for( unsigned i = 0; i < capabilities_length; i++){
      offset += this->capabilities[i].serialize(outbuffer + offset);
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
      this->robot_name = (char *)(inbuffer + offset-1);
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
      this->robot_type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned robot_images_length = inbuffer[offset++];
      robot_images_length |= inbuffer[offset++] << 8;
      robot_images_length |= inbuffer[offset++] << 16;
      robot_images_length |= inbuffer[offset++] << 24;
      robot_images.clear();
      robot_images.reserve(robot_images_length);
      for( unsigned i = 0; i < robot_images_length; i++){
      robot_images.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->robot_images.back() = (char *)(inbuffer + offset-1);
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
      this->robot_descr = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned capabilities_length = inbuffer[offset++];
      capabilities_length |= inbuffer[offset++] << 8;
      capabilities_length |= inbuffer[offset++] << 16;
      capabilities_length |= inbuffer[offset++] << 24;
      capabilities.clear();
      capabilities.reserve(capabilities_length);
      for( unsigned i = 0; i < capabilities_length; i++){
      capabilities.emplace_back();
      offset += this->capabilities.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return LISTDESCRIPTION; };
    const char * getMD5(){ return "a36ba5a97ce785b9b964aa015b26332b"; };

  };

  class ListDescription {
    public:
    typedef ListDescriptionRequest Request;
    typedef ListDescriptionResponse Response;
  };

}
#endif
