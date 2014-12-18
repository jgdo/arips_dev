#ifndef _ROS_SERVICE_SetJointTrajectory_h
#define _ROS_SERVICE_SetJointTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "geometry_msgs/Pose.h"

namespace gazebo_msgs
{

static const char SETJOINTTRAJECTORY[] = "gazebo_msgs/SetJointTrajectory";

  class SetJointTrajectoryRequest : public ros::Msg
  {
    public:
      char * model_name = nullptr;
      trajectory_msgs::JointTrajectory joint_trajectory;
      geometry_msgs::Pose model_pose;
      bool set_model_pose = 0;
      bool disable_physics_updates = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->model_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_);
      offset += length_;
      }
      offset += this->joint_trajectory.serialize(outbuffer + offset);
      offset += this->model_pose.serialize(outbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->set_model_pose;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->set_model_pose);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->disable_physics_updates;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->disable_physics_updates);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->joint_trajectory.deserialize(inbuffer + offset);
      offset += this->model_pose.deserialize(inbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_model_pose = u_.real;
      }
      offset += sizeof(this->set_model_pose);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_physics_updates = u_.real;
      }
      offset += sizeof(this->disable_physics_updates);
     return offset;
    }

    const char * getType(){ return SETJOINTTRAJECTORY; };
    const char * getMD5(){ return "649dd2eba5ffd358069238825f9f85ab"; };

  };

  class SetJointTrajectoryResponse : public ros::Msg
  {
    public:
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_.real;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SETJOINTTRAJECTORY; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetJointTrajectory {
    public:
    typedef SetJointTrajectoryRequest Request;
    typedef SetJointTrajectoryResponse Response;
  };

}
#endif
