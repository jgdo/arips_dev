#ifndef _ROS_manipulation_msgs_GraspableObjectList_h
#define _ROS_manipulation_msgs_GraspableObjectList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "manipulation_msgs/GraspableObject.h"
#include <vector>
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "shape_msgs/Mesh.h"
#include "geometry_msgs/Pose.h"

namespace manipulation_msgs
{

  class GraspableObjectList : public ros::Msg
  {
    public:
      std::vector<manipulation_msgs::GraspableObject> graspable_objects;
      sensor_msgs::Image image;
      sensor_msgs::CameraInfo camera_info;
      std::vector<shape_msgs::Mesh> meshes;
      geometry_msgs::Pose reference_to_camera;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned graspable_objects_length = graspable_objects.size();
      outbuffer[offset++] = (graspable_objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (graspable_objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (graspable_objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (graspable_objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < graspable_objects_length; i++){
      offset += this->graspable_objects[i].serialize(outbuffer + offset);
      }
      offset += this->image.serialize(outbuffer + offset);
      offset += this->camera_info.serialize(outbuffer + offset);
      unsigned meshes_length = meshes.size();
      outbuffer[offset++] = (meshes_length >> 0) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 8) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 16) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < meshes_length; i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      offset += this->reference_to_camera.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned graspable_objects_length = inbuffer[offset++];
      graspable_objects_length |= inbuffer[offset++] << 8;
      graspable_objects_length |= inbuffer[offset++] << 16;
      graspable_objects_length |= inbuffer[offset++] << 24;
      graspable_objects.clear();
      graspable_objects.reserve(graspable_objects_length);
      for( unsigned i = 0; i < graspable_objects_length; i++){
      graspable_objects.emplace_back();
      offset += this->graspable_objects.back().deserialize(inbuffer + offset);
      }
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->camera_info.deserialize(inbuffer + offset);
      unsigned meshes_length = inbuffer[offset++];
      meshes_length |= inbuffer[offset++] << 8;
      meshes_length |= inbuffer[offset++] << 16;
      meshes_length |= inbuffer[offset++] << 24;
      meshes.clear();
      meshes.reserve(meshes_length);
      for( unsigned i = 0; i < meshes_length; i++){
      meshes.emplace_back();
      offset += this->meshes.back().deserialize(inbuffer + offset);
      }
      offset += this->reference_to_camera.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspableObjectList"; };
    const char * getMD5(){ return "d67571f2982f1b7115de1e0027319109"; };

  };

}
#endif