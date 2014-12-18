#ifndef _ROS_SERVICE_Nodes_h
#define _ROS_SERVICE_Nodes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosapi
{

static const char NODES[] = "rosapi/Nodes";

  class NodesRequest : public ros::Msg
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

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NodesResponse : public ros::Msg
  {
    public:
      std::vector<char*> nodes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned nodes_length = nodes.size();
      outbuffer[offset++] = (nodes_length >> 0) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 8) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 16) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < nodes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->nodes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned nodes_length = inbuffer[offset++];
      nodes_length |= inbuffer[offset++] << 8;
      nodes_length |= inbuffer[offset++] << 16;
      nodes_length |= inbuffer[offset++] << 24;
      nodes.clear();
      nodes.reserve(nodes_length);
      for( unsigned i = 0; i < nodes_length; i++){
      nodes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->nodes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "3d07bfda1268b4f76b16b7ba8a82665d"; };

  };

  class Nodes {
    public:
    typedef NodesRequest Request;
    typedef NodesResponse Response;
  };

}
#endif
