#ifndef _ROS_SERVICE_StartApp_h
#define _ROS_SERVICE_StartApp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "rocon_app_manager_msgs/Remapping.h"

namespace rocon_app_manager_msgs
{

static const char STARTAPP[] = "rocon_app_manager_msgs/StartApp";

  class StartAppRequest : public ros::Msg
  {
    public:
      char * name = nullptr;
      std::vector<rocon_app_manager_msgs::Remapping> remappings;

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
      this->name = (char *)(inbuffer + offset-1);
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

    const char * getType(){ return STARTAPP; };
    const char * getMD5(){ return "52a705a1e5933de18edbae79e2aafe49"; };

  };

  class StartAppResponse : public ros::Msg
  {
    public:
      bool started = 0;
      int32_t error_code = 0;
      char * message = nullptr;
      char * app_namespace = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->started;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->started);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->error_code;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->error_code);
      {
      uint32_t length_ = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->app_namespace);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->app_namespace, length_);
      offset += length_;
      }
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
      this->started = u_.real;
      }
      offset += sizeof(this->started);
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
      this->error_code = u_.real;
      }
      offset += sizeof(this->error_code);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->app_namespace = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return STARTAPP; };
    const char * getMD5(){ return "d47dedd876ba5df1daf4654018d1329b"; };

  };

  class StartApp {
    public:
    typedef StartAppRequest Request;
    typedef StartAppResponse Response;
  };

}
#endif
