#ifndef _ROS_pr2_msgs_AccelerometerState_h
#define _ROS_pr2_msgs_AccelerometerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include <vector>

namespace pr2_msgs
{

  class AccelerometerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<geometry_msgs::Vector3> samples;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned samples_length = samples.size();
      outbuffer[offset++] = (samples_length >> 0) & 0xFF;
      outbuffer[offset++] = (samples_length >> 8) & 0xFF;
      outbuffer[offset++] = (samples_length >> 16) & 0xFF;
      outbuffer[offset++] = (samples_length >> 24) & 0xFF;
      for( unsigned i = 0; i < samples_length; i++){
      offset += this->samples[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned samples_length = inbuffer[offset++];
      samples_length |= inbuffer[offset++] << 8;
      samples_length |= inbuffer[offset++] << 16;
      samples_length |= inbuffer[offset++] << 24;
      samples.clear();
      samples.reserve(samples_length);
      for( unsigned i = 0; i < samples_length; i++){
      samples.emplace_back();
      offset += this->samples.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/AccelerometerState"; };
    const char * getMD5(){ return "26492e97ed8c13252c4a85592d3e93fd"; };

  };

}
#endif