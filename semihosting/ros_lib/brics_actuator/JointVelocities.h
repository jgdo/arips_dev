#ifndef _ROS_brics_actuator_JointVelocities_h
#define _ROS_brics_actuator_JointVelocities_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"
#include <vector>

namespace brics_actuator
{

  class JointVelocities : public ros::Msg
  {
    public:
      brics_actuator::Poison poisonStamp;
      std::vector<brics_actuator::JointValue> velocities;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      unsigned velocities_length = velocities.size();
      outbuffer[offset++] = (velocities_length >> 0) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 8) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 16) & 0xFF;
      outbuffer[offset++] = (velocities_length >> 24) & 0xFF;
      for( unsigned i = 0; i < velocities_length; i++){
      offset += this->velocities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
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
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointVelocities"; };
    const char * getMD5(){ return "9786afc900be50b3ba4113fcb65c9363"; };

  };

}
#endif