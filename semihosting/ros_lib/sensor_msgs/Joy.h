#ifndef _ROS_sensor_msgs_Joy_h
#define _ROS_sensor_msgs_Joy_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace sensor_msgs
{

  class Joy : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<float> axes;
      std::vector<int32_t> buttons;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned axes_length = axes.size();
      outbuffer[offset++] = (axes_length >> 0) & 0xFF;
      outbuffer[offset++] = (axes_length >> 8) & 0xFF;
      outbuffer[offset++] = (axes_length >> 16) & 0xFF;
      outbuffer[offset++] = (axes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < axes_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->axes[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->axes[i]);
      }
      unsigned buttons_length = buttons.size();
      outbuffer[offset++] = (buttons_length >> 0) & 0xFF;
      outbuffer[offset++] = (buttons_length >> 8) & 0xFF;
      outbuffer[offset++] = (buttons_length >> 16) & 0xFF;
      outbuffer[offset++] = (buttons_length >> 24) & 0xFF;
      for( unsigned i = 0; i < buttons_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->buttons[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->buttons[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned axes_length = inbuffer[offset++];
      axes_length |= inbuffer[offset++] << 8;
      axes_length |= inbuffer[offset++] << 16;
      axes_length |= inbuffer[offset++] << 24;
      axes.clear();
      axes.reserve(axes_length);
      for( unsigned i = 0; i < axes_length; i++){
      axes.emplace_back();
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
      this->axes.back() = u_.real;
      }
      offset += sizeof(this->axes.back());
      }
      unsigned buttons_length = inbuffer[offset++];
      buttons_length |= inbuffer[offset++] << 8;
      buttons_length |= inbuffer[offset++] << 16;
      buttons_length |= inbuffer[offset++] << 24;
      buttons.clear();
      buttons.reserve(buttons_length);
      for( unsigned i = 0; i < buttons_length; i++){
      buttons.emplace_back();
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
      this->buttons.back() = u_.real;
      }
      offset += sizeof(this->buttons.back());
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Joy"; };
    const char * getMD5(){ return "5a9ea5f83505693b71e785041e67a8bb"; };

  };

}
#endif