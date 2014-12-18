#ifndef _ROS_tf2_msgs_TFMessage_h
#define _ROS_tf2_msgs_TFMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"
#include <vector>

namespace tf2_msgs
{

  class TFMessage : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::TransformStamped> transforms;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned transforms_length = transforms.size();
      outbuffer[offset++] = (transforms_length >> 0) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 8) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 16) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 24) & 0xFF;
      for( unsigned i = 0; i < transforms_length; i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned transforms_length = inbuffer[offset++];
      transforms_length |= inbuffer[offset++] << 8;
      transforms_length |= inbuffer[offset++] << 16;
      transforms_length |= inbuffer[offset++] << 24;
      transforms.clear();
      transforms.reserve(transforms_length);
      for( unsigned i = 0; i < transforms_length; i++){
      transforms.emplace_back();
      offset += this->transforms.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "tf2_msgs/TFMessage"; };
    const char * getMD5(){ return "94810edda583a504dfda3829e70d7eec"; };

  };

}
#endif