#ifndef _ROS_kobuki_msgs_DigitalInputEvent_h
#define _ROS_kobuki_msgs_DigitalInputEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace kobuki_msgs
{

  class DigitalInputEvent : public ros::Msg
  {
    public:
      bool values[4];
      static const unsigned values_length = 4;

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
     return offset;
    }

    const char * getType(){ return "kobuki_msgs/DigitalInputEvent"; };
    const char * getMD5(){ return "93da823c8b121f8a3940ef3830c58e44"; };

  };

}
#endif