#ifndef _ROS_gazebo_msgs_ContactsState_h
#define _ROS_gazebo_msgs_ContactsState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "gazebo_msgs/ContactState.h"
#include <vector>

namespace gazebo_msgs
{

  class ContactsState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<gazebo_msgs::ContactState> states;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned states_length = states.size();
      outbuffer[offset++] = (states_length >> 0) & 0xFF;
      outbuffer[offset++] = (states_length >> 8) & 0xFF;
      outbuffer[offset++] = (states_length >> 16) & 0xFF;
      outbuffer[offset++] = (states_length >> 24) & 0xFF;
      for( unsigned i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned states_length = inbuffer[offset++];
      states_length |= inbuffer[offset++] << 8;
      states_length |= inbuffer[offset++] << 16;
      states_length |= inbuffer[offset++] << 24;
      states.clear();
      states.reserve(states_length);
      for( unsigned i = 0; i < states_length; i++){
      states.emplace_back();
      offset += this->states.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ContactsState"; };
    const char * getMD5(){ return "acbcb1601a8e525bf72509f18e6f668d"; };

  };

}
#endif