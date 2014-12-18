#ifndef _ROS_rosgraph_msgs_Log_h
#define _ROS_rosgraph_msgs_Log_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace rosgraph_msgs
{

  class Log : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t level = 0;
      char * name = nullptr;
      char * msg = nullptr;
      char * file = nullptr;
      char * function = nullptr;
      uint32_t line = 0;
      std::vector<char*> topics;
      enum { DEBUG = 1  };
      enum { INFO = 2   };
      enum { WARN = 4   };
      enum { ERROR = 8  };
      enum { FATAL = 16  };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      uint32_t length_ = strlen( (const char*) this->msg);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->file);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->function);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->function, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->line >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line);
      unsigned topics_length = topics.size();
      outbuffer[offset++] = (topics_length >> 0) & 0xFF;
      outbuffer[offset++] = (topics_length >> 8) & 0xFF;
      outbuffer[offset++] = (topics_length >> 16) & 0xFF;
      outbuffer[offset++] = (topics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < topics_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->topics[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_);
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
      this->msg = (char *)(inbuffer + offset-1);
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
      this->file = (char *)(inbuffer + offset-1);
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
      this->function = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->line =  ((uint32_t) (*(inbuffer + offset)));
      this->line |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->line |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->line |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->line);
      unsigned topics_length = inbuffer[offset++];
      topics_length |= inbuffer[offset++] << 8;
      topics_length |= inbuffer[offset++] << 16;
      topics_length |= inbuffer[offset++] << 24;
      topics.clear();
      topics.reserve(topics_length);
      for( unsigned i = 0; i < topics_length; i++){
      topics.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->topics.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "rosgraph_msgs/Log"; };
    const char * getMD5(){ return "acffd30cd6b6de30f120938c17c593fb"; };

  };

}
#endif