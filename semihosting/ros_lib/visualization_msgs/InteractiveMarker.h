#ifndef _ROS_visualization_msgs_InteractiveMarker_h
#define _ROS_visualization_msgs_InteractiveMarker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "visualization_msgs/MenuEntry.h"
#include <vector>
#include "visualization_msgs/InteractiveMarkerControl.h"

namespace visualization_msgs
{

  class InteractiveMarker : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose pose;
      char * name = nullptr;
      char * description = nullptr;
      float scale = 0;
      std::vector<visualization_msgs::MenuEntry> menu_entries;
      std::vector<visualization_msgs::InteractiveMarkerControl> controls;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->description);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_);
      offset += length_;
      }
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->scale;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->scale);
      unsigned menu_entries_length = menu_entries.size();
      outbuffer[offset++] = (menu_entries_length >> 0) & 0xFF;
      outbuffer[offset++] = (menu_entries_length >> 8) & 0xFF;
      outbuffer[offset++] = (menu_entries_length >> 16) & 0xFF;
      outbuffer[offset++] = (menu_entries_length >> 24) & 0xFF;
      for( unsigned i = 0; i < menu_entries_length; i++){
      offset += this->menu_entries[i].serialize(outbuffer + offset);
      }
      unsigned controls_length = controls.size();
      outbuffer[offset++] = (controls_length >> 0) & 0xFF;
      outbuffer[offset++] = (controls_length >> 8) & 0xFF;
      outbuffer[offset++] = (controls_length >> 16) & 0xFF;
      outbuffer[offset++] = (controls_length >> 24) & 0xFF;
      for( unsigned i = 0; i < controls_length; i++){
      offset += this->controls[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
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
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scale = u_.real;
      }
      offset += sizeof(this->scale);
      unsigned menu_entries_length = inbuffer[offset++];
      menu_entries_length |= inbuffer[offset++] << 8;
      menu_entries_length |= inbuffer[offset++] << 16;
      menu_entries_length |= inbuffer[offset++] << 24;
      menu_entries.clear();
      menu_entries.reserve(menu_entries_length);
      for( unsigned i = 0; i < menu_entries_length; i++){
      menu_entries.emplace_back();
      offset += this->menu_entries.back().deserialize(inbuffer + offset);
      }
      unsigned controls_length = inbuffer[offset++];
      controls_length |= inbuffer[offset++] << 8;
      controls_length |= inbuffer[offset++] << 16;
      controls_length |= inbuffer[offset++] << 24;
      controls.clear();
      controls.reserve(controls_length);
      for( unsigned i = 0; i < controls_length; i++){
      controls.emplace_back();
      offset += this->controls.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarker"; };
    const char * getMD5(){ return "311bd5f6cd6a20820ac0ba84315f4e22"; };

  };

}
#endif