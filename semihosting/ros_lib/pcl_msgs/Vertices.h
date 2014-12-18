#ifndef _ROS_pcl_msgs_Vertices_h
#define _ROS_pcl_msgs_Vertices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace pcl_msgs
{

  class Vertices : public ros::Msg
  {
    public:
      std::vector<uint32_t> vertices;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned vertices_length = vertices.size();
      outbuffer[offset++] = (vertices_length >> 0) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 8) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 16) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 24) & 0xFF;
      for( unsigned i = 0; i < vertices_length; i++){
      *(outbuffer + offset + 0) = (this->vertices[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned vertices_length = inbuffer[offset++];
      vertices_length |= inbuffer[offset++] << 8;
      vertices_length |= inbuffer[offset++] << 16;
      vertices_length |= inbuffer[offset++] << 24;
      vertices.clear();
      vertices.reserve(vertices_length);
      for( unsigned i = 0; i < vertices_length; i++){
      vertices.emplace_back();
      this->vertices.back() =  ((uint32_t) (*(inbuffer + offset)));
      this->vertices.back() |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vertices.back() |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vertices.back() |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vertices.back());
      }
     return offset;
    }

    const char * getType(){ return "pcl_msgs/Vertices"; };
    const char * getMD5(){ return "39bd7b1c23763ddd1b882b97cb7cfe11"; };

  };

}
#endif