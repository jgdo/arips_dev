#ifndef _ROS_rospy_tutorials_Floats_h
#define _ROS_rospy_tutorials_Floats_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rospy_tutorials
{

  class Floats : public ros::Msg
  {
    public:
      std::vector<float> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->data[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned data_length = inbuffer[offset++];
      data_length |= inbuffer[offset++] << 8;
      data_length |= inbuffer[offset++] << 16;
      data_length |= inbuffer[offset++] << 24;
      data.clear();
      data.reserve(data_length);
      for( unsigned i = 0; i < data_length; i++){
      data.emplace_back();
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
      this->data.back() = u_.real;
      }
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "rospy_tutorials/Floats"; };
    const char * getMD5(){ return "420cd38b6b071cd49f2970c3e2cee511"; };

  };

}
#endif