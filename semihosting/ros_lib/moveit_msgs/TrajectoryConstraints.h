#ifndef _ROS_moveit_msgs_TrajectoryConstraints_h
#define _ROS_moveit_msgs_TrajectoryConstraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/Constraints.h"
#include <vector>

namespace moveit_msgs
{

  class TrajectoryConstraints : public ros::Msg
  {
    public:
      std::vector<moveit_msgs::Constraints> constraints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned constraints_length = constraints.size();
      outbuffer[offset++] = (constraints_length >> 0) & 0xFF;
      outbuffer[offset++] = (constraints_length >> 8) & 0xFF;
      outbuffer[offset++] = (constraints_length >> 16) & 0xFF;
      outbuffer[offset++] = (constraints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < constraints_length; i++){
      offset += this->constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned constraints_length = inbuffer[offset++];
      constraints_length |= inbuffer[offset++] << 8;
      constraints_length |= inbuffer[offset++] << 16;
      constraints_length |= inbuffer[offset++] << 24;
      constraints.clear();
      constraints.reserve(constraints_length);
      for( unsigned i = 0; i < constraints_length; i++){
      constraints.emplace_back();
      offset += this->constraints.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/TrajectoryConstraints"; };
    const char * getMD5(){ return "461e1a732dfebb01e7d6c75d51a51eac"; };

  };

}
#endif