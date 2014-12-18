#ifndef _ROS_gateway_msgs_RemoteRule_h
#define _ROS_gateway_msgs_RemoteRule_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gateway_msgs/Rule.h"

namespace gateway_msgs
{

  class RemoteRule : public ros::Msg
  {
    public:
      char * gateway = nullptr;
      gateway_msgs::Rule rule;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->gateway);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gateway, length_);
      offset += length_;
      }
      offset += this->rule.serialize(outbuffer + offset);
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
      this->gateway = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->rule.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "gateway_msgs/RemoteRule"; };
    const char * getMD5(){ return "14f4c5aaf33b32b22c50fd514747f99f"; };

  };

}
#endif