#ifndef _ROS_scheduler_msgs_CurrentStatus_h
#define _ROS_scheduler_msgs_CurrentStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include <vector>

namespace scheduler_msgs
{

  class CurrentStatus : public ros::Msg
  {
    public:
      char * uri = nullptr;
      uint8_t status = 0;
      uuid_msgs::UniqueID owner;
      int16_t priority = 0;
      std::vector<char*> rapps;
      enum { AVAILABLE =  0    };
      enum { ALLOCATED =  1    };
      enum { MISSING =  2    };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->uri);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->owner.serialize(outbuffer + offset);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->priority;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->priority);
      unsigned rapps_length = rapps.size();
      outbuffer[offset++] = (rapps_length >> 0) & 0xFF;
      outbuffer[offset++] = (rapps_length >> 8) & 0xFF;
      outbuffer[offset++] = (rapps_length >> 16) & 0xFF;
      outbuffer[offset++] = (rapps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < rapps_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->rapps[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapps[i], length_);
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
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      offset += this->owner.deserialize(inbuffer + offset);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_.real;
      }
      offset += sizeof(this->priority);
      unsigned rapps_length = inbuffer[offset++];
      rapps_length |= inbuffer[offset++] << 8;
      rapps_length |= inbuffer[offset++] << 16;
      rapps_length |= inbuffer[offset++] << 24;
      rapps.clear();
      rapps.reserve(rapps_length);
      for( unsigned i = 0; i < rapps_length; i++){
      rapps.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->rapps.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/CurrentStatus"; };
    const char * getMD5(){ return "12d978458e0f7365b1048dc85c792bd1"; };

  };

}
#endif