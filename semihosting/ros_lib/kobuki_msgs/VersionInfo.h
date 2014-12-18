#ifndef _ROS_kobuki_msgs_VersionInfo_h
#define _ROS_kobuki_msgs_VersionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace kobuki_msgs
{

  class VersionInfo : public ros::Msg
  {
    public:
      char * hardware = nullptr;
      char * firmware = nullptr;
      char * software = nullptr;
      std::vector<uint32_t> udid;
      uint64_t features = 0;
      enum { SMOOTH_MOVE_START =  0000000000000001 };
      enum { GYROSCOPE_3D_DATA =  0000000000000002 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->hardware);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->firmware);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->firmware, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->software);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->software, length_);
      offset += length_;
      }
      unsigned udid_length = udid.size();
      outbuffer[offset++] = (udid_length >> 0) & 0xFF;
      outbuffer[offset++] = (udid_length >> 8) & 0xFF;
      outbuffer[offset++] = (udid_length >> 16) & 0xFF;
      outbuffer[offset++] = (udid_length >> 24) & 0xFF;
      for( unsigned i = 0; i < udid_length; i++){
      *(outbuffer + offset + 0) = (this->udid[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->udid[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->udid[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->udid[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->udid[i]);
      }
      {
      union {
        uint64_t real;
        uint32_t base;
      } u_;
      u_.real = this->features;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->features);
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
      this->hardware = (char *)(inbuffer + offset-1);
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
      this->firmware = (char *)(inbuffer + offset-1);
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
      this->software = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned udid_length = inbuffer[offset++];
      udid_length |= inbuffer[offset++] << 8;
      udid_length |= inbuffer[offset++] << 16;
      udid_length |= inbuffer[offset++] << 24;
      udid.clear();
      udid.reserve(udid_length);
      for( unsigned i = 0; i < udid_length; i++){
      udid.emplace_back();
      this->udid.back() =  ((uint32_t) (*(inbuffer + offset)));
      this->udid.back() |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->udid.back() |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->udid.back() |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->udid.back());
      }
      {
      union {
        uint64_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->features = u_.real;
      }
      offset += sizeof(this->features);
     return offset;
    }

    const char * getType(){ return "kobuki_msgs/VersionInfo"; };
    const char * getMD5(){ return "3dc0ce6edd49be1fc86730f4a4a21861"; };

  };

}
#endif