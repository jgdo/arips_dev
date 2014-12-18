#ifndef _ROS_object_recognition_msgs_Table_h
#define _ROS_object_recognition_msgs_Table_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include <vector>

namespace object_recognition_msgs
{

  class Table : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose pose;
      std::vector<geometry_msgs::Point> convex_hull;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      unsigned convex_hull_length = convex_hull.size();
      outbuffer[offset++] = (convex_hull_length >> 0) & 0xFF;
      outbuffer[offset++] = (convex_hull_length >> 8) & 0xFF;
      outbuffer[offset++] = (convex_hull_length >> 16) & 0xFF;
      outbuffer[offset++] = (convex_hull_length >> 24) & 0xFF;
      for( unsigned i = 0; i < convex_hull_length; i++){
      offset += this->convex_hull[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      unsigned convex_hull_length = inbuffer[offset++];
      convex_hull_length |= inbuffer[offset++] << 8;
      convex_hull_length |= inbuffer[offset++] << 16;
      convex_hull_length |= inbuffer[offset++] << 24;
      convex_hull.clear();
      convex_hull.reserve(convex_hull_length);
      for( unsigned i = 0; i < convex_hull_length; i++){
      convex_hull.emplace_back();
      offset += this->convex_hull.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/Table"; };
    const char * getMD5(){ return "39efebc7d51e44bd2d72f2df6c7823a2"; };

  };

}
#endif