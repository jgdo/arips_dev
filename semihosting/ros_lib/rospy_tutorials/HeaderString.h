#ifndef _ROS_rospy_tutorials_HeaderString_h
#define _ROS_rospy_tutorials_HeaderString_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rospy_tutorials
{

  class HeaderString : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * data = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->data);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "rospy_tutorials/HeaderString"; };
    const char * getMD5(){ return "c99a9440709e4d4a9716d55b8270d5e7"; };

  };

}
#endif