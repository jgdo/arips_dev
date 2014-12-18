#ifndef _ROS_dynamic_reconfigure_Config_h
#define _ROS_dynamic_reconfigure_Config_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_reconfigure/BoolParameter.h"
#include <vector>
#include "dynamic_reconfigure/IntParameter.h"
#include "dynamic_reconfigure/StrParameter.h"
#include "dynamic_reconfigure/DoubleParameter.h"
#include "dynamic_reconfigure/GroupState.h"

namespace dynamic_reconfigure
{

  class Config : public ros::Msg
  {
    public:
      std::vector<dynamic_reconfigure::BoolParameter> bools;
      std::vector<dynamic_reconfigure::IntParameter> ints;
      std::vector<dynamic_reconfigure::StrParameter> strs;
      std::vector<dynamic_reconfigure::DoubleParameter> doubles;
      std::vector<dynamic_reconfigure::GroupState> groups;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned bools_length = bools.size();
      outbuffer[offset++] = (bools_length >> 0) & 0xFF;
      outbuffer[offset++] = (bools_length >> 8) & 0xFF;
      outbuffer[offset++] = (bools_length >> 16) & 0xFF;
      outbuffer[offset++] = (bools_length >> 24) & 0xFF;
      for( unsigned i = 0; i < bools_length; i++){
      offset += this->bools[i].serialize(outbuffer + offset);
      }
      unsigned ints_length = ints.size();
      outbuffer[offset++] = (ints_length >> 0) & 0xFF;
      outbuffer[offset++] = (ints_length >> 8) & 0xFF;
      outbuffer[offset++] = (ints_length >> 16) & 0xFF;
      outbuffer[offset++] = (ints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ints_length; i++){
      offset += this->ints[i].serialize(outbuffer + offset);
      }
      unsigned strs_length = strs.size();
      outbuffer[offset++] = (strs_length >> 0) & 0xFF;
      outbuffer[offset++] = (strs_length >> 8) & 0xFF;
      outbuffer[offset++] = (strs_length >> 16) & 0xFF;
      outbuffer[offset++] = (strs_length >> 24) & 0xFF;
      for( unsigned i = 0; i < strs_length; i++){
      offset += this->strs[i].serialize(outbuffer + offset);
      }
      unsigned doubles_length = doubles.size();
      outbuffer[offset++] = (doubles_length >> 0) & 0xFF;
      outbuffer[offset++] = (doubles_length >> 8) & 0xFF;
      outbuffer[offset++] = (doubles_length >> 16) & 0xFF;
      outbuffer[offset++] = (doubles_length >> 24) & 0xFF;
      for( unsigned i = 0; i < doubles_length; i++){
      offset += this->doubles[i].serialize(outbuffer + offset);
      }
      unsigned groups_length = groups.size();
      outbuffer[offset++] = (groups_length >> 0) & 0xFF;
      outbuffer[offset++] = (groups_length >> 8) & 0xFF;
      outbuffer[offset++] = (groups_length >> 16) & 0xFF;
      outbuffer[offset++] = (groups_length >> 24) & 0xFF;
      for( unsigned i = 0; i < groups_length; i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned bools_length = inbuffer[offset++];
      bools_length |= inbuffer[offset++] << 8;
      bools_length |= inbuffer[offset++] << 16;
      bools_length |= inbuffer[offset++] << 24;
      bools.clear();
      bools.reserve(bools_length);
      for( unsigned i = 0; i < bools_length; i++){
      bools.emplace_back();
      offset += this->bools.back().deserialize(inbuffer + offset);
      }
      unsigned ints_length = inbuffer[offset++];
      ints_length |= inbuffer[offset++] << 8;
      ints_length |= inbuffer[offset++] << 16;
      ints_length |= inbuffer[offset++] << 24;
      ints.clear();
      ints.reserve(ints_length);
      for( unsigned i = 0; i < ints_length; i++){
      ints.emplace_back();
      offset += this->ints.back().deserialize(inbuffer + offset);
      }
      unsigned strs_length = inbuffer[offset++];
      strs_length |= inbuffer[offset++] << 8;
      strs_length |= inbuffer[offset++] << 16;
      strs_length |= inbuffer[offset++] << 24;
      strs.clear();
      strs.reserve(strs_length);
      for( unsigned i = 0; i < strs_length; i++){
      strs.emplace_back();
      offset += this->strs.back().deserialize(inbuffer + offset);
      }
      unsigned doubles_length = inbuffer[offset++];
      doubles_length |= inbuffer[offset++] << 8;
      doubles_length |= inbuffer[offset++] << 16;
      doubles_length |= inbuffer[offset++] << 24;
      doubles.clear();
      doubles.reserve(doubles_length);
      for( unsigned i = 0; i < doubles_length; i++){
      doubles.emplace_back();
      offset += this->doubles.back().deserialize(inbuffer + offset);
      }
      unsigned groups_length = inbuffer[offset++];
      groups_length |= inbuffer[offset++] << 8;
      groups_length |= inbuffer[offset++] << 16;
      groups_length |= inbuffer[offset++] << 24;
      groups.clear();
      groups.reserve(groups_length);
      for( unsigned i = 0; i < groups_length; i++){
      groups.emplace_back();
      offset += this->groups.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "dynamic_reconfigure/Config"; };
    const char * getMD5(){ return "958f16a05573709014982821e6822580"; };

  };

}
#endif