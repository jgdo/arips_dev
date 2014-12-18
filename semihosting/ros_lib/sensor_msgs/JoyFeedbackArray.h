#ifndef _ROS_sensor_msgs_JoyFeedbackArray_h
#define _ROS_sensor_msgs_JoyFeedbackArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JoyFeedback.h"
#include <vector>

namespace sensor_msgs
{

  class JoyFeedbackArray : public ros::Msg
  {
    public:
      std::vector<sensor_msgs::JoyFeedback> array;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned array_length = array.size();
      outbuffer[offset++] = (array_length >> 0) & 0xFF;
      outbuffer[offset++] = (array_length >> 8) & 0xFF;
      outbuffer[offset++] = (array_length >> 16) & 0xFF;
      outbuffer[offset++] = (array_length >> 24) & 0xFF;
      for( unsigned i = 0; i < array_length; i++){
      offset += this->array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned array_length = inbuffer[offset++];
      array_length |= inbuffer[offset++] << 8;
      array_length |= inbuffer[offset++] << 16;
      array_length |= inbuffer[offset++] << 24;
      array.clear();
      array.reserve(array_length);
      for( unsigned i = 0; i < array_length; i++){
      array.emplace_back();
      offset += this->array.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/JoyFeedbackArray"; };
    const char * getMD5(){ return "cde5730a895b1fc4dee6f91b754b213d"; };

  };

}
#endif