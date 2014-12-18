#ifndef _ROS_moveit_msgs_PlanningSceneWorld_h
#define _ROS_moveit_msgs_PlanningSceneWorld_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/CollisionObject.h"
#include <vector>
#include "octomap_msgs/OctomapWithPose.h"

namespace moveit_msgs
{

  class PlanningSceneWorld : public ros::Msg
  {
    public:
      std::vector<moveit_msgs::CollisionObject> collision_objects;
      octomap_msgs::OctomapWithPose octomap;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned collision_objects_length = collision_objects.size();
      outbuffer[offset++] = (collision_objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (collision_objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (collision_objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (collision_objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < collision_objects_length; i++){
      offset += this->collision_objects[i].serialize(outbuffer + offset);
      }
      offset += this->octomap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned collision_objects_length = inbuffer[offset++];
      collision_objects_length |= inbuffer[offset++] << 8;
      collision_objects_length |= inbuffer[offset++] << 16;
      collision_objects_length |= inbuffer[offset++] << 24;
      collision_objects.clear();
      collision_objects.reserve(collision_objects_length);
      for( unsigned i = 0; i < collision_objects_length; i++){
      collision_objects.emplace_back();
      offset += this->collision_objects.back().deserialize(inbuffer + offset);
      }
      offset += this->octomap.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningSceneWorld"; };
    const char * getMD5(){ return "373d88390d1db385335639f687723ee6"; };

  };

}
#endif