#ifndef _ROS_ar_track_alvar_AlvarMarkers_h
#define _ROS_ar_track_alvar_AlvarMarkers_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ar_track_alvar/AlvarMarker.h"
#include <vector>

namespace ar_track_alvar
{

  class AlvarMarkers : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<ar_track_alvar::AlvarMarker> markers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "ar_track_alvar/AlvarMarkers"; };
    const char * getMD5(){ return "943fe17bfb0b4ea7890368d0b25ad0ad"; };

  };

}
#endif