#ifndef _ROS_SERVICE_SetLoggerLevel_h
#define _ROS_SERVICE_SetLoggerLevel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscpp
{

static const char SETLOGGERLEVEL[] = "roscpp/SetLoggerLevel";

  class SetLoggerLevelRequest : public ros::Msg
  {
    public:
      char * logger = nullptr;
      char * level = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->logger);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->logger, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->level);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->level, length_);
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
      this->logger = (char *)(inbuffer + offset-1);
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
      this->level = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SETLOGGERLEVEL; };
    const char * getMD5(){ return "51da076440d78ca1684d36c868df61ea"; };

  };

  class SetLoggerLevelResponse : public ros::Msg
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

    const char * getType(){ return SETLOGGERLEVEL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetLoggerLevel {
    public:
    typedef SetLoggerLevelRequest Request;
    typedef SetLoggerLevelResponse Response;
  };

}
#endif
