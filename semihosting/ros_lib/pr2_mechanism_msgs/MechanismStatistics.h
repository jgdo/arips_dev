#ifndef _ROS_pr2_mechanism_msgs_MechanismStatistics_h
#define _ROS_pr2_mechanism_msgs_MechanismStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pr2_mechanism_msgs/ActuatorStatistics.h"
#include <vector>
#include "pr2_mechanism_msgs/JointStatistics.h"
#include "pr2_mechanism_msgs/ControllerStatistics.h"

namespace pr2_mechanism_msgs
{

  class MechanismStatistics : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<pr2_mechanism_msgs::ActuatorStatistics> actuator_statistics;
      std::vector<pr2_mechanism_msgs::JointStatistics> joint_statistics;
      std::vector<pr2_mechanism_msgs::ControllerStatistics> controller_statistics;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned actuator_statistics_length = actuator_statistics.size();
      outbuffer[offset++] = (actuator_statistics_length >> 0) & 0xFF;
      outbuffer[offset++] = (actuator_statistics_length >> 8) & 0xFF;
      outbuffer[offset++] = (actuator_statistics_length >> 16) & 0xFF;
      outbuffer[offset++] = (actuator_statistics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < actuator_statistics_length; i++){
      offset += this->actuator_statistics[i].serialize(outbuffer + offset);
      }
      unsigned joint_statistics_length = joint_statistics.size();
      outbuffer[offset++] = (joint_statistics_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_statistics_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_statistics_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_statistics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_statistics_length; i++){
      offset += this->joint_statistics[i].serialize(outbuffer + offset);
      }
      unsigned controller_statistics_length = controller_statistics.size();
      outbuffer[offset++] = (controller_statistics_length >> 0) & 0xFF;
      outbuffer[offset++] = (controller_statistics_length >> 8) & 0xFF;
      outbuffer[offset++] = (controller_statistics_length >> 16) & 0xFF;
      outbuffer[offset++] = (controller_statistics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < controller_statistics_length; i++){
      offset += this->controller_statistics[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned actuator_statistics_length = inbuffer[offset++];
      actuator_statistics_length |= inbuffer[offset++] << 8;
      actuator_statistics_length |= inbuffer[offset++] << 16;
      actuator_statistics_length |= inbuffer[offset++] << 24;
      actuator_statistics.clear();
      actuator_statistics.reserve(actuator_statistics_length);
      for( unsigned i = 0; i < actuator_statistics_length; i++){
      actuator_statistics.emplace_back();
      offset += this->actuator_statistics.back().deserialize(inbuffer + offset);
      }
      unsigned joint_statistics_length = inbuffer[offset++];
      joint_statistics_length |= inbuffer[offset++] << 8;
      joint_statistics_length |= inbuffer[offset++] << 16;
      joint_statistics_length |= inbuffer[offset++] << 24;
      joint_statistics.clear();
      joint_statistics.reserve(joint_statistics_length);
      for( unsigned i = 0; i < joint_statistics_length; i++){
      joint_statistics.emplace_back();
      offset += this->joint_statistics.back().deserialize(inbuffer + offset);
      }
      unsigned controller_statistics_length = inbuffer[offset++];
      controller_statistics_length |= inbuffer[offset++] << 8;
      controller_statistics_length |= inbuffer[offset++] << 16;
      controller_statistics_length |= inbuffer[offset++] << 24;
      controller_statistics.clear();
      controller_statistics.reserve(controller_statistics_length);
      for( unsigned i = 0; i < controller_statistics_length; i++){
      controller_statistics.emplace_back();
      offset += this->controller_statistics.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_msgs/MechanismStatistics"; };
    const char * getMD5(){ return "b4a99069393681672c01f8c823458e04"; };

  };

}
#endif