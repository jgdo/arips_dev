#ifndef _ROS_moveit_msgs_PlannerInterfaceDescription_h
#define _ROS_moveit_msgs_PlannerInterfaceDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace moveit_msgs
{

  class PlannerInterfaceDescription : public ros::Msg
  {
    public:
      char * name = nullptr;
      std::vector<char*> planner_ids;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      unsigned planner_ids_length = planner_ids.size();
      outbuffer[offset++] = (planner_ids_length >> 0) & 0xFF;
      outbuffer[offset++] = (planner_ids_length >> 8) & 0xFF;
      outbuffer[offset++] = (planner_ids_length >> 16) & 0xFF;
      outbuffer[offset++] = (planner_ids_length >> 24) & 0xFF;
      for( unsigned i = 0; i < planner_ids_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->planner_ids[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_ids[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned planner_ids_length = inbuffer[offset++];
      planner_ids_length |= inbuffer[offset++] << 8;
      planner_ids_length |= inbuffer[offset++] << 16;
      planner_ids_length |= inbuffer[offset++] << 24;
      planner_ids.clear();
      planner_ids.reserve(planner_ids_length);
      for( unsigned i = 0; i < planner_ids_length; i++){
      planner_ids.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->planner_ids.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlannerInterfaceDescription"; };
    const char * getMD5(){ return "ea5f6e6129aa1b110ccda9900d2bf25e"; };

  };

}
#endif