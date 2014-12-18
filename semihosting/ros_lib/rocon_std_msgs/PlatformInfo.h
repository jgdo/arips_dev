#ifndef _ROS_rocon_std_msgs_PlatformInfo_h
#define _ROS_rocon_std_msgs_PlatformInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"

namespace rocon_std_msgs
{

  class PlatformInfo : public ros::Msg
  {
    public:
      char * uri = nullptr;
      char * version = nullptr;
      rocon_std_msgs::Icon icon;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->uri);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->version);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_);
      offset += length_;
      }
      offset += this->icon.serialize(outbuffer + offset);
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
      this->uri = (char *)(inbuffer + offset-1);
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
      this->version = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->icon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/PlatformInfo"; };
    const char * getMD5(){ return "ffe7bd3c68cda016b708f36a9d12b09e"; };

  };

}
#endif