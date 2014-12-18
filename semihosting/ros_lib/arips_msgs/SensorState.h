#ifndef _ROS_arips_msgs_SensorState_h
#define _ROS_arips_msgs_SensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace arips_msgs
{

  class SensorState : public ros::Msg
  {
    public:
      std::vector<int16_t> ADC;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned ADC_length = ADC.size();
      outbuffer[offset++] = (ADC_length >> 0) & 0xFF;
      outbuffer[offset++] = (ADC_length >> 8) & 0xFF;
      outbuffer[offset++] = (ADC_length >> 16) & 0xFF;
      outbuffer[offset++] = (ADC_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ADC_length; i++){
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->ADC[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->ADC[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned ADC_length = inbuffer[offset++];
      ADC_length |= inbuffer[offset++] << 8;
      ADC_length |= inbuffer[offset++] << 16;
      ADC_length |= inbuffer[offset++] << 24;
      ADC.clear();
      ADC.reserve(ADC_length);
      for( unsigned i = 0; i < ADC_length; i++){
      ADC.emplace_back();
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ADC.back() = u_.real;
      }
      offset += sizeof(this->ADC.back());
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/SensorState"; };
    const char * getMD5(){ return "85629c8256dbbce843797ff45463c656"; };

  };

}
#endif