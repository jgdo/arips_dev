#ifndef _ROS_pr2_mechanism_msgs_SwitchControllerGoal_h
#define _ROS_pr2_mechanism_msgs_SwitchControllerGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace pr2_mechanism_msgs
{

  class SwitchControllerGoal : public ros::Msg
  {
    public:
      std::vector<char*> start_controllers;
      std::vector<char*> stop_controllers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned start_controllers_length = start_controllers.size();
      outbuffer[offset++] = (start_controllers_length >> 0) & 0xFF;
      outbuffer[offset++] = (start_controllers_length >> 8) & 0xFF;
      outbuffer[offset++] = (start_controllers_length >> 16) & 0xFF;
      outbuffer[offset++] = (start_controllers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < start_controllers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->start_controllers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->start_controllers[i], length_);
      offset += length_;
      }
      }
      unsigned stop_controllers_length = stop_controllers.size();
      outbuffer[offset++] = (stop_controllers_length >> 0) & 0xFF;
      outbuffer[offset++] = (stop_controllers_length >> 8) & 0xFF;
      outbuffer[offset++] = (stop_controllers_length >> 16) & 0xFF;
      outbuffer[offset++] = (stop_controllers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < stop_controllers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->stop_controllers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->stop_controllers[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned start_controllers_length = inbuffer[offset++];
      start_controllers_length |= inbuffer[offset++] << 8;
      start_controllers_length |= inbuffer[offset++] << 16;
      start_controllers_length |= inbuffer[offset++] << 24;
      start_controllers.clear();
      start_controllers.reserve(start_controllers_length);
      for( unsigned i = 0; i < start_controllers_length; i++){
      start_controllers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->start_controllers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned stop_controllers_length = inbuffer[offset++];
      stop_controllers_length |= inbuffer[offset++] << 8;
      stop_controllers_length |= inbuffer[offset++] << 16;
      stop_controllers_length |= inbuffer[offset++] << 24;
      stop_controllers.clear();
      stop_controllers.reserve(stop_controllers_length);
      for( unsigned i = 0; i < stop_controllers_length; i++){
      stop_controllers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->stop_controllers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_msgs/SwitchControllerGoal"; };
    const char * getMD5(){ return "c3f1879cbb2d6cd8732c0e031574dde5"; };

  };

}
#endif