#ifndef _ROS_household_objects_database_msgs_DatabaseModelPoseList_h
#define _ROS_household_objects_database_msgs_DatabaseModelPoseList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseModelPose.h"
#include <vector>

namespace household_objects_database_msgs
{

  class DatabaseModelPoseList : public ros::Msg
  {
    public:
      std::vector<household_objects_database_msgs::DatabaseModelPose> model_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned model_list_length = model_list.size();
      outbuffer[offset++] = (model_list_length >> 0) & 0xFF;
      outbuffer[offset++] = (model_list_length >> 8) & 0xFF;
      outbuffer[offset++] = (model_list_length >> 16) & 0xFF;
      outbuffer[offset++] = (model_list_length >> 24) & 0xFF;
      for( unsigned i = 0; i < model_list_length; i++){
      offset += this->model_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned model_list_length = inbuffer[offset++];
      model_list_length |= inbuffer[offset++] << 8;
      model_list_length |= inbuffer[offset++] << 16;
      model_list_length |= inbuffer[offset++] << 24;
      model_list.clear();
      model_list.reserve(model_list_length);
      for( unsigned i = 0; i < model_list_length; i++){
      model_list.emplace_back();
      offset += this->model_list.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "household_objects_database_msgs/DatabaseModelPoseList"; };
    const char * getMD5(){ return "f0bb2aa8d2ededee0ffe0f5d2107e099"; };

  };

}
#endif