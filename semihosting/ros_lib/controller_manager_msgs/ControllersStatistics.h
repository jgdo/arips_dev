#ifndef _ROS_controller_manager_msgs_ControllersStatistics_h
#define _ROS_controller_manager_msgs_ControllersStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "controller_manager_msgs/ControllerStatistics.h"
#include <vector>

namespace controller_manager_msgs
{

  class ControllersStatistics : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<controller_manager_msgs::ControllerStatistics> controller;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned controller_length = controller.size();
      outbuffer[offset++] = (controller_length >> 0) & 0xFF;
      outbuffer[offset++] = (controller_length >> 8) & 0xFF;
      outbuffer[offset++] = (controller_length >> 16) & 0xFF;
      outbuffer[offset++] = (controller_length >> 24) & 0xFF;
      for( unsigned i = 0; i < controller_length; i++){
      offset += this->controller[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned controller_length = inbuffer[offset++];
      controller_length |= inbuffer[offset++] << 8;
      controller_length |= inbuffer[offset++] << 16;
      controller_length |= inbuffer[offset++] << 24;
      controller.clear();
      controller.reserve(controller_length);
      for( unsigned i = 0; i < controller_length; i++){
      controller.emplace_back();
      offset += this->controller.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "controller_manager_msgs/ControllersStatistics"; };
    const char * getMD5(){ return "a154c347736773e3700d1719105df29d"; };

  };

}
#endif