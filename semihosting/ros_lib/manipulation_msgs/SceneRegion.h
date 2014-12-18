#ifndef _ROS_manipulation_msgs_SceneRegion_h
#define _ROS_manipulation_msgs_SceneRegion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include <vector>
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3.h"

namespace manipulation_msgs
{

  class SceneRegion : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 cloud;
      std::vector<int32_t> mask;
      sensor_msgs::Image image;
      sensor_msgs::Image disparity_image;
      sensor_msgs::CameraInfo cam_info;
      geometry_msgs::PoseStamped roi_box_pose;
      geometry_msgs::Vector3 roi_box_dims;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      unsigned mask_length = mask.size();
      outbuffer[offset++] = (mask_length >> 0) & 0xFF;
      outbuffer[offset++] = (mask_length >> 8) & 0xFF;
      outbuffer[offset++] = (mask_length >> 16) & 0xFF;
      outbuffer[offset++] = (mask_length >> 24) & 0xFF;
      for( unsigned i = 0; i < mask_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->mask[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->mask[i]);
      }
      offset += this->image.serialize(outbuffer + offset);
      offset += this->disparity_image.serialize(outbuffer + offset);
      offset += this->cam_info.serialize(outbuffer + offset);
      offset += this->roi_box_pose.serialize(outbuffer + offset);
      offset += this->roi_box_dims.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      unsigned mask_length = inbuffer[offset++];
      mask_length |= inbuffer[offset++] << 8;
      mask_length |= inbuffer[offset++] << 16;
      mask_length |= inbuffer[offset++] << 24;
      mask.clear();
      mask.reserve(mask_length);
      for( unsigned i = 0; i < mask_length; i++){
      mask.emplace_back();
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
      this->mask.back() = u_.real;
      }
      offset += sizeof(this->mask.back());
      }
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->disparity_image.deserialize(inbuffer + offset);
      offset += this->cam_info.deserialize(inbuffer + offset);
      offset += this->roi_box_pose.deserialize(inbuffer + offset);
      offset += this->roi_box_dims.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/SceneRegion"; };
    const char * getMD5(){ return "0a9ab02b19292633619876c9d247690c"; };

  };

}
#endif