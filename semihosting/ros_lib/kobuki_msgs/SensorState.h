#ifndef _ROS_kobuki_msgs_SensorState_h
#define _ROS_kobuki_msgs_SensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace kobuki_msgs
{

  class SensorState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t time_stamp = 0;
      uint8_t bumper = 0;
      uint8_t wheel_drop = 0;
      uint8_t cliff = 0;
      uint16_t left_encoder = 0;
      uint16_t right_encoder = 0;
      int8_t left_pwm = 0;
      int8_t right_pwm = 0;
      uint8_t buttons = 0;
      uint8_t charger = 0;
      uint8_t battery = 0;
      std::vector<uint16_t> bottom;
      std::vector<uint8_t> current;
      uint8_t over_current = 0;
      uint16_t digital_input = 0;
      std::vector<uint16_t> analog_input;
      enum { BUMPER_RIGHT =  1 };
      enum { BUMPER_CENTRE =  2 };
      enum { BUMPER_LEFT =  4 };
      enum { WHEEL_DROP_RIGHT =  1 };
      enum { WHEEL_DROP_LEFT =  2 };
      enum { CLIFF_RIGHT =  1 };
      enum { CLIFF_CENTRE =  2 };
      enum { CLIFF_LEFT =  4 };
      enum { BUTTON0 =  1 };
      enum { BUTTON1 =  2 };
      enum { BUTTON2 =  4 };
      enum { DISCHARGING =  0 };
      enum { DOCKING_CHARGED =  2 };
      enum { DOCKING_CHARGING =  6 };
      enum { ADAPTER_CHARGED =  18 };
      enum { ADAPTER_CHARGING =  22 };
      enum { OVER_CURRENT_LEFT_WHEEL =  1 };
      enum { OVER_CURRENT_RIGHT_WHEEL =  2 };
      enum { OVER_CURRENT_BOTH_WHEELS =  3 };
      enum { DIGITAL_INPUT0 =  1 };
      enum { DIGITAL_INPUT1 =  2 };
      enum { DIGITAL_INPUT2 =  4 };
      enum { DIGITAL_INPUT3 =  8 };
      enum { DB25_TEST_BOARD_CONNECTED =  64 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->time_stamp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp >> (8 * 1)) & 0xFF;
      offset += sizeof(this->time_stamp);
      *(outbuffer + offset + 0) = (this->bumper >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bumper);
      *(outbuffer + offset + 0) = (this->wheel_drop >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wheel_drop);
      *(outbuffer + offset + 0) = (this->cliff >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff);
      *(outbuffer + offset + 0) = (this->left_encoder >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_encoder >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_encoder);
      *(outbuffer + offset + 0) = (this->right_encoder >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_encoder >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_encoder);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->left_pwm;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->left_pwm);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->right_pwm;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->right_pwm);
      *(outbuffer + offset + 0) = (this->buttons >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons);
      *(outbuffer + offset + 0) = (this->charger >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger);
      *(outbuffer + offset + 0) = (this->battery >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery);
      unsigned bottom_length = bottom.size();
      outbuffer[offset++] = (bottom_length >> 0) & 0xFF;
      outbuffer[offset++] = (bottom_length >> 8) & 0xFF;
      outbuffer[offset++] = (bottom_length >> 16) & 0xFF;
      outbuffer[offset++] = (bottom_length >> 24) & 0xFF;
      for( unsigned i = 0; i < bottom_length; i++){
      *(outbuffer + offset + 0) = (this->bottom[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bottom[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->bottom[i]);
      }
      unsigned current_length = current.size();
      outbuffer[offset++] = (current_length >> 0) & 0xFF;
      outbuffer[offset++] = (current_length >> 8) & 0xFF;
      outbuffer[offset++] = (current_length >> 16) & 0xFF;
      outbuffer[offset++] = (current_length >> 24) & 0xFF;
      for( unsigned i = 0; i < current_length; i++){
      *(outbuffer + offset + 0) = (this->current[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current[i]);
      }
      *(outbuffer + offset + 0) = (this->over_current >> (8 * 0)) & 0xFF;
      offset += sizeof(this->over_current);
      *(outbuffer + offset + 0) = (this->digital_input >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->digital_input >> (8 * 1)) & 0xFF;
      offset += sizeof(this->digital_input);
      unsigned analog_input_length = analog_input.size();
      outbuffer[offset++] = (analog_input_length >> 0) & 0xFF;
      outbuffer[offset++] = (analog_input_length >> 8) & 0xFF;
      outbuffer[offset++] = (analog_input_length >> 16) & 0xFF;
      outbuffer[offset++] = (analog_input_length >> 24) & 0xFF;
      for( unsigned i = 0; i < analog_input_length; i++){
      *(outbuffer + offset + 0) = (this->analog_input[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analog_input[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->analog_input[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->time_stamp =  ((uint16_t) (*(inbuffer + offset)));
      this->time_stamp |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->time_stamp);
      this->bumper =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bumper);
      this->wheel_drop =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wheel_drop);
      this->cliff =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cliff);
      this->left_encoder =  ((uint16_t) (*(inbuffer + offset)));
      this->left_encoder |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->left_encoder);
      this->right_encoder =  ((uint16_t) (*(inbuffer + offset)));
      this->right_encoder |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_encoder);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_pwm = u_.real;
      }
      offset += sizeof(this->left_pwm);
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_pwm = u_.real;
      }
      offset += sizeof(this->right_pwm);
      this->buttons =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->buttons);
      this->charger =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charger);
      this->battery =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->battery);
      unsigned bottom_length = inbuffer[offset++];
      bottom_length |= inbuffer[offset++] << 8;
      bottom_length |= inbuffer[offset++] << 16;
      bottom_length |= inbuffer[offset++] << 24;
      bottom.clear();
      bottom.reserve(bottom_length);
      for( unsigned i = 0; i < bottom_length; i++){
      bottom.emplace_back();
      this->bottom.back() =  ((uint16_t) (*(inbuffer + offset)));
      this->bottom.back() |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->bottom.back());
      }
      unsigned current_length = inbuffer[offset++];
      current_length |= inbuffer[offset++] << 8;
      current_length |= inbuffer[offset++] << 16;
      current_length |= inbuffer[offset++] << 24;
      current.clear();
      current.reserve(current_length);
      for( unsigned i = 0; i < current_length; i++){
      current.emplace_back();
      this->current.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current.back());
      }
      this->over_current =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->over_current);
      this->digital_input =  ((uint16_t) (*(inbuffer + offset)));
      this->digital_input |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->digital_input);
      unsigned analog_input_length = inbuffer[offset++];
      analog_input_length |= inbuffer[offset++] << 8;
      analog_input_length |= inbuffer[offset++] << 16;
      analog_input_length |= inbuffer[offset++] << 24;
      analog_input.clear();
      analog_input.reserve(analog_input_length);
      for( unsigned i = 0; i < analog_input_length; i++){
      analog_input.emplace_back();
      this->analog_input.back() =  ((uint16_t) (*(inbuffer + offset)));
      this->analog_input.back() |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->analog_input.back());
      }
     return offset;
    }

    const char * getType(){ return "kobuki_msgs/SensorState"; };
    const char * getMD5(){ return "430a4bfd78449c8740bfef32b26613a6"; };

  };

}
#endif