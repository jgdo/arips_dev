#ifndef _ROS_SERVICE_NodeletList_h
#define _ROS_SERVICE_NodeletList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace nodelet
{

static const char NODELETLIST[] = "nodelet/NodeletList";

  class NodeletListRequest : public ros::Msg
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

    const char * getType(){ return NODELETLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NodeletListResponse : public ros::Msg
  {
    public:
      std::vector<char*> nodelets;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned nodelets_length = nodelets.size();
      outbuffer[offset++] = (nodelets_length >> 0) & 0xFF;
      outbuffer[offset++] = (nodelets_length >> 8) & 0xFF;
      outbuffer[offset++] = (nodelets_length >> 16) & 0xFF;
      outbuffer[offset++] = (nodelets_length >> 24) & 0xFF;
      for( unsigned i = 0; i < nodelets_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->nodelets[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodelets[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned nodelets_length = inbuffer[offset++];
      nodelets_length |= inbuffer[offset++] << 8;
      nodelets_length |= inbuffer[offset++] << 16;
      nodelets_length |= inbuffer[offset++] << 24;
      nodelets.clear();
      nodelets.reserve(nodelets_length);
      for( unsigned i = 0; i < nodelets_length; i++){
      nodelets.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->nodelets.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return NODELETLIST; };
    const char * getMD5(){ return "99c7b10e794f5600b8030e697e946ca7"; };

  };

  class NodeletList {
    public:
    typedef NodeletListRequest Request;
    typedef NodeletListResponse Response;
  };

}
#endif
