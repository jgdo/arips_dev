#ifndef _ROS_sensor_msgs_ChannelFloat32_h
#define _ROS_sensor_msgs_ChannelFloat32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace sensor_msgs
{

  class ChannelFloat32 : public ros::Msg
  {
    public:
      char * name = nullptr;
      std::vector<float> values;

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
      unsigned values_length = values.size();
      outbuffer[offset++] = (values_length >> 0) & 0xFF;
      outbuffer[offset++] = (values_length >> 8) & 0xFF;
      outbuffer[offset++] = (values_length >> 16) & 0xFF;
      outbuffer[offset++] = (values_length >> 24) & 0xFF;
      for( unsigned i = 0; i < values_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->values[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->values[i]);
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
      unsigned values_length = inbuffer[offset++];
      values_length |= inbuffer[offset++] << 8;
      values_length |= inbuffer[offset++] << 16;
      values_length |= inbuffer[offset++] << 24;
      values.clear();
      values.reserve(values_length);
      for( unsigned i = 0; i < values_length; i++){
      values.emplace_back();
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->values.back() = u_.real;
      }
      offset += sizeof(this->values.back());
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/ChannelFloat32"; };
    const char * getMD5(){ return "3d40139cdd33dfedcb71ffeeeb42ae7f"; };

  };

}
#endif