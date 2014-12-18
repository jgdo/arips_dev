#ifndef _ROS_SERVICE_SwitchController_h
#define _ROS_SERVICE_SwitchController_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace controller_manager_msgs
{

static const char SWITCHCONTROLLER[] = "controller_manager_msgs/SwitchController";

  class SwitchControllerRequest : public ros::Msg
  {
    public:
      std::vector<char*> start_controllers;
      std::vector<char*> stop_controllers;
      int32_t strictness = 0;
      enum { BEST_EFFORT = 1 };
      enum { STRICT = 2 };

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
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->strictness;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->strictness);
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
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strictness = u_.real;
      }
      offset += sizeof(this->strictness);
     return offset;
    }

    const char * getType(){ return SWITCHCONTROLLER; };
    const char * getMD5(){ return "434da54adc434a5af5743ed711fd6ba1"; };

  };

  class SwitchControllerResponse : public ros::Msg
  {
    public:
      bool ok = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->ok;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_.real;
      }
      offset += sizeof(this->ok);
     return offset;
    }

    const char * getType(){ return SWITCHCONTROLLER; };
    const char * getMD5(){ return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class SwitchController {
    public:
    typedef SwitchControllerRequest Request;
    typedef SwitchControllerResponse Response;
  };

}
#endif
