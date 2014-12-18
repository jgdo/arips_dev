#ifndef _ROS_geometry_msgs_Polygon_h
#define _ROS_geometry_msgs_Polygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"
#include <vector>

namespace geometry_msgs
{

  class Polygon : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::Point32> points;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned points_length = points.size();
      outbuffer[offset++] = (points_length >> 0) & 0xFF;
      outbuffer[offset++] = (points_length >> 8) & 0xFF;
      outbuffer[offset++] = (points_length >> 16) & 0xFF;
      outbuffer[offset++] = (points_length >> 24) & 0xFF;
      for( unsigned i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned points_length = inbuffer[offset++];
      points_length |= inbuffer[offset++] << 8;
      points_length |= inbuffer[offset++] << 16;
      points_length |= inbuffer[offset++] << 24;
      points.clear();
      points.reserve(points_length);
      for( unsigned i = 0; i < points_length; i++){
      points.emplace_back();
      offset += this->points.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Polygon"; };
    const char * getMD5(){ return "cd60a26494a087f577976f0329fa120e"; };

  };

}
#endif