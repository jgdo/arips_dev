#ifndef _ROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h
#define _ROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"
#include <vector>
#include "geometry_msgs/Twist.h"
#include "ros/duration.h"

namespace trajectory_msgs
{

  class MultiDOFJointTrajectoryPoint : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::Transform> transforms;
      std::vector<geometry_msgs::Twist> velocities;
      std::vector<geometry_msgs::Twist> accelerations;
      ros::Duration time_from_start;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned transforms_length = transforms.size();
      outbuffer[offset++] = (transforms_length >> 0) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 8) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 16) & 0xFF;
      outbuffer[offset++] = (transforms_length >> 24) & 0xFF;
      for( unsigned i = 0; i < transforms_length; i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
      }
      unsigned velocities_length = velocities.size();
      outbuffer[offset++] = (velocities_length >> 0) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 8) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 16) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 24) & 0xFF;
      for( unsigned i = 0; i < velocities_length; i++){
      offset += this->velocities[i].serialize(outbuffer + offset);
      }
      unsigned accelerations_length = accelerations.size();
      outbuffer[offset++] = (accelerations_length >> 0) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 8) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 16) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 24) & 0xFF;
      for( unsigned i = 0; i < accelerations_length; i++){
      offset += this->accelerations[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned transforms_length = inbuffer[offset++];
      transforms_length |= inbuffer[offset++] << 8;
      transforms_length |= inbuffer[offset++] << 16;
      transforms_length |= inbuffer[offset++] << 24;
      transforms.clear();
      transforms.reserve(transforms_length);
      for( unsigned i = 0; i < transforms_length; i++){
      transforms.emplace_back();
      offset += this->transforms.back().deserialize(inbuffer + offset);
      }
      unsigned velocities_length = inbuffer[offset++];
      velocities_length |= inbuffer[offset++] << 8;
      velocities_length |= inbuffer[offset++] << 16;
      velocities_length |= inbuffer[offset++] << 24;
      velocities.clear();
      velocities.reserve(velocities_length);
      for( unsigned i = 0; i < velocities_length; i++){
      velocities.emplace_back();
      offset += this->velocities.back().deserialize(inbuffer + offset);
      }
      unsigned accelerations_length = inbuffer[offset++];
      accelerations_length |= inbuffer[offset++] << 8;
      accelerations_length |= inbuffer[offset++] << 16;
      accelerations_length |= inbuffer[offset++] << 24;
      accelerations.clear();
      accelerations.reserve(accelerations_length);
      for( unsigned i = 0; i < accelerations_length; i++){
      accelerations.emplace_back();
      offset += this->accelerations.back().deserialize(inbuffer + offset);
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
     return offset;
    }

    const char * getType(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; };
    const char * getMD5(){ return "3ebe08d1abd5b65862d50e09430db776"; };

  };

}
#endif