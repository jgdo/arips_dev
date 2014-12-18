#ifndef _ROS_yocs_msgs_WallList_h
#define _ROS_yocs_msgs_WallList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "yocs_msgs/Wall.h"
#include <vector>

namespace yocs_msgs
{

  class WallList : public ros::Msg
  {
    public:
      std::vector<yocs_msgs::Wall> obstacles;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned obstacles_length = obstacles.size();
      outbuffer[offset++] = (obstacles_length >> 0) & 0xFF;
      outbuffer[offset++] = (obstacles_length >> 8) & 0xFF;
      outbuffer[offset++] = (obstacles_length >> 16) & 0xFF;
      outbuffer[offset++] = (obstacles_length >> 24) & 0xFF;
      for( unsigned i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned obstacles_length = inbuffer[offset++];
      obstacles_length |= inbuffer[offset++] << 8;
      obstacles_length |= inbuffer[offset++] << 16;
      obstacles_length |= inbuffer[offset++] << 24;
      obstacles.clear();
      obstacles.reserve(obstacles_length);
      for( unsigned i = 0; i < obstacles_length; i++){
      obstacles.emplace_back();
      offset += this->obstacles.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "yocs_msgs/WallList"; };
    const char * getMD5(){ return "2879979aabb372fc7f6d782228e53412"; };

  };

}
#endif