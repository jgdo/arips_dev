#ifndef _ROS_SERVICE_StartSolution_h
#define _ROS_SERVICE_StartSolution_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

static const char STARTSOLUTION[] = "concert_msgs/StartSolution";

  class StartSolutionRequest : public ros::Msg
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

    const char * getType(){ return STARTSOLUTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartSolutionResponse : public ros::Msg
  {
    public:
      bool success = 0;
      char * message = nullptr;

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
      {
      uint32_t length_ = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_);
      offset += length_;
      }
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
     return offset;
    }

    const char * getType(){ return STARTSOLUTION; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class StartSolution {
    public:
    typedef StartSolutionRequest Request;
    typedef StartSolutionResponse Response;
  };

}
#endif
