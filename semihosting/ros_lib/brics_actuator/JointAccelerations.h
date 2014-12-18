#ifndef _ROS_brics_actuator_JointAccelerations_h
#define _ROS_brics_actuator_JointAccelerations_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"
#include <vector>

namespace brics_actuator
{

  class JointAccelerations : public ros::Msg
  {
    public:
      brics_actuator::Poison poisonStamp;
      std::vector<brics_actuator::JointValue> accelerations;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      unsigned accelerations_length = accelerations.size();
      outbuffer[offset++] = (accelerations_length >> 0) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 8) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 16) & 0xFF;
      outbuffer[offset++] = (accelerations_length >> 24) & 0xFF;
      for( unsigned i = 0; i < accelerations_length; i++){
      offset += this->accelerations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
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
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointAccelerations"; };
    const char * getMD5(){ return "f904d45aa2c1d97ea9e99a3ba4e3610e"; };

  };

}
#endif