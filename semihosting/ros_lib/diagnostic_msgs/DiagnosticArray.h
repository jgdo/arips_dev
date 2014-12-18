#ifndef _ROS_diagnostic_msgs_DiagnosticArray_h
#define _ROS_diagnostic_msgs_DiagnosticArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "diagnostic_msgs/DiagnosticStatus.h"
#include <vector>

namespace diagnostic_msgs
{

  class DiagnosticArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<diagnostic_msgs::DiagnosticStatus> status;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "diagnostic_msgs/DiagnosticArray"; };
    const char * getMD5(){ return "3cfbeff055e708a24c3d946a5c8139cd"; };

  };

}
#endif