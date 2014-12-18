#ifndef _ROS_SERVICE_QueryPlannerInterfaces_h
#define _ROS_SERVICE_QueryPlannerInterfaces_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlannerInterfaceDescription.h"
#include <vector>

namespace moveit_msgs
{

static const char QUERYPLANNERINTERFACES[] = "moveit_msgs/QueryPlannerInterfaces";

  class QueryPlannerInterfacesRequest : public ros::Msg
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

    const char * getType(){ return QUERYPLANNERINTERFACES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class QueryPlannerInterfacesResponse : public ros::Msg
  {
    public:
      std::vector<moveit_msgs::PlannerInterfaceDescription> planner_interfaces;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned planner_interfaces_length = planner_interfaces.size();
      outbuffer[offset++] = (planner_interfaces_length >> 0) & 0xFF;
      outbuffer[offset++] = (planner_interfaces_length >> 8) & 0xFF;
      outbuffer[offset++] = (planner_interfaces_length >> 16) & 0xFF;
      outbuffer[offset++] = (planner_interfaces_length >> 24) & 0xFF;
      for( unsigned i = 0; i < planner_interfaces_length; i++){
      offset += this->planner_interfaces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned planner_interfaces_length = inbuffer[offset++];
      planner_interfaces_length |= inbuffer[offset++] << 8;
      planner_interfaces_length |= inbuffer[offset++] << 16;
      planner_interfaces_length |= inbuffer[offset++] << 24;
      planner_interfaces.clear();
      planner_interfaces.reserve(planner_interfaces_length);
      for( unsigned i = 0; i < planner_interfaces_length; i++){
      planner_interfaces.emplace_back();
      offset += this->planner_interfaces.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return QUERYPLANNERINTERFACES; };
    const char * getMD5(){ return "acd3317a4c5631f33127fb428209db05"; };

  };

  class QueryPlannerInterfaces {
    public:
    typedef QueryPlannerInterfacesRequest Request;
    typedef QueryPlannerInterfacesResponse Response;
  };

}
#endif
