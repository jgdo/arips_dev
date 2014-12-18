#ifndef _ROS_moveit_msgs_DisplayTrajectory_h
#define _ROS_moveit_msgs_DisplayTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotTrajectory.h"
#include <vector>
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

  class DisplayTrajectory : public ros::Msg
  {
    public:
      char * model_id = nullptr;
      std::vector<moveit_msgs::RobotTrajectory> trajectory;
      moveit_msgs::RobotState trajectory_start;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->model_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_id, length_);
      offset += length_;
      }
      unsigned trajectory_length = trajectory.size();
      outbuffer[offset++] = (trajectory_length >> 0) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 8) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 16) & 0xFF;
      outbuffer[offset++] = (trajectory_length >> 24) & 0xFF;
      for( unsigned i = 0; i < trajectory_length; i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      offset += this->trajectory_start.serialize(outbuffer + offset);
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
      this->model_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned trajectory_length = inbuffer[offset++];
      trajectory_length |= inbuffer[offset++] << 8;
      trajectory_length |= inbuffer[offset++] << 16;
      trajectory_length |= inbuffer[offset++] << 24;
      trajectory.clear();
      trajectory.reserve(trajectory_length);
      for( unsigned i = 0; i < trajectory_length; i++){
      trajectory.emplace_back();
      offset += this->trajectory.back().deserialize(inbuffer + offset);
      }
      offset += this->trajectory_start.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/DisplayTrajectory"; };
    const char * getMD5(){ return "c3c039261ab9e8a11457dac56b6316c8"; };

  };

}
#endif