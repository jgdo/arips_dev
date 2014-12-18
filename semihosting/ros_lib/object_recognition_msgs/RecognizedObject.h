#ifndef _ROS_object_recognition_msgs_RecognizedObject_h
#define _ROS_object_recognition_msgs_RecognizedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/ObjectType.h"
#include "sensor_msgs/PointCloud2.h"
#include <vector>
#include "shape_msgs/Mesh.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace object_recognition_msgs
{

  class RecognizedObject : public ros::Msg
  {
    public:
      std_msgs::Header header;
      object_recognition_msgs::ObjectType type;
      float confidence = 0;
      std::vector<sensor_msgs::PointCloud2> point_clouds;
      shape_msgs::Mesh bounding_mesh;
      std::vector<geometry_msgs::Point> bounding_contours;
      geometry_msgs::PoseWithCovarianceStamped pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->type.serialize(outbuffer + offset);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->confidence;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->confidence);
      unsigned point_clouds_length = point_clouds.size();
      outbuffer[offset++] = (point_clouds_length >> 0) & 0xFF;
      outbuffer[offset++] = (point_clouds_length >> 8) & 0xFF;
      outbuffer[offset++] = (point_clouds_length >> 16) & 0xFF;
      outbuffer[offset++] = (point_clouds_length >> 24) & 0xFF;
      for( unsigned i = 0; i < point_clouds_length; i++){
      offset += this->point_clouds[i].serialize(outbuffer + offset);
      }
      offset += this->bounding_mesh.serialize(outbuffer + offset);
      unsigned bounding_contours_length = bounding_contours.size();
      outbuffer[offset++] = (bounding_contours_length >> 0) & 0xFF;
      outbuffer[offset++] = (bounding_contours_length >> 8) & 0xFF;
      outbuffer[offset++] = (bounding_contours_length >> 16) & 0xFF;
      outbuffer[offset++] = (bounding_contours_length >> 24) & 0xFF;
      for( unsigned i = 0; i < bounding_contours_length; i++){
      offset += this->bounding_contours[i].serialize(outbuffer + offset);
      }
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->type.deserialize(inbuffer + offset);
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
      this->confidence = u_.real;
      }
      offset += sizeof(this->confidence);
      unsigned point_clouds_length = inbuffer[offset++];
      point_clouds_length |= inbuffer[offset++] << 8;
      point_clouds_length |= inbuffer[offset++] << 16;
      point_clouds_length |= inbuffer[offset++] << 24;
      point_clouds.clear();
      point_clouds.reserve(point_clouds_length);
      for( unsigned i = 0; i < point_clouds_length; i++){
      point_clouds.emplace_back();
      offset += this->point_clouds.back().deserialize(inbuffer + offset);
      }
      offset += this->bounding_mesh.deserialize(inbuffer + offset);
      unsigned bounding_contours_length = inbuffer[offset++];
      bounding_contours_length |= inbuffer[offset++] << 8;
      bounding_contours_length |= inbuffer[offset++] << 16;
      bounding_contours_length |= inbuffer[offset++] << 24;
      bounding_contours.clear();
      bounding_contours.reserve(bounding_contours_length);
      for( unsigned i = 0; i < bounding_contours_length; i++){
      bounding_contours.emplace_back();
      offset += this->bounding_contours.back().deserialize(inbuffer + offset);
      }
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/RecognizedObject"; };
    const char * getMD5(){ return "f92c4cb29ba11f26c5f7219de97e900d"; };

  };

}
#endif