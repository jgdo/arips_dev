#ifndef _ROS_concert_msgs_Implementation_h
#define _ROS_concert_msgs_Implementation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/LinkGraph.h"

namespace concert_msgs
{

  class Implementation : public ros::Msg
  {
    public:
      char * name = nullptr;
      concert_msgs::LinkGraph link_graph;
      char * dot_graph = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      offset += this->link_graph.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->dot_graph);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dot_graph, length_);
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
      this->name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->link_graph.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->dot_graph = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/Implementation"; };
    const char * getMD5(){ return "aeb0655c516d030025a8fe13f0998166"; };

  };

}
#endif