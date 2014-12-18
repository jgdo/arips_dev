#ifndef _ROS_moveit_msgs_ObjectColor_h
#define _ROS_moveit_msgs_ObjectColor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace moveit_msgs
{

  class ObjectColor : public ros::Msg
  {
    public:
      char * id = nullptr;
      std_msgs::ColorRGBA color;

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
      offset += this->color.serialize(outbuffer + offset);
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
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ObjectColor"; };
    const char * getMD5(){ return "ec3bd6f103430e64b2ae706a67d8488e"; };

  };

}
#endif