#ifndef _ROS_moveit_msgs_AllowedCollisionMatrix_h
#define _ROS_moveit_msgs_AllowedCollisionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "moveit_msgs/AllowedCollisionEntry.h"

namespace moveit_msgs
{

  class AllowedCollisionMatrix : public ros::Msg
  {
    public:
      std::vector<char*> entry_names;
      std::vector<moveit_msgs::AllowedCollisionEntry> entry_values;
      std::vector<char*> default_entry_names;
      std::vector<bool> default_entry_values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned entry_names_length = entry_names.size();
      outbuffer[offset++] = (entry_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (entry_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (entry_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (entry_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < entry_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->entry_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->entry_names[i], length_);
      offset += length_;
      }
      }
      unsigned entry_values_length = entry_values.size();
      outbuffer[offset++] = (entry_values_length >> 0) & 0xFF;
      outbuffer[offset++] = (entry_values_length >> 8) & 0xFF;
      outbuffer[offset++] = (entry_values_length >> 16) & 0xFF;
      outbuffer[offset++] = (entry_values_length >> 24) & 0xFF;
      for( unsigned i = 0; i < entry_values_length; i++){
      offset += this->entry_values[i].serialize(outbuffer + offset);
      }
      unsigned default_entry_names_length = default_entry_names.size();
      outbuffer[offset++] = (default_entry_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (default_entry_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (default_entry_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (default_entry_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < default_entry_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->default_entry_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->default_entry_names[i], length_);
      offset += length_;
      }
      }
      unsigned default_entry_values_length = default_entry_values.size();
      outbuffer[offset++] = (default_entry_values_length >> 0) & 0xFF;
      outbuffer[offset++] = (default_entry_values_length >> 8) & 0xFF;
      outbuffer[offset++] = (default_entry_values_length >> 16) & 0xFF;
      outbuffer[offset++] = (default_entry_values_length >> 24) & 0xFF;
      for( unsigned i = 0; i < default_entry_values_length; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->default_entry_values[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->default_entry_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned entry_names_length = inbuffer[offset++];
      entry_names_length |= inbuffer[offset++] << 8;
      entry_names_length |= inbuffer[offset++] << 16;
      entry_names_length |= inbuffer[offset++] << 24;
      entry_names.clear();
      entry_names.reserve(entry_names_length);
      for( unsigned i = 0; i < entry_names_length; i++){
      entry_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->entry_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned entry_values_length = inbuffer[offset++];
      entry_values_length |= inbuffer[offset++] << 8;
      entry_values_length |= inbuffer[offset++] << 16;
      entry_values_length |= inbuffer[offset++] << 24;
      entry_values.clear();
      entry_values.reserve(entry_values_length);
      for( unsigned i = 0; i < entry_values_length; i++){
      entry_values.emplace_back();
      offset += this->entry_values.back().deserialize(inbuffer + offset);
      }
      unsigned default_entry_names_length = inbuffer[offset++];
      default_entry_names_length |= inbuffer[offset++] << 8;
      default_entry_names_length |= inbuffer[offset++] << 16;
      default_entry_names_length |= inbuffer[offset++] << 24;
      default_entry_names.clear();
      default_entry_names.reserve(default_entry_names_length);
      for( unsigned i = 0; i < default_entry_names_length; i++){
      default_entry_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->default_entry_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned default_entry_values_length = inbuffer[offset++];
      default_entry_values_length |= inbuffer[offset++] << 8;
      default_entry_values_length |= inbuffer[offset++] << 16;
      default_entry_values_length |= inbuffer[offset++] << 24;
      default_entry_values.clear();
      default_entry_values.reserve(default_entry_values_length);
      for( unsigned i = 0; i < default_entry_values_length; i++){
      default_entry_values.emplace_back();
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->default_entry_values.back() = u_.real;
      }
      offset += sizeof(this->default_entry_values.back());
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionMatrix"; };
    const char * getMD5(){ return "aedce13587eef0d79165a075659c1879"; };

  };

}
#endif