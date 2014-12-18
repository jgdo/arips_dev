#ifndef _ROS_visualization_msgs_MarkerArray_h
#define _ROS_visualization_msgs_MarkerArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/Marker.h"
#include <vector>

namespace visualization_msgs
{

  class MarkerArray : public ros::Msg
  {
    public:
      std::vector<visualization_msgs::Marker> markers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned markers_length = markers.size();
      outbuffer[offset++] = (markers_length >> 0) & 0xFF;
      outbuffer[offset++] = (markers_length >> 8) & 0xFF;
      outbuffer[offset++] = (markers_length >> 16) & 0xFF;
      outbuffer[offset++] = (markers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned markers_length = inbuffer[offset++];
      markers_length |= inbuffer[offset++] << 8;
      markers_length |= inbuffer[offset++] << 16;
      markers_length |= inbuffer[offset++] << 24;
      markers.clear();
      markers.reserve(markers_length);
      for( unsigned i = 0; i < markers_length; i++){
      markers.emplace_back();
      offset += this->markers.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/MarkerArray"; };
    const char * getMD5(){ return "90da67007c26525f655c1c269094e39f"; };

  };

}
#endif