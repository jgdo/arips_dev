#ifndef _ROS_sr_ronex_msgs_GeneralIOState_h
#define _ROS_sr_ronex_msgs_GeneralIOState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace sr_ronex_msgs
{

  class GeneralIOState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<bool> digital;
      std::vector<uint16_t> analogue;
      uint16_t pwm_clock_divider = 0;
      std::vector<bool> input_mode;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned digital_length = digital.size();
      outbuffer[offset++] = (digital_length >> 0) & 0xFF;
      outbuffer[offset++] = (digital_length >> 8) & 0xFF;
      outbuffer[offset++] = (digital_length >> 16) & 0xFF;
      outbuffer[offset++] = (digital_length >> 24) & 0xFF;
      for( unsigned i = 0; i < digital_length; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->digital[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->digital[i]);
      }
      unsigned analogue_length = analogue.size();
      outbuffer[offset++] = (analogue_length >> 0) & 0xFF;
      outbuffer[offset++] = (analogue_length >> 8) & 0xFF;
      outbuffer[offset++] = (analogue_length >> 16) & 0xFF;
      outbuffer[offset++] = (analogue_length >> 24) & 0xFF;
      for( unsigned i = 0; i < analogue_length; i++){
      *(outbuffer + offset + 0) = (this->analogue[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analogue[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->analogue[i]);
      }
      *(outbuffer + offset + 0) = (this->pwm_clock_divider >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm_clock_divider >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_clock_divider);
      unsigned input_mode_length = input_mode.size();
      outbuffer[offset++] = (input_mode_length >> 0) & 0xFF;
      outbuffer[offset++] = (input_mode_length >> 8) & 0xFF;
      outbuffer[offset++] = (input_mode_length >> 16) & 0xFF;
      outbuffer[offset++] = (input_mode_length >> 24) & 0xFF;
      for( unsigned i = 0; i < input_mode_length; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->input_mode[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->input_mode[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned digital_length = inbuffer[offset++];
      digital_length |= inbuffer[offset++] << 8;
      digital_length |= inbuffer[offset++] << 16;
      digital_length |= inbuffer[offset++] << 24;
      digital.clear();
      digital.reserve(digital_length);
      for( unsigned i = 0; i < digital_length; i++){
      digital.emplace_back();
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital.back() = u_.real;
      }
      offset += sizeof(this->digital.back());
      }
      unsigned analogue_length = inbuffer[offset++];
      analogue_length |= inbuffer[offset++] << 8;
      analogue_length |= inbuffer[offset++] << 16;
      analogue_length |= inbuffer[offset++] << 24;
      analogue.clear();
      analogue.reserve(analogue_length);
      for( unsigned i = 0; i < analogue_length; i++){
      analogue.emplace_back();
      this->analogue.back() =  ((uint16_t) (*(inbuffer + offset)));
      this->analogue.back() |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->analogue.back());
      }
      this->pwm_clock_divider =  ((uint16_t) (*(inbuffer + offset)));
      this->pwm_clock_divider |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pwm_clock_divider);
      unsigned input_mode_length = inbuffer[offset++];
      input_mode_length |= inbuffer[offset++] << 8;
      input_mode_length |= inbuffer[offset++] << 16;
      input_mode_length |= inbuffer[offset++] << 24;
      input_mode.clear();
      input_mode.reserve(input_mode_length);
      for( unsigned i = 0; i < input_mode_length; i++){
      input_mode.emplace_back();
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->input_mode.back() = u_.real;
      }
      offset += sizeof(this->input_mode.back());
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/GeneralIOState"; };
    const char * getMD5(){ return "0c3ee57b67f445415be2df465ebee265"; };

  };

}
#endif