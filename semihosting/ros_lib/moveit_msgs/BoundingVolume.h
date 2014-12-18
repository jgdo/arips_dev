#ifndef _ROS_moveit_msgs_BoundingVolume_h
#define _ROS_moveit_msgs_BoundingVolume_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "shape_msgs/SolidPrimitive.h"
#include <vector>
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"

namespace moveit_msgs
{

  class BoundingVolume : public ros::Msg
  {
    public:
      std::vector<shape_msgs::SolidPrimitive> primitives;
      std::vector<geometry_msgs::Pose> primitive_poses;
      std::vector<shape_msgs::Mesh> meshes;
      std::vector<geometry_msgs::Pose> mesh_poses;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned primitives_length = primitives.size();
      outbuffer[offset++] = (primitives_length >> 0) & 0xFF;
      outbuffer[offset++] = (primitives_length >> 8) & 0xFF;
      outbuffer[offset++] = (primitives_length >> 16) & 0xFF;
      outbuffer[offset++] = (primitives_length >> 24) & 0xFF;
      for( unsigned i = 0; i < primitives_length; i++){
      offset += this->primitives[i].serialize(outbuffer + offset);
      }
      unsigned primitive_poses_length = primitive_poses.size();
      outbuffer[offset++] = (primitive_poses_length >> 0) & 0xFF;
      outbuffer[offset++] = (primitive_poses_length >> 8) & 0xFF;
      outbuffer[offset++] = (primitive_poses_length >> 16) & 0xFF;
      outbuffer[offset++] = (primitive_poses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < primitive_poses_length; i++){
      offset += this->primitive_poses[i].serialize(outbuffer + offset);
      }
      unsigned meshes_length = meshes.size();
      outbuffer[offset++] = (meshes_length >> 0) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 8) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 16) & 0xFF;
      outbuffer[offset++] = (meshes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < meshes_length; i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      unsigned mesh_poses_length = mesh_poses.size();
      outbuffer[offset++] = (mesh_poses_length >> 0) & 0xFF;
      outbuffer[offset++] = (mesh_poses_length >> 8) & 0xFF;
      outbuffer[offset++] = (mesh_poses_length >> 16) & 0xFF;
      outbuffer[offset++] = (mesh_poses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < mesh_poses_length; i++){
      offset += this->mesh_poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned primitives_length = inbuffer[offset++];
      primitives_length |= inbuffer[offset++] << 8;
      primitives_length |= inbuffer[offset++] << 16;
      primitives_length |= inbuffer[offset++] << 24;
      primitives.clear();
      primitives.reserve(primitives_length);
      for( unsigned i = 0; i < primitives_length; i++){
      primitives.emplace_back();
      offset += this->primitives.back().deserialize(inbuffer + offset);
      }
      unsigned primitive_poses_length = inbuffer[offset++];
      primitive_poses_length |= inbuffer[offset++] << 8;
      primitive_poses_length |= inbuffer[offset++] << 16;
      primitive_poses_length |= inbuffer[offset++] << 24;
      primitive_poses.clear();
      primitive_poses.reserve(primitive_poses_length);
      for( unsigned i = 0; i < primitive_poses_length; i++){
      primitive_poses.emplace_back();
      offset += this->primitive_poses.back().deserialize(inbuffer + offset);
      }
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
      unsigned mesh_poses_length = inbuffer[offset++];
      mesh_poses_length |= inbuffer[offset++] << 8;
      mesh_poses_length |= inbuffer[offset++] << 16;
      mesh_poses_length |= inbuffer[offset++] << 24;
      mesh_poses.clear();
      mesh_poses.reserve(mesh_poses_length);
      for( unsigned i = 0; i < mesh_poses_length; i++){
      mesh_poses.emplace_back();
      offset += this->mesh_poses.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/BoundingVolume"; };
    const char * getMD5(){ return "22db94010f39e9198032cb4a1aeda26e"; };

  };

}
#endif