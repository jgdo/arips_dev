#ifndef _ROS_smach_msgs_SmachContainerInitialStatusCmd_h
#define _ROS_smach_msgs_SmachContainerInitialStatusCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace smach_msgs
{

  class SmachContainerInitialStatusCmd : public ros::Msg
  {
    public:
      char * path = nullptr;
      std::vector<char*> initial_states;
      char * local_data = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->path);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->path, length_);
      offset += length_;
      }
      unsigned initial_states_length = initial_states.size();
      outbuffer[offset++] = (initial_states_length >> 0) & 0xFF;
      outbuffer[offset++] = (initial_states_length >> 8) & 0xFF;
      outbuffer[offset++] = (initial_states_length >> 16) & 0xFF;
      outbuffer[offset++] = (initial_states_length >> 24) & 0xFF;
      for( unsigned i = 0; i < initial_states_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->initial_states[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->initial_states[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->local_data);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->local_data, length_);
      offset += length_;
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
      this->path = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned initial_states_length = inbuffer[offset++];
      initial_states_length |= inbuffer[offset++] << 8;
      initial_states_length |= inbuffer[offset++] << 16;
      initial_states_length |= inbuffer[offset++] << 24;
      initial_states.clear();
      initial_states.reserve(initial_states_length);
      for( unsigned i = 0; i < initial_states_length; i++){
      initial_states.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->initial_states.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->local_data = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "smach_msgs/SmachContainerInitialStatusCmd"; };
    const char * getMD5(){ return "45f8cf31fc29b829db77f23001f788d6"; };

  };

}
#endif