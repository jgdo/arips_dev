#ifndef _ROS_brics_actuator_JointTorques_h
#define _ROS_brics_actuator_JointTorques_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"
#include <vector>

namespace brics_actuator
{

  class JointTorques : public ros::Msg
  {
    public:
      brics_actuator::Poison poisonStamp;
      std::vector<brics_actuator::JointValue> torques;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      unsigned torques_length = torques.size();
      outbuffer[offset++] = (torques_length >> 0) & 0xFF;
      outbuffer[offset++] = (torques_length >> 8) & 0xFF;
      outbuffer[offset++] = (torques_length >> 16) & 0xFF;
      outbuffer[offset++] = (torques_length >> 24) & 0xFF;
      for( unsigned i = 0; i < torques_length; i++){
      offset += this->torques[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      unsigned torques_length = inbuffer[offset++];
      torques_length |= inbuffer[offset++] << 8;
      torques_length |= inbuffer[offset++] << 16;
      torques_length |= inbuffer[offset++] << 24;
      torques.clear();
      torques.reserve(torques_length);
      for( unsigned i = 0; i < torques_length; i++){
      torques.emplace_back();
      offset += this->torques.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointTorques"; };
    const char * getMD5(){ return "75ccec429fa95e6b178bb9f3d06583e1"; };

  };

}
#endif