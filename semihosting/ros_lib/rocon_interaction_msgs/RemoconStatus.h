#ifndef _ROS_rocon_interaction_msgs_RemoconStatus_h
#define _ROS_rocon_interaction_msgs_RemoconStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/PlatformInfo.h"

namespace rocon_interaction_msgs
{

  class RemoconStatus : public ros::Msg
  {
    public:
      rocon_std_msgs::PlatformInfo platform_info;
      char * uuid = nullptr;
      bool running_app = 0;
      int32_t hash = 0;
      char * version = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->platform_info.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->uuid);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->running_app;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->running_app);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->hash;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->hash);
      {
      uint32_t length_ = strlen( (const char*) this->version);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->platform_info.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->running_app = u_.real;
      }
      offset += sizeof(this->running_app);
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
      this->hash = u_.real;
      }
      offset += sizeof(this->hash);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/RemoconStatus"; };
    const char * getMD5(){ return "0f9e0cb24dc73c1b1b1abd41a05afebb"; };

  };

}
#endif