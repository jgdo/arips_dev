#ifndef _ROS_visualization_msgs_InteractiveMarkerInit_h
#define _ROS_visualization_msgs_InteractiveMarkerInit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"
#include <vector>

namespace visualization_msgs
{

  class InteractiveMarkerInit : public ros::Msg
  {
    public:
      char * server_id = nullptr;
      uint64_t seq_num = 0;
      std::vector<visualization_msgs::InteractiveMarker> markers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->server_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->server_id, length_);
      offset += length_;
      }
      {
      union {
        uint64_t real;
        uint32_t base;
      } u_;
      u_.real = this->seq_num;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->seq_num);
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
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->server_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        uint64_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq_num = u_.real;
      }
      offset += sizeof(this->seq_num);
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

    const char * getType(){ return "visualization_msgs/InteractiveMarkerInit"; };
    const char * getMD5(){ return "aa2f1dcea79533d1710675195653028d"; };

  };

}
#endif