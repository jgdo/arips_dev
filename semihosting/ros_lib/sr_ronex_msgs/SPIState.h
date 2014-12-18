#ifndef _ROS_sr_ronex_msgs_SPIState_h
#define _ROS_sr_ronex_msgs_SPIState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "sr_ronex_msgs/SPIPacketIn.h"

namespace sr_ronex_msgs
{

  class SPIState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t command_type = 0;
      uint8_t pin_input_states_DIO[4];
      static const unsigned pin_input_states_DIO_length = 4;
      uint8_t pin_input_states_SOMI[4];
      static const unsigned pin_input_states_SOMI_length = 4;
      sr_ronex_msgs::SPIPacketIn spi_in[4];
      static const unsigned spi_in_length = 4;
      uint16_t analogue_in[6];
      static const unsigned analogue_in_length = 6;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->command_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command_type >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command_type);
      for( unsigned i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->pin_input_states_DIO[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pin_input_states_DIO[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->pin_input_states_SOMI[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pin_input_states_SOMI[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      offset += this->spi_in[i].serialize(outbuffer + offset);
      }
      for( unsigned i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->analogue_in[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analogue_in[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->analogue_in[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->command_type =  ((uint16_t) (*(inbuffer + offset)));
      this->command_type |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->command_type);
      for( unsigned i = 0; i < 4; i++){
      this->pin_input_states_DIO[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pin_input_states_DIO[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      this->pin_input_states_SOMI[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pin_input_states_SOMI[i]);
      }
      for( unsigned i = 0; i < 4; i++){
      offset += this->spi_in[i].deserialize(inbuffer + offset);
      }
      for( unsigned i = 0; i < 6; i++){
      this->analogue_in[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->analogue_in[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->analogue_in[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/SPIState"; };
    const char * getMD5(){ return "a93176a9c88e53cc58a927f7b4db311c"; };

  };

}
#endif