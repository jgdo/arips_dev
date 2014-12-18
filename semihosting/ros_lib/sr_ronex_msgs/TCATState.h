#ifndef _ROS_sr_ronex_msgs_TCATState_h
#define _ROS_sr_ronex_msgs_TCATState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_ronex_msgs/ReceiverData.h"
#include <vector>

namespace sr_ronex_msgs
{

  class TCATState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t sequence_number = 0;
      sr_ronex_msgs::ReceiverData received_data[4];
      static const unsigned received_data_length = 4;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sequence_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sequence_number);
      for( unsigned i = 0; i < 4; i++){
      offset += this->received_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->sequence_number =  ((uint16_t) (*(inbuffer + offset)));
      this->sequence_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sequence_number);
      for( unsigned i = 0; i < 4; i++){
      offset += this->received_data[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/TCATState"; };
    const char * getMD5(){ return "111c06a71da4f225240b922d7dd93b63"; };

  };

}
#endif