#ifndef _ROS_kobuki_msgs_DockInfraRed_h
#define _ROS_kobuki_msgs_DockInfraRed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace kobuki_msgs
{

  class DockInfraRed : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<uint8_t> data;
      enum { NEAR_LEFT =   1 };
      enum { NEAR_CENTER =   2 };
      enum { NEAR_RIGHT =   4 };
      enum { FAR_LEFT =  16 };
      enum { FAR_CENTER =   8 };
      enum { FAR_RIGHT =  32 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned data_length = inbuffer[offset++];
      data_length |= inbuffer[offset++] << 8;
      data_length |= inbuffer[offset++] << 16;
      data_length |= inbuffer[offset++] << 24;
      data.clear();
      data.reserve(data_length);
      for( unsigned i = 0; i < data_length; i++){
      data.emplace_back();
      this->data.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "kobuki_msgs/DockInfraRed"; };
    const char * getMD5(){ return "a3d77f7d15e50579473dcc24e9b97b34"; };

  };

}
#endif