#ifndef _ROS_kobuki_msgs_DigitalOutput_h
#define _ROS_kobuki_msgs_DigitalOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace kobuki_msgs
{

  class DigitalOutput : public ros::Msg
  {
    public:
      bool values[4];
      static const unsigned values_length = 4;
      bool mask[4];
      static const unsigned mask_length = 4;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( unsigned i = 0; i < 4; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->values[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->values[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->mask[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->mask[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( unsigned i = 0; i < 4; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->values[i] = u_.real;
      }
      offset += sizeof(this->values[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mask[i] = u_.real;
      }
      offset += sizeof(this->mask[i]);
      }
     return offset;
    }

    const char * getType(){ return "kobuki_msgs/DigitalOutput"; };
    const char * getMD5(){ return "1e97cd7f196a0270516b506e8bf29ca2"; };

  };

}
#endif