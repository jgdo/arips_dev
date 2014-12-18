#ifndef _ROS_brics_actuator_JointPositions_h
#define _ROS_brics_actuator_JointPositions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"
#include <vector>

namespace brics_actuator
{

  class JointPositions : public ros::Msg
  {
    public:
      brics_actuator::Poison poisonStamp;
      std::vector<brics_actuator::JointValue> positions;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      unsigned positions_length = positions.size();
      outbuffer[offset++] = (positions_length >> 0) & 0xFF;
      outbuffer[offset++] = (positions_length >> 8) & 0xFF;
      outbuffer[offset++] = (positions_length >> 16) & 0xFF;
      outbuffer[offset++] = (positions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < positions_length; i++){
      offset += this->positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      unsigned positions_length = inbuffer[offset++];
      positions_length |= inbuffer[offset++] << 8;
      positions_length |= inbuffer[offset++] << 16;
      positions_length |= inbuffer[offset++] << 24;
      positions.clear();
      positions.reserve(positions_length);
      for( unsigned i = 0; i < positions_length; i++){
      positions.emplace_back();
      offset += this->positions.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointPositions"; };
    const char * getMD5(){ return "2b7638f5c85f5257bef140a00cd0eec3"; };

  };

}
#endif