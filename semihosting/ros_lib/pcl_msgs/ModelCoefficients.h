#ifndef _ROS_pcl_msgs_ModelCoefficients_h
#define _ROS_pcl_msgs_ModelCoefficients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace pcl_msgs
{

  class ModelCoefficients : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<float> values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "pcl_msgs/ModelCoefficients"; };
    const char * getMD5(){ return "ca27dea75e72cb894cd36f9e5005e93e"; };

  };

}
#endif