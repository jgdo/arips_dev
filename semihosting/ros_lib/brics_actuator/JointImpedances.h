#ifndef _ROS_brics_actuator_JointImpedances_h
#define _ROS_brics_actuator_JointImpedances_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"
#include <vector>

namespace brics_actuator
{

  class JointImpedances : public ros::Msg
  {
    public:
      brics_actuator::Poison poisonStamp;
      std::vector<brics_actuator::JointValue> dampings;
      std::vector<brics_actuator::JointValue> stiffnesses;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      unsigned dampings_length = dampings.size();
      outbuffer[offset++] = (dampings_length >> 0) & 0xFF;
      outbuffer[offset++] = (dampings_length >> 8) & 0xFF;
      outbuffer[offset++] = (dampings_length >> 16) & 0xFF;
      outbuffer[offset++] = (dampings_length >> 24) & 0xFF;
      for( unsigned i = 0; i < dampings_length; i++){
      offset += this->dampings[i].serialize(outbuffer + offset);
      }
      unsigned stiffnesses_length = stiffnesses.size();
      outbuffer[offset++] = (stiffnesses_length >> 0) & 0xFF;
      outbuffer[offset++] = (stiffnesses_length >> 8) & 0xFF;
      outbuffer[offset++] = (stiffnesses_length >> 16) & 0xFF;
      outbuffer[offset++] = (stiffnesses_length >> 24) & 0xFF;
      for( unsigned i = 0; i < stiffnesses_length; i++){
      offset += this->stiffnesses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      unsigned dampings_length = inbuffer[offset++];
      dampings_length |= inbuffer[offset++] << 8;
      dampings_length |= inbuffer[offset++] << 16;
      dampings_length |= inbuffer[offset++] << 24;
      dampings.clear();
      dampings.reserve(dampings_length);
      for( unsigned i = 0; i < dampings_length; i++){
      dampings.emplace_back();
      offset += this->dampings.back().deserialize(inbuffer + offset);
      }
      unsigned stiffnesses_length = inbuffer[offset++];
      stiffnesses_length |= inbuffer[offset++] << 8;
      stiffnesses_length |= inbuffer[offset++] << 16;
      stiffnesses_length |= inbuffer[offset++] << 24;
      stiffnesses.clear();
      stiffnesses.reserve(stiffnesses_length);
      for( unsigned i = 0; i < stiffnesses_length; i++){
      stiffnesses.emplace_back();
      offset += this->stiffnesses.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointImpedances"; };
    const char * getMD5(){ return "14fdbb76121290f17525acd99e7242c6"; };

  };

}
#endif