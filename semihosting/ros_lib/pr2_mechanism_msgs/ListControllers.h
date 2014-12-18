#ifndef _ROS_SERVICE_ListControllers_h
#define _ROS_SERVICE_ListControllers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace pr2_mechanism_msgs
{

static const char LISTCONTROLLERS[] = "pr2_mechanism_msgs/ListControllers";

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
      std::vector<char*> controllers;
      std::vector<char*> state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned controllers_length = controllers.size();
      outbuffer[offset++] = (controllers_length >> 0) & 0xFF;
      outbuffer[offset++] = (controllers_length >> 8) & 0xFF;
      outbuffer[offset++] = (controllers_length >> 16) & 0xFF;
      outbuffer[offset++] = (controllers_length >> 24) & 0xFF;
      for( unsigned i = 0; i < controllers_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->controllers[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->controllers[i], length_);
      offset += length_;
      }
      }
      unsigned state_length = state.size();
      outbuffer[offset++] = (state_length >> 0) & 0xFF;
      outbuffer[offset++] = (state_length >> 8) & 0xFF;
      outbuffer[offset++] = (state_length >> 16) & 0xFF;
      outbuffer[offset++] = (state_length >> 24) & 0xFF;
      for( unsigned i = 0; i < state_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->state[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->state[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned controllers_length = inbuffer[offset++];
      controllers_length |= inbuffer[offset++] << 8;
      controllers_length |= inbuffer[offset++] << 16;
      controllers_length |= inbuffer[offset++] << 24;
      controllers.clear();
      controllers.reserve(controllers_length);
      for( unsigned i = 0; i < controllers_length; i++){
      controllers.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->controllers.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned state_length = inbuffer[offset++];
      state_length |= inbuffer[offset++] << 8;
      state_length |= inbuffer[offset++] << 16;
      state_length |= inbuffer[offset++] << 24;
      state.clear();
      state.reserve(state_length);
      for( unsigned i = 0; i < state_length; i++){
      state.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->state.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERS; };
    const char * getMD5(){ return "39c8d39516aed5c7d76284ac06c220e5"; };

  };

  class ListControllers {
    public:
    typedef ListControllersRequest Request;
    typedef ListControllersResponse Response;
  };

}
#endif
