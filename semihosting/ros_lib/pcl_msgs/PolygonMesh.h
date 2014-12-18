#ifndef _ROS_pcl_msgs_PolygonMesh_h
#define _ROS_pcl_msgs_PolygonMesh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"
#include "pcl_msgs/Vertices.h"
#include <vector>

namespace pcl_msgs
{

  class PolygonMesh : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sensor_msgs::PointCloud2 cloud;
      std::vector<pcl_msgs::Vertices> polygons;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cloud.serialize(outbuffer + offset);
      unsigned polygons_length = polygons.size();
      outbuffer[offset++] = (polygons_length >> 0) & 0xFF;
      outbuffer[offset++] = (polygons_length >> 8) & 0xFF;
      outbuffer[offset++] = (polygons_length >> 16) & 0xFF;
      outbuffer[offset++] = (polygons_length >> 24) & 0xFF;
      for( unsigned i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cloud.deserialize(inbuffer + offset);
      unsigned polygons_length = inbuffer[offset++];
      polygons_length |= inbuffer[offset++] << 8;
      polygons_length |= inbuffer[offset++] << 16;
      polygons_length |= inbuffer[offset++] << 24;
      polygons.clear();
      polygons.reserve(polygons_length);
      for( unsigned i = 0; i < polygons_length; i++){
      polygons.emplace_back();
      offset += this->polygons.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "pcl_msgs/PolygonMesh"; };
    const char * getMD5(){ return "45a5fc6ad2cde8489600a790acc9a38a"; };

  };

}
#endif