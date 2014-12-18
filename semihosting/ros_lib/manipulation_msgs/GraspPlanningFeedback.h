#ifndef _ROS_manipulation_msgs_GraspPlanningFeedback_h
#define _ROS_manipulation_msgs_GraspPlanningFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "manipulation_msgs/Grasp.h"
#include <vector>

namespace manipulation_msgs
{

  class GraspPlanningFeedback : public ros::Msg
  {
    public:
      std::vector<manipulation_msgs::Grasp> grasps;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned grasps_length = grasps.size();
      outbuffer[offset++] = (grasps_length >> 0) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 8) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 16) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < grasps_length; i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned grasps_length = inbuffer[offset++];
      grasps_length |= inbuffer[offset++] << 8;
      grasps_length |= inbuffer[offset++] << 16;
      grasps_length |= inbuffer[offset++] << 24;
      grasps.clear();
      grasps.reserve(grasps_length);
      for( unsigned i = 0; i < grasps_length; i++){
      grasps.emplace_back();
      offset += this->grasps.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspPlanningFeedback"; };
    const char * getMD5(){ return "0b493f83ef98679f05dc681205fbe54c"; };

  };

}
#endif