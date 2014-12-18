#ifndef _ROS_moveit_msgs_CollisionObject_h
#define _ROS_moveit_msgs_CollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/ObjectType.h"
#include "shape_msgs/SolidPrimitive.h"
#include <vector>
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"
#include "shape_msgs/Plane.h"

namespace moveit_msgs
{

  class CollisionObject : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * id = nullptr;
      object_recognition_msgs::ObjectType type;
      std::vector<shape_msgs::SolidPrimitive> primitives;
      std::vector<geometry_msgs::Pose> primitive_poses;
      std::vector<shape_msgs::Mesh> meshes;
      std::vector<geometry_msgs::Pose> mesh_poses;
      std::vector<shape_msgs::Plane> planes;
      std::vector<geometry_msgs::Pose> plane_poses;
      int8_t operation = 0;
      enum { ADD = 0 };
      enum { REMOVE = 1 };
      enum { APPEND = 2 };
      enum { MOVE = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_);
      offset += length_;
      }
      offset += this->type.serialize(outbuffer + offset);
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
      unsigned planes_length = planes.size();
      outbuffer[offset++] = (planes_length >> 0) & 0xFF;
      outbuffer[offset++] = (planes_length >> 8) & 0xFF;
      outbuffer[offset++] = (planes_length >> 16) & 0xFF;
      outbuffer[offset++] = (planes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < planes_length; i++){
      offset += this->planes[i].serialize(outbuffer + offset);
      }
      unsigned plane_poses_length = plane_poses.size();
      outbuffer[offset++] = (plane_poses_length >> 0) & 0xFF;
      outbuffer[offset++] = (plane_poses_length >> 8) & 0xFF;
      outbuffer[offset++] = (plane_poses_length >> 16) & 0xFF;
      outbuffer[offset++] = (plane_poses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < plane_poses_length; i++){
      offset += this->plane_poses[i].serialize(outbuffer + offset);
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->operation;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->operation);
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
      this->id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->type.deserialize(inbuffer + offset);
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
      unsigned planes_length = inbuffer[offset++];
      planes_length |= inbuffer[offset++] << 8;
      planes_length |= inbuffer[offset++] << 16;
      planes_length |= inbuffer[offset++] << 24;
      planes.clear();
      planes.reserve(planes_length);
      for( unsigned i = 0; i < planes_length; i++){
      planes.emplace_back();
      offset += this->planes.back().deserialize(inbuffer + offset);
      }
      unsigned plane_poses_length = inbuffer[offset++];
      plane_poses_length |= inbuffer[offset++] << 8;
      plane_poses_length |= inbuffer[offset++] << 16;
      plane_poses_length |= inbuffer[offset++] << 24;
      plane_poses.clear();
      plane_poses.reserve(plane_poses_length);
      for( unsigned i = 0; i < plane_poses_length; i++){
      plane_poses.emplace_back();
      offset += this->plane_poses.back().deserialize(inbuffer + offset);
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation = u_.real;
      }
      offset += sizeof(this->operation);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/CollisionObject"; };
    const char * getMD5(){ return "568a161b26dc46c54a5a07621ce82cf3"; };

  };

}
#endif