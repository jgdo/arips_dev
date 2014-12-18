#ifndef _ROS_sr_ronex_msgs_SPIPacketIn_h
#define _ROS_sr_ronex_msgs_SPIPacketIn_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace sr_ronex_msgs
{

  class SPIPacketIn : public ros::Msg
  {
    public:
      uint8_t data[32];
      static const unsigned data_length = 32;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( unsigned i = 0; i < 32; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( unsigned i = 0; i < 32; i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/SPIPacketIn"; };
    const char * getMD5(){ return "581a2da7850358e28584a5446af8a890"; };

  };

}
#endif