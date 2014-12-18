#ifndef _ROS_moveit_msgs_DisplayRobotState_h
#define _ROS_moveit_msgs_DisplayRobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/ObjectColor.h"
#include <vector>

namespace moveit_msgs
{

  class DisplayRobotState : public ros::Msg
  {
    public:
      moveit_msgs::RobotState state;
      std::vector<moveit_msgs::ObjectColor> highlight_links;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      unsigned highlight_links_length = highlight_links.size();
      outbuffer[offset++] = (highlight_links_length >> 0) & 0xFF;
      outbuffer[offset++] = (highlight_links_length >> 8) & 0xFF;
      outbuffer[offset++] = (highlight_links_length >> 16) & 0xFF;
      outbuffer[offset++] = (highlight_links_length >> 24) & 0xFF;
      for( unsigned i = 0; i < highlight_links_length; i++){
      offset += this->highlight_links[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
      unsigned highlight_links_length = inbuffer[offset++];
      highlight_links_length |= inbuffer[offset++] << 8;
      highlight_links_length |= inbuffer[offset++] << 16;
      highlight_links_length |= inbuffer[offset++] << 24;
      highlight_links.clear();
      highlight_links.reserve(highlight_links_length);
      for( unsigned i = 0; i < highlight_links_length; i++){
      highlight_links.emplace_back();
      offset += this->highlight_links.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/DisplayRobotState"; };
    const char * getMD5(){ return "6a3bab3a33a8c47aee24481a455a21aa"; };

  };

}
#endif