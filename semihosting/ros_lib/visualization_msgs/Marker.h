#ifndef _ROS_visualization_msgs_Marker_h
#define _ROS_visualization_msgs_Marker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/ColorRGBA.h"
#include "ros/duration.h"
#include "geometry_msgs/Point.h"
#include <vector>

namespace visualization_msgs
{

  class Marker : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * ns = nullptr;
      int32_t id = 0;
      int32_t type = 0;
      int32_t action = 0;
      geometry_msgs::Pose pose;
      geometry_msgs::Vector3 scale;
      std_msgs::ColorRGBA color;
      ros::Duration lifetime;
      bool frame_locked = 0;
      std::vector<geometry_msgs::Point> points;
      std::vector<std_msgs::ColorRGBA> colors;
      char * text = nullptr;
      char * mesh_resource = nullptr;
      bool mesh_use_embedded_materials = 0;
      enum { ARROW = 0 };
      enum { CUBE = 1 };
      enum { SPHERE = 2 };
      enum { CYLINDER = 3 };
      enum { LINE_STRIP = 4 };
      enum { LINE_LIST = 5 };
      enum { CUBE_LIST = 6 };
      enum { SPHERE_LIST = 7 };
      enum { POINTS = 8 };
      enum { TEXT_VIEW_FACING = 9 };
      enum { MESH_RESOURCE = 10 };
      enum { TRIANGLE_LIST = 11 };
      enum { ADD = 0 };
      enum { MODIFY = 0 };
      enum { DELETE = 2 };

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
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->scale.serialize(outbuffer + offset);
      offset += this->color.serialize(outbuffer + offset);
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
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->frame_locked;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->frame_locked);
      unsigned points_length = points.size();
      outbuffer[offset++] = (points_length >> 0) & 0xFF;
      outbuffer[offset++] = (points_length >> 8) & 0xFF;
      outbuffer[offset++] = (points_length >> 16) & 0xFF;
      outbuffer[offset++] = (points_length >> 24) & 0xFF;
      for( unsigned i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      unsigned colors_length = colors.size();
      outbuffer[offset++] = (colors_length >> 0) & 0xFF;
      outbuffer[offset++] = (colors_length >> 8) & 0xFF;
      outbuffer[offset++] = (colors_length >> 16) & 0xFF;
      outbuffer[offset++] = (colors_length >> 24) & 0xFF;
      for( unsigned i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      {
      uint32_t length_ = strlen( (const char*) this->text);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->mesh_resource);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mesh_resource, length_);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->mesh_use_embedded_materials;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->mesh_use_embedded_materials);
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
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->scale.deserialize(inbuffer + offset);
      offset += this->color.deserialize(inbuffer + offset);
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
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->frame_locked = u_.real;
      }
      offset += sizeof(this->frame_locked);
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
      unsigned colors_length = inbuffer[offset++];
      colors_length |= inbuffer[offset++] << 8;
      colors_length |= inbuffer[offset++] << 16;
      colors_length |= inbuffer[offset++] << 24;
      colors.clear();
      colors.reserve(colors_length);
      for( unsigned i = 0; i < colors_length; i++){
      colors.emplace_back();
      offset += this->colors.back().deserialize(inbuffer + offset);
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->text = (char *)(inbuffer + offset-1);
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
      this->mesh_resource = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mesh_use_embedded_materials = u_.real;
      }
      offset += sizeof(this->mesh_use_embedded_materials);
     return offset;
    }

    const char * getType(){ return "visualization_msgs/Marker"; };
    const char * getMD5(){ return "18326976df9d29249efc939e00342cde"; };

  };

}
#endif