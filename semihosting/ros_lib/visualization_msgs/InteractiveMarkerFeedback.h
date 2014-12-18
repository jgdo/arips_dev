#ifndef _ROS_visualization_msgs_InteractiveMarkerFeedback_h
#define _ROS_visualization_msgs_InteractiveMarkerFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace visualization_msgs
{

  class InteractiveMarkerFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * client_id = nullptr;
      char * marker_name = nullptr;
      char * control_name = nullptr;
      uint8_t event_type = 0;
      geometry_msgs::Pose pose;
      uint32_t menu_entry_id = 0;
      geometry_msgs::Point mouse_point;
      bool mouse_point_valid = 0;
      enum { KEEP_ALIVE =  0 };
      enum { POSE_UPDATE =  1 };
      enum { MENU_SELECT =  2 };
      enum { BUTTON_CLICK =  3 };
      enum { MOUSE_DOWN =  4 };
      enum { MOUSE_UP =  5 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->client_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->client_id, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->marker_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->marker_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->control_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->control_name, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->event_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->event_type);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->menu_entry_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->menu_entry_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->menu_entry_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->menu_entry_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->menu_entry_id);
      offset += this->mouse_point.serialize(outbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->mouse_point_valid;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->mouse_point_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->client_id = (char *)(inbuffer + offset-1);
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
      this->marker_name = (char *)(inbuffer + offset-1);
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
      this->control_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->event_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->event_type);
      offset += this->pose.deserialize(inbuffer + offset);
      this->menu_entry_id =  ((uint32_t) (*(inbuffer + offset)));
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->menu_entry_id);
      offset += this->mouse_point.deserialize(inbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mouse_point_valid = u_.real;
      }
      offset += sizeof(this->mouse_point_valid);
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerFeedback"; };
    const char * getMD5(){ return "ab0f1eee058667e28c19ff3ffc3f4b78"; };

  };

}
#endif