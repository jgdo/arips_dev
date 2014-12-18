#ifndef _ROS_rocon_interaction_msgs_Roles_h
#define _ROS_rocon_interaction_msgs_Roles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rocon_interaction_msgs
{

  class Roles : public ros::Msg
  {
    public:
      std::vector<char*> list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned list_length = list.size();
      outbuffer[offset++] = (list_length >> 0) & 0xFF;
      outbuffer[offset++] = (list_length >> 8) & 0xFF;
      outbuffer[offset++] = (list_length >> 16) & 0xFF;
      outbuffer[offset++] = (list_length >> 24) & 0xFF;
      for( unsigned i = 0; i < list_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->list[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->list[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned list_length = inbuffer[offset++];
      list_length |= inbuffer[offset++] << 8;
      list_length |= inbuffer[offset++] << 16;
      list_length |= inbuffer[offset++] << 24;
      list.clear();
      list.reserve(list_length);
      for( unsigned i = 0; i < list_length; i++){
      list.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->list.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/Roles"; };
    const char * getMD5(){ return "8e09fa9aad51508cfdcab3b64f048ce0"; };

  };

}
#endif