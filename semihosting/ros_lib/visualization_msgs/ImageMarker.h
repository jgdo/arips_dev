#ifndef _ROS_visualization_msgs_ImageMarker_h
#define _ROS_visualization_msgs_ImageMarker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/ColorRGBA.h"
#include "ros/duration.h"
#include <vector>

namespace visualization_msgs
{

  class ImageMarker : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * ns = nullptr;
      int32_t id = 0;
      int32_t type = 0;
      int32_t action = 0;
      geometry_msgs::Point position;
      float scale = 0;
      std_msgs::ColorRGBA outline_color;
      uint8_t filled = 0;
      std_msgs::ColorRGBA fill_color;
      ros::Duration lifetime;
      std::vector<geometry_msgs::Point> points;
      std::vector<std_msgs::ColorRGBA> outline_colors;
      enum { CIRCLE = 0 };
      enum { LINE_STRIP = 1 };
      enum { LINE_LIST = 2 };
      enum { POLYGON = 3 };
      enum { POINTS = 4 };
      enum { ADD = 0 };
      enum { REMOVE = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->ns);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ns, length_);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->id);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->type;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->type);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->action;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->action);
      offset += this->position.serialize(outbuffer + offset);
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
      offset += this->outline_color.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->filled >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filled);
      offset += this->fill_color.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lifetime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.sec);
      *(outbuffer + offset + 0) = (this->lifetime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.nsec);
      unsigned points_length = points.size();
      outbuffer[offset++] = (points_length >> 0) & 0xFF;
      outbuffer[offset++] = (points_length >> 8) & 0xFF;
      outbuffer[offset++] = (points_length >> 16) & 0xFF;
      outbuffer[offset++] = (points_length >> 24) & 0xFF;
      for( unsigned i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      unsigned outline_colors_length = outline_colors.size();
      outbuffer[offset++] = (outline_colors_length >> 0) & 0xFF;
      outbuffer[offset++] = (outline_colors_length >> 8) & 0xFF;
      outbuffer[offset++] = (outline_colors_length >> 16) & 0xFF;
      outbuffer[offset++] = (outline_colors_length >> 24) & 0xFF;
      for( unsigned i = 0; i < outline_colors_length; i++){
      offset += this->outline_colors[i].serialize(outbuffer + offset);
      }
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
      this->ns = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_.real;
      }
      offset += sizeof(this->id);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_.real;
      }
      offset += sizeof(this->type);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_.real;
      }
      offset += sizeof(this->action);
      offset += this->position.deserialize(inbuffer + offset);
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
      offset += this->outline_color.deserialize(inbuffer + offset);
      this->filled =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->filled);
      offset += this->fill_color.deserialize(inbuffer + offset);
      this->lifetime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.sec);
      this->lifetime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.nsec);
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
      unsigned outline_colors_length = inbuffer[offset++];
      outline_colors_length |= inbuffer[offset++] << 8;
      outline_colors_length |= inbuffer[offset++] << 16;
      outline_colors_length |= inbuffer[offset++] << 24;
      outline_colors.clear();
      outline_colors.reserve(outline_colors_length);
      for( unsigned i = 0; i < outline_colors_length; i++){
      outline_colors.emplace_back();
      offset += this->outline_colors.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/ImageMarker"; };
    const char * getMD5(){ return "1de93c67ec8858b831025a08fbf1b35c"; };

  };

}
#endif