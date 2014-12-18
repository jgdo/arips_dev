#ifndef _ROS_SERVICE_GetInteractions_h
#define _ROS_SERVICE_GetInteractions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "rocon_interaction_msgs/Interaction.h"

namespace rocon_interaction_msgs
{

static const char GETINTERACTIONS[] = "rocon_interaction_msgs/GetInteractions";

  class GetInteractionsRequest : public ros::Msg
  {
    public:
      std::vector<char*> roles;
      char * uri = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned roles_length = roles.size();
      outbuffer[offset++] = (roles_length >> 0) & 0xFF;
      outbuffer[offset++] = (roles_length >> 8) & 0xFF;
      outbuffer[offset++] = (roles_length >> 16) & 0xFF;
      outbuffer[offset++] = (roles_length >> 24) & 0xFF;
      for( unsigned i = 0; i < roles_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->roles[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->roles[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->uri);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned roles_length = inbuffer[offset++];
      roles_length |= inbuffer[offset++] << 8;
      roles_length |= inbuffer[offset++] << 16;
      roles_length |= inbuffer[offset++] << 24;
      roles.clear();
      roles.reserve(roles_length);
      for( unsigned i = 0; i < roles_length; i++){
      roles.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->roles.back() = (char *)(inbuffer + offset-1);
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
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "7729678b2d98f5eb8e7358aaf9d23bcb"; };

  };

  class GetInteractionsResponse : public ros::Msg
  {
    public:
      std::vector<rocon_interaction_msgs::Interaction> interactions;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned interactions_length = interactions.size();
      outbuffer[offset++] = (interactions_length >> 0) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 8) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 16) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < interactions_length; i++){
      offset += this->interactions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned interactions_length = inbuffer[offset++];
      interactions_length |= inbuffer[offset++] << 8;
      interactions_length |= inbuffer[offset++] << 16;
      interactions_length |= inbuffer[offset++] << 24;
      interactions.clear();
      interactions.reserve(interactions_length);
      for( unsigned i = 0; i < interactions_length; i++){
      interactions.emplace_back();
      offset += this->interactions.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "d0d6f5a671c00eccc974dfaa7d85d865"; };

  };

  class GetInteractions {
    public:
    typedef GetInteractionsRequest Request;
    typedef GetInteractionsResponse Response;
  };

}
#endif
