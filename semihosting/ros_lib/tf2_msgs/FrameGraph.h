#ifndef _ROS_SERVICE_FrameGraph_h
#define _ROS_SERVICE_FrameGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tf2_msgs
{

static const char FRAMEGRAPH[] = "tf2_msgs/FrameGraph";

  class FrameGraphRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return FRAMEGRAPH; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FrameGraphResponse : public ros::Msg
  {
    public:
      char * frame_yaml = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->frame_yaml);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_yaml, length_);
      offset += length_;
      }
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
      this->frame_yaml = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return FRAMEGRAPH; };
    const char * getMD5(){ return "437ea58e9463815a0d511c7326b686b0"; };

  };

  class FrameGraph {
    public:
    typedef FrameGraphRequest Request;
    typedef FrameGraphResponse Response;
  };

}
#endif
