#ifndef _ROS_visualization_msgs_InteractiveMarkerUpdate_h
#define _ROS_visualization_msgs_InteractiveMarkerUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"
#include <vector>
#include "visualization_msgs/InteractiveMarkerPose.h"

namespace visualization_msgs
{

  class InteractiveMarkerUpdate : public ros::Msg
  {
    public:
      char * server_id = nullptr;
      uint64_t seq_num = 0;
      uint8_t type = 0;
      std::vector<visualization_msgs::InteractiveMarker> markers;
      std::vector<visualization_msgs::InteractiveMarkerPose> poses;
      std::vector<char*> erases;
      enum { KEEP_ALIVE =  0 };
      enum { UPDATE =  1 };

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
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      unsigned markers_length = markers.size();
      outbuffer[offset++] = (markers_length >> 0) & 0xFF;
      outbuffer[offset++] = (markers_length >> 8) & 0xFF;
      outbuffer[offset++] = (markers_length >> 16) & 0xFF;
      outbuffer[offset++] = (markers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      unsigned poses_length = poses.size();
      outbuffer[offset++] = (poses_length >> 0) & 0xFF;
      outbuffer[offset++] = (poses_length >> 8) & 0xFF;
      outbuffer[offset++] = (poses_length >> 16) & 0xFF;
      outbuffer[offset++] = (poses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      unsigned erases_length = erases.size();
      outbuffer[offset++] = (erases_length >> 0) & 0xFF;
      outbuffer[offset++] = (erases_length >> 8) & 0xFF;
      outbuffer[offset++] = (erases_length >> 16) & 0xFF;
      outbuffer[offset++] = (erases_length >> 24) & 0xFF;
      for( unsigned i = 0; i < erases_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->erases[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->erases[i], length_);
      offset += length_;
      }
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
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
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
      unsigned poses_length = inbuffer[offset++];
      poses_length |= inbuffer[offset++] << 8;
      poses_length |= inbuffer[offset++] << 16;
      poses_length |= inbuffer[offset++] << 24;
      poses.clear();
      poses.reserve(poses_length);
      for( unsigned i = 0; i < poses_length; i++){
      poses.emplace_back();
      offset += this->poses.back().deserialize(inbuffer + offset);
      }
      unsigned erases_length = inbuffer[offset++];
      erases_length |= inbuffer[offset++] << 8;
      erases_length |= inbuffer[offset++] << 16;
      erases_length |= inbuffer[offset++] << 24;
      erases.clear();
      erases.reserve(erases_length);
      for( unsigned i = 0; i < erases_length; i++){
      erases.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->erases.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerUpdate"; };
    const char * getMD5(){ return "83e22f99d3b31fde725e0a338200e036"; };

  };

}
#endif