#ifndef _ROS_dynamic_reconfigure_ConfigDescription_h
#define _ROS_dynamic_reconfigure_ConfigDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_reconfigure/Group.h"
#include <vector>
#include "dynamic_reconfigure/Config.h"

namespace dynamic_reconfigure
{

  class ConfigDescription : public ros::Msg
  {
    public:
      std::vector<dynamic_reconfigure::Group> groups;
      dynamic_reconfigure::Config max;
      dynamic_reconfigure::Config min;
      dynamic_reconfigure::Config dflt;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned groups_length = groups.size();
      outbuffer[offset++] = (groups_length >> 0) & 0xFF;
      outbuffer[offset++] = (groups_length >> 8) & 0xFF;
      outbuffer[offset++] = (groups_length >> 16) & 0xFF;
      outbuffer[offset++] = (groups_length >> 24) & 0xFF;
      for( unsigned i = 0; i < groups_length; i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      offset += this->max.serialize(outbuffer + offset);
      offset += this->min.serialize(outbuffer + offset);
      offset += this->dflt.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      offset += this->max.deserialize(inbuffer + offset);
      offset += this->min.deserialize(inbuffer + offset);
      offset += this->dflt.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "dynamic_reconfigure/ConfigDescription"; };
    const char * getMD5(){ return "757ce9d44ba8ddd801bb30bc456f946f"; };

  };

}
#endif