#ifndef _ROS_pr2_msgs_PressureState_h
#define _ROS_pr2_msgs_PressureState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace pr2_msgs
{

  class PressureState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<int16_t> l_finger_tip;
      std::vector<int16_t> r_finger_tip;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned l_finger_tip_length = l_finger_tip.size();
      outbuffer[offset++] = (l_finger_tip_length >> 0) & 0xFF;
      outbuffer[offset++] = (l_finger_tip_length >> 8) & 0xFF;
      outbuffer[offset++] = (l_finger_tip_length >> 16) & 0xFF;
      outbuffer[offset++] = (l_finger_tip_length >> 24) & 0xFF;
      for( unsigned i = 0; i < l_finger_tip_length; i++){
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->l_finger_tip[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->l_finger_tip[i]);
      }
      unsigned r_finger_tip_length = r_finger_tip.size();
      outbuffer[offset++] = (r_finger_tip_length >> 0) & 0xFF;
      outbuffer[offset++] = (r_finger_tip_length >> 8) & 0xFF;
      outbuffer[offset++] = (r_finger_tip_length >> 16) & 0xFF;
      outbuffer[offset++] = (r_finger_tip_length >> 24) & 0xFF;
      for( unsigned i = 0; i < r_finger_tip_length; i++){
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->r_finger_tip[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->r_finger_tip[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned l_finger_tip_length = inbuffer[offset++];
      l_finger_tip_length |= inbuffer[offset++] << 8;
      l_finger_tip_length |= inbuffer[offset++] << 16;
      l_finger_tip_length |= inbuffer[offset++] << 24;
      l_finger_tip.clear();
      l_finger_tip.reserve(l_finger_tip_length);
      for( unsigned i = 0; i < l_finger_tip_length; i++){
      l_finger_tip.emplace_back();
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->l_finger_tip.back() = u_.real;
      }
      offset += sizeof(this->l_finger_tip.back());
      }
      unsigned r_finger_tip_length = inbuffer[offset++];
      r_finger_tip_length |= inbuffer[offset++] << 8;
      r_finger_tip_length |= inbuffer[offset++] << 16;
      r_finger_tip_length |= inbuffer[offset++] << 24;
      r_finger_tip.clear();
      r_finger_tip.reserve(r_finger_tip_length);
      for( unsigned i = 0; i < r_finger_tip_length; i++){
      r_finger_tip.emplace_back();
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->r_finger_tip.back() = u_.real;
      }
      offset += sizeof(this->r_finger_tip.back());
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/PressureState"; };
    const char * getMD5(){ return "756fb3b75fa8884524fd0789a78eb04b"; };

  };

}
#endif