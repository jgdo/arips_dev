#ifndef _ROS_diagnostic_msgs_DiagnosticStatus_h
#define _ROS_diagnostic_msgs_DiagnosticStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"
#include <vector>

namespace diagnostic_msgs
{

  class DiagnosticStatus : public ros::Msg
  {
    public:
      int8_t level = 0;
      char * name = nullptr;
      char * message = nullptr;
      char * hardware_id = nullptr;
      std::vector<diagnostic_msgs::KeyValue> values;
      enum { OK = 0 };
      enum { WARN = 1 };
      enum { ERROR = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->level;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->level);
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->hardware_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_id, length_);
      offset += length_;
      }
      unsigned values_length = values.size();
      outbuffer[offset++] = (values_length >> 0) & 0xFF;
      outbuffer[offset++] = (values_length >> 8) & 0xFF;
      outbuffer[offset++] = (values_length >> 16) & 0xFF;
      outbuffer[offset++] = (values_length >> 24) & 0xFF;
      for( unsigned i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->level = u_.real;
      }
      offset += sizeof(this->level);
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
      this->message = (char *)(inbuffer + offset-1);
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
      this->hardware_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned values_length = inbuffer[offset++];
      values_length |= inbuffer[offset++] << 8;
      values_length |= inbuffer[offset++] << 16;
      values_length |= inbuffer[offset++] << 24;
      values.clear();
      values.reserve(values_length);
      for( unsigned i = 0; i < values_length; i++){
      values.emplace_back();
      offset += this->values.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "diagnostic_msgs/DiagnosticStatus"; };
    const char * getMD5(){ return "67d15a62edb26e9d52b0f0efa3ef9da7"; };

  };

}
#endif