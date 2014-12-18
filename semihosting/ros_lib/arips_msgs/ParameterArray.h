#ifndef _ROS_arips_msgs_ParameterArray_h
#define _ROS_arips_msgs_ParameterArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_msgs/Parameter.h"
#include <vector>

namespace arips_msgs
{

  class ParameterArray : public ros::Msg
  {
    public:
      std::vector<arips_msgs::Parameter> parameters;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned parameters_length = parameters.size();
      outbuffer[offset++] = (parameters_length >> 0) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 8) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 16) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 24) & 0xFF;
      for( unsigned i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned parameters_length = inbuffer[offset++];
      parameters_length |= inbuffer[offset++] << 8;
      parameters_length |= inbuffer[offset++] << 16;
      parameters_length |= inbuffer[offset++] << 24;
      parameters.clear();
      parameters.reserve(parameters_length);
      for( unsigned i = 0; i < parameters_length; i++){
      parameters.emplace_back();
      offset += this->parameters.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/ParameterArray"; };
    const char * getMD5(){ return "c4b54e13b7c18e2c13c38c7a12d418c2"; };

  };

}
#endif