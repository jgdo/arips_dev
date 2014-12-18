#ifndef _ROS_control_msgs_FollowJointTrajectoryGoal_h
#define _ROS_control_msgs_FollowJointTrajectoryGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "control_msgs/JointTolerance.h"
#include <vector>
#include "ros/duration.h"

namespace control_msgs
{

  class FollowJointTrajectoryGoal : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      std::vector<control_msgs::JointTolerance> path_tolerance;
      std::vector<control_msgs::JointTolerance> goal_tolerance;
      ros::Duration goal_time_tolerance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      unsigned path_tolerance_length = path_tolerance.size();
      outbuffer[offset++] = (path_tolerance_length >> 0) & 0xFF;
      outbuffer[offset++] = (path_tolerance_length >> 8) & 0xFF;
      outbuffer[offset++] = (path_tolerance_length >> 16) & 0xFF;
      outbuffer[offset++] = (path_tolerance_length >> 24) & 0xFF;
      for( unsigned i = 0; i < path_tolerance_length; i++){
      offset += this->path_tolerance[i].serialize(outbuffer + offset);
      }
      unsigned goal_tolerance_length = goal_tolerance.size();
      outbuffer[offset++] = (goal_tolerance_length >> 0) & 0xFF;
      outbuffer[offset++] = (goal_tolerance_length >> 8) & 0xFF;
      outbuffer[offset++] = (goal_tolerance_length >> 16) & 0xFF;
      outbuffer[offset++] = (goal_tolerance_length >> 24) & 0xFF;
      for( unsigned i = 0; i < goal_tolerance_length; i++){
      offset += this->goal_tolerance[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->goal_time_tolerance.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->goal_time_tolerance.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->goal_time_tolerance.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->goal_time_tolerance.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_time_tolerance.sec);
      *(outbuffer + offset + 0) = (this->goal_time_tolerance.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->goal_time_tolerance.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->goal_time_tolerance.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->goal_time_tolerance.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_time_tolerance.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      unsigned path_tolerance_length = inbuffer[offset++];
      path_tolerance_length |= inbuffer[offset++] << 8;
      path_tolerance_length |= inbuffer[offset++] << 16;
      path_tolerance_length |= inbuffer[offset++] << 24;
      path_tolerance.clear();
      path_tolerance.reserve(path_tolerance_length);
      for( unsigned i = 0; i < path_tolerance_length; i++){
      path_tolerance.emplace_back();
      offset += this->path_tolerance.back().deserialize(inbuffer + offset);
      }
      unsigned goal_tolerance_length = inbuffer[offset++];
      goal_tolerance_length |= inbuffer[offset++] << 8;
      goal_tolerance_length |= inbuffer[offset++] << 16;
      goal_tolerance_length |= inbuffer[offset++] << 24;
      goal_tolerance.clear();
      goal_tolerance.reserve(goal_tolerance_length);
      for( unsigned i = 0; i < goal_tolerance_length; i++){
      goal_tolerance.emplace_back();
      offset += this->goal_tolerance.back().deserialize(inbuffer + offset);
      }
      this->goal_time_tolerance.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->goal_time_tolerance.sec);
      this->goal_time_tolerance.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->goal_time_tolerance.nsec);
     return offset;
    }

    const char * getType(){ return "control_msgs/FollowJointTrajectoryGoal"; };
    const char * getMD5(){ return "69636787b6ecbde4d61d711979bc7ecb"; };

  };

}
#endif