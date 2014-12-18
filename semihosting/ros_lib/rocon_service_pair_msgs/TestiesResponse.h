#ifndef _ROS_rocon_service_pair_msgs_TestiesResponse_h
#define _ROS_rocon_service_pair_msgs_TestiesResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"

namespace rocon_service_pair_msgs
{

  class TestiesResponse : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      char * data = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
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
      offset += this->id.deserialize(inbuffer + offset);
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

    const char * getType(){ return "rocon_service_pair_msgs/TestiesResponse"; };
    const char * getMD5(){ return "f2e0bb16a22dc66826bb64ac8b44aeb3"; };

  };

}
#endif