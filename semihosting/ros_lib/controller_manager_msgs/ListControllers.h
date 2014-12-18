#ifndef _ROS_SERVICE_ListControllers_h
#define _ROS_SERVICE_ListControllers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "controller_manager_msgs/ControllerState.h"
#include <vector>

namespace controller_manager_msgs
{

static const char LISTCONTROLLERS[] = "controller_manager_msgs/ListControllers";

  class ListControllersRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListControllersResponse : public ros::Msg
  {
    public:
      std::vector<controller_manager_msgs::ControllerState> controller;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return LISTCONTROLLERS; };
    const char * getMD5(){ return "12c85fca1984c8ec86264f3d00b938f2"; };

  };

  class ListControllers {
    public:
    typedef ListControllersRequest Request;
    typedef ListControllersResponse Response;
  };

}
#endif
