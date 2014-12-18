#ifndef _ROS_SERVICE_SelfTest_h
#define _ROS_SERVICE_SelfTest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "diagnostic_msgs/DiagnosticStatus.h"

namespace diagnostic_msgs
{

static const char SELFTEST[] = "diagnostic_msgs/SelfTest";

  class SelfTestRequest : public ros::Msg
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

    const char * getType(){ return SELFTEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SelfTestResponse : public ros::Msg
  {
    public:
      char * id = nullptr;
      int8_t passed = 0;
      std::vector<diagnostic_msgs::DiagnosticStatus> status;

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
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->passed;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->passed);
      unsigned status_length = status.size();
      outbuffer[offset++] = (status_length >> 0) & 0xFF;
      outbuffer[offset++] = (status_length >> 8) & 0xFF;
      outbuffer[offset++] = (status_length >> 16) & 0xFF;
      outbuffer[offset++] = (status_length >> 24) & 0xFF;
      for( unsigned i = 0; i < status_length; i++){
      offset += this->status[i].serialize(outbuffer + offset);
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
      this->id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passed = u_.real;
      }
      offset += sizeof(this->passed);
      unsigned status_length = inbuffer[offset++];
      status_length |= inbuffer[offset++] << 8;
      status_length |= inbuffer[offset++] << 16;
      status_length |= inbuffer[offset++] << 24;
      status.clear();
      status.reserve(status_length);
      for( unsigned i = 0; i < status_length; i++){
      status.emplace_back();
      offset += this->status.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return SELFTEST; };
    const char * getMD5(){ return "74c9372c870a76da4fc2b3973978b898"; };

  };

  class SelfTest {
    public:
    typedef SelfTestRequest Request;
    typedef SelfTestResponse Response;
  };

}
#endif
