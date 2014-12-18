#ifndef _ROS_concert_msgs_LinkNode_h
#define _ROS_concert_msgs_LinkNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

  class LinkNode : public ros::Msg
  {
    public:
      char * id = nullptr;
      char * tuple = nullptr;
      int8_t min = 0;
      int8_t max = 0;
      bool force_name_matching = 0;
      enum { UNLIMITED_RESOURCE = -1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->tuple);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tuple, length_);
      offset += length_;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->min;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->min);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->max;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->max);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->force_name_matching;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->force_name_matching);
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
      this->id = (char *)(inbuffer + offset-1);
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
      this->tuple = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->min = u_.real;
      }
      offset += sizeof(this->min);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max = u_.real;
      }
      offset += sizeof(this->max);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force_name_matching = u_.real;
      }
      offset += sizeof(this->force_name_matching);
     return offset;
    }

    const char * getType(){ return "concert_msgs/LinkNode"; };
    const char * getMD5(){ return "8cb53e2248706eb448c74babbdffc381"; };

  };

}
#endif