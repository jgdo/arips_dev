#ifndef _ROS_scheduler_msgs_Resource_h
#define _ROS_scheduler_msgs_Resource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "rocon_std_msgs/Remapping.h"
#include <vector>

namespace scheduler_msgs
{

  class Resource : public ros::Msg
  {
    public:
      char * rapp = nullptr;
      uuid_msgs::UniqueID id;
      char * uri = nullptr;
      std::vector<rocon_std_msgs::Remapping> remappings;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->rapp);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapp, length_);
      offset += length_;
      }
      offset += this->id.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->uri);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_);
      offset += length_;
      }
      unsigned remappings_length = remappings.size();
      outbuffer[offset++] = (remappings_length >> 0) & 0xFF;
      outbuffer[offset++] = (remappings_length >> 8) & 0xFF;
      outbuffer[offset++] = (remappings_length >> 16) & 0xFF;
      outbuffer[offset++] = (remappings_length >> 24) & 0xFF;
      for( unsigned i = 0; i < remappings_length; i++){
      offset += this->remappings[i].serialize(outbuffer + offset);
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
      this->rapp = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->id.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned remappings_length = inbuffer[offset++];
      remappings_length |= inbuffer[offset++] << 8;
      remappings_length |= inbuffer[offset++] << 16;
      remappings_length |= inbuffer[offset++] << 24;
      remappings.clear();
      remappings.reserve(remappings_length);
      for( unsigned i = 0; i < remappings_length; i++){
      remappings.emplace_back();
      offset += this->remappings.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/Resource"; };
    const char * getMD5(){ return "1234649cb96e9fac93f446b07c558b23"; };

  };

}
#endif