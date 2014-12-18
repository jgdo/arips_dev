#ifndef _ROS_shape_msgs_Mesh_h
#define _ROS_shape_msgs_Mesh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "shape_msgs/MeshTriangle.h"
#include <vector>
#include "geometry_msgs/Point.h"

namespace shape_msgs
{

  class Mesh : public ros::Msg
  {
    public:
      std::vector<shape_msgs::MeshTriangle> triangles;
      std::vector<geometry_msgs::Point> vertices;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned triangles_length = triangles.size();
      outbuffer[offset++] = (triangles_length >> 0) & 0xFF;
      outbuffer[offset++] = (triangles_length >> 8) & 0xFF;
      outbuffer[offset++] = (triangles_length >> 16) & 0xFF;
      outbuffer[offset++] = (triangles_length >> 24) & 0xFF;
      for( unsigned i = 0; i < triangles_length; i++){
      offset += this->triangles[i].serialize(outbuffer + offset);
      }
      unsigned vertices_length = vertices.size();
      outbuffer[offset++] = (vertices_length >> 0) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 8) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 16) & 0xFF;
      outbuffer[offset++] = (vertices_length >> 24) & 0xFF;
      for( unsigned i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned triangles_length = inbuffer[offset++];
      triangles_length |= inbuffer[offset++] << 8;
      triangles_length |= inbuffer[offset++] << 16;
      triangles_length |= inbuffer[offset++] << 24;
      triangles.clear();
      triangles.reserve(triangles_length);
      for( unsigned i = 0; i < triangles_length; i++){
      triangles.emplace_back();
      offset += this->triangles.back().deserialize(inbuffer + offset);
      }
      unsigned vertices_length = inbuffer[offset++];
      vertices_length |= inbuffer[offset++] << 8;
      vertices_length |= inbuffer[offset++] << 16;
      vertices_length |= inbuffer[offset++] << 24;
      vertices.clear();
      vertices.reserve(vertices_length);
      for( unsigned i = 0; i < vertices_length; i++){
      vertices.emplace_back();
      offset += this->vertices.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/Mesh"; };
    const char * getMD5(){ return "1ffdae9486cd3316a121c578b47a85cc"; };

  };

}
#endif