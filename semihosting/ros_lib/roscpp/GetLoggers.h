#ifndef _ROS_SERVICE_GetLoggers_h
#define _ROS_SERVICE_GetLoggers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "roscpp/Logger.h"

namespace roscpp
{

static const char GETLOGGERS[] = "roscpp/GetLoggers";

  class GetLoggersRequest : public ros::Msg
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

    const char * getType(){ return GETLOGGERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetLoggersResponse : public ros::Msg
  {
    public:
      std::vector<roscpp::Logger> loggers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned loggers_length = loggers.size();
      outbuffer[offset++] = (loggers_length >> 0) & 0xFF;
      outbuffer[offset++] = (loggers_length >> 8) & 0xFF;
      outbuffer[offset++] = (loggers_length >> 16) & 0xFF;
      outbuffer[offset++] = (loggers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < loggers_length; i++){
      offset += this->loggers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned loggers_length = inbuffer[offset++];
      loggers_length |= inbuffer[offset++] << 8;
      loggers_length |= inbuffer[offset++] << 16;
      loggers_length |= inbuffer[offset++] << 24;
      loggers.clear();
      loggers.reserve(loggers_length);
      for( unsigned i = 0; i < loggers_length; i++){
      loggers.emplace_back();
      offset += this->loggers.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETLOGGERS; };
    const char * getMD5(){ return "32e97e85527d4678a8f9279894bb64b0"; };

  };

  class GetLoggers {
    public:
    typedef GetLoggersRequest Request;
    typedef GetLoggersResponse Response;
  };

}
#endif
