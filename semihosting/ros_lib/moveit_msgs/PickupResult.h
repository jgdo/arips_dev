#ifndef _ROS_moveit_msgs_PickupResult_h
#define _ROS_moveit_msgs_PickupResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"
#include <vector>
#include "moveit_msgs/Grasp.h"

namespace moveit_msgs
{

  class PickupResult : public ros::Msg
  {
    public:
      moveit_msgs::MoveItErrorCodes error_code;
      moveit_msgs::RobotState trajectory_start;
      std::vector<moveit_msgs::RobotTrajectory> trajectory_stages;
      std::vector<char*> trajectory_descriptions;
      moveit_msgs::Grasp grasp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      offset += this->trajectory_start.serialize(outbuffer + offset);
      unsigned trajectory_stages_length = trajectory_stages.size();
      outbuffer[offset++] = (trajectory_stages_length >> 0) & 0xFF;
      outbuffer[offset++] = (trajectory_stages_length >> 8) & 0xFF;
      outbuffer[offset++] = (trajectory_stages_length >> 16) & 0xFF;
      outbuffer[offset++] = (trajectory_stages_length >> 24) & 0xFF;
      for( unsigned i = 0; i < trajectory_stages_length; i++){
      offset += this->trajectory_stages[i].serialize(outbuffer + offset);
      }
      unsigned trajectory_descriptions_length = trajectory_descriptions.size();
      outbuffer[offset++] = (trajectory_descriptions_length >> 0) & 0xFF;
      outbuffer[offset++] = (trajectory_descriptions_length >> 8) & 0xFF;
      outbuffer[offset++] = (trajectory_descriptions_length >> 16) & 0xFF;
      outbuffer[offset++] = (trajectory_descriptions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < trajectory_descriptions_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->trajectory_descriptions[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->trajectory_descriptions[i], length_);
      offset += length_;
      }
      }
      offset += this->grasp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      offset += this->trajectory_start.deserialize(inbuffer + offset);
      unsigned trajectory_stages_length = inbuffer[offset++];
      trajectory_stages_length |= inbuffer[offset++] << 8;
      trajectory_stages_length |= inbuffer[offset++] << 16;
      trajectory_stages_length |= inbuffer[offset++] << 24;
      trajectory_stages.clear();
      trajectory_stages.reserve(trajectory_stages_length);
      for( unsigned i = 0; i < trajectory_stages_length; i++){
      trajectory_stages.emplace_back();
      offset += this->trajectory_stages.back().deserialize(inbuffer + offset);
      }
      unsigned trajectory_descriptions_length = inbuffer[offset++];
      trajectory_descriptions_length |= inbuffer[offset++] << 8;
      trajectory_descriptions_length |= inbuffer[offset++] << 16;
      trajectory_descriptions_length |= inbuffer[offset++] << 24;
      trajectory_descriptions.clear();
      trajectory_descriptions.reserve(trajectory_descriptions_length);
      for( unsigned i = 0; i < trajectory_descriptions_length; i++){
      trajectory_descriptions.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->trajectory_descriptions.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      offset += this->grasp.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PickupResult"; };
    const char * getMD5(){ return "23c6d8bf0580f4bc8f7a8e1f59b4b6b7"; };

  };

}
#endif