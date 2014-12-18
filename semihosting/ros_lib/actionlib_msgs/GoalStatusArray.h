#ifndef _ROS_actionlib_msgs_GoalStatusArray_h
#define _ROS_actionlib_msgs_GoalStatusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include <vector>

namespace actionlib_msgs
{

  class GoalStatusArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<actionlib_msgs::GoalStatus> status_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned status_list_length = status_list.size();
      outbuffer[offset++] = (status_list_length >> 0) & 0xFF;
      outbuffer[offset++] = (status_list_length >> 8) & 0xFF;
      outbuffer[offset++] = (status_list_length >> 16) & 0xFF;
      outbuffer[offset++] = (status_list_length >> 24) & 0xFF;
      for( unsigned i = 0; i < status_list_length; i++){
      offset += this->status_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned status_list_length = inbuffer[offset++];
      status_list_length |= inbuffer[offset++] << 8;
      status_list_length |= inbuffer[offset++] << 16;
      status_list_length |= inbuffer[offset++] << 24;
      status_list.clear();
      status_list.reserve(status_list_length);
      for( unsigned i = 0; i < status_list_length; i++){
      status_list.emplace_back();
      offset += this->status_list.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "actionlib_msgs/GoalStatusArray"; };
    const char * getMD5(){ return "8b2b82f13216d0a8ea88bd3af735e619"; };

  };

}
#endif