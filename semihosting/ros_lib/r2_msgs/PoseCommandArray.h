#ifndef _ROS_r2_msgs_PoseCommandArray_h
#define _ROS_r2_msgs_PoseCommandArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "r2_msgs/PoseCommand.h"
#include <vector>

namespace r2_msgs
{

  class PoseCommandArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<r2_msgs::PoseCommand> command;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned command_length = command.size();
      outbuffer[offset++] = (command_length >> 0) & 0xFF;
      outbuffer[offset++] = (command_length >> 8) & 0xFF;
      outbuffer[offset++] = (command_length >> 16) & 0xFF;
      outbuffer[offset++] = (command_length >> 24) & 0xFF;
      for( unsigned i = 0; i < command_length; i++){
      offset += this->command[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned command_length = inbuffer[offset++];
      command_length |= inbuffer[offset++] << 8;
      command_length |= inbuffer[offset++] << 16;
      command_length |= inbuffer[offset++] << 24;
      command.clear();
      command.reserve(command_length);
      for( unsigned i = 0; i < command_length; i++){
      command.emplace_back();
      offset += this->command.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "r2_msgs/PoseCommandArray"; };
    const char * getMD5(){ return "fd9b3b03f805dcb412e07ffc694f2684"; };

  };

}
#endif