#ifndef _ROS_moveit_msgs_RobotState_h
#define _ROS_moveit_msgs_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/MultiDOFJointState.h"
#include "moveit_msgs/AttachedCollisionObject.h"
#include <vector>

namespace moveit_msgs
{

  class RobotState : public ros::Msg
  {
    public:
      sensor_msgs::JointState joint_state;
      sensor_msgs::MultiDOFJointState multi_dof_joint_state;
      std::vector<moveit_msgs::AttachedCollisionObject> attached_collision_objects;
      bool is_diff = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_state.serialize(outbuffer + offset);
      offset += this->multi_dof_joint_state.serialize(outbuffer + offset);
      unsigned attached_collision_objects_length = attached_collision_objects.size();
      outbuffer[offset++] = (attached_collision_objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (attached_collision_objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (attached_collision_objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (attached_collision_objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < attached_collision_objects_length; i++){
      offset += this->attached_collision_objects[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_diff;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_diff);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_state.deserialize(inbuffer + offset);
      offset += this->multi_dof_joint_state.deserialize(inbuffer + offset);
      unsigned attached_collision_objects_length = inbuffer[offset++];
      attached_collision_objects_length |= inbuffer[offset++] << 8;
      attached_collision_objects_length |= inbuffer[offset++] << 16;
      attached_collision_objects_length |= inbuffer[offset++] << 24;
      attached_collision_objects.clear();
      attached_collision_objects.reserve(attached_collision_objects_length);
      for( unsigned i = 0; i < attached_collision_objects_length; i++){
      attached_collision_objects.emplace_back();
      offset += this->attached_collision_objects.back().deserialize(inbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_diff = u_.real;
      }
      offset += sizeof(this->is_diff);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/RobotState"; };
    const char * getMD5(){ return "217a2e8e5547f4162b13a37db9cb4da4"; };

  };

}
#endif