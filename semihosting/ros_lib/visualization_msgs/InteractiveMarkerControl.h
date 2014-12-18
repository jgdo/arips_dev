#ifndef _ROS_visualization_msgs_InteractiveMarkerControl_h
#define _ROS_visualization_msgs_InteractiveMarkerControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "visualization_msgs/Marker.h"
#include <vector>

namespace visualization_msgs
{

  class InteractiveMarkerControl : public ros::Msg
  {
    public:
      char * name = nullptr;
      geometry_msgs::Quaternion orientation;
      uint8_t orientation_mode = 0;
      uint8_t interaction_mode = 0;
      bool always_visible = 0;
      std::vector<visualization_msgs::Marker> markers;
      bool independent_marker_orientation = 0;
      char * description = nullptr;
      enum { INHERIT =  0 };
      enum { FIXED =  1 };
      enum { VIEW_FACING =  2 };
      enum { NONE =  0 };
      enum { MENU =  1 };
      enum { BUTTON =  2 };
      enum { MOVE_AXIS =  3 };
      enum { MOVE_PLANE =  4 };
      enum { ROTATE_AXIS =  5 };
      enum { MOVE_ROTATE =  6 };
      enum { MOVE_3D =  7 };
      enum { ROTATE_3D =  8 };
      enum { MOVE_ROTATE_3D =  9 };

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
      offset += this->orientation.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->orientation_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->orientation_mode);
      *(outbuffer + offset + 0) = (this->interaction_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interaction_mode);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->always_visible;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->always_visible);
      unsigned markers_length = markers.size();
      outbuffer[offset++] = (markers_length >> 0) & 0xFF;
      outbuffer[offset++] = (markers_length >> 8) & 0xFF;
      outbuffer[offset++] = (markers_length >> 16) & 0xFF;
      outbuffer[offset++] = (markers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->independent_marker_orientation;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->independent_marker_orientation);
      {
      uint32_t length_ = strlen( (const char*) this->description);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_);
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
      offset += this->orientation.deserialize(inbuffer + offset);
      this->orientation_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->orientation_mode);
      this->interaction_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interaction_mode);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->always_visible = u_.real;
      }
      offset += sizeof(this->always_visible);
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
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->independent_marker_orientation = u_.real;
      }
      offset += sizeof(this->independent_marker_orientation);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerControl"; };
    const char * getMD5(){ return "e3a939c98cdd4f709d8e1dec2a9c3f37"; };

  };

}
#endif