#ifndef _ROS_std_msgs_UInt32MultiArray_h
#define _ROS_std_msgs_UInt32MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/MultiArrayLayout.h"
#include <vector>

namespace std_msgs
{

  class UInt32MultiArray : public ros::Msg
  {
    public:
      std_msgs::MultiArrayLayout layout;
      std::vector<uint32_t> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->layout.serialize(outbuffer + offset);
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->layout.deserialize(inbuffer + offset);
      unsigned data_length = inbuffer[offset++];
      data_length |= inbuffer[offset++] << 8;
      data_length |= inbuffer[offset++] << 16;
      data_length |= inbuffer[offset++] << 24;
      data.clear();
      data.reserve(data_length);
      for( unsigned i = 0; i < data_length; i++){
      data.emplace_back();
      this->data.back() =  ((uint32_t) (*(inbuffer + offset)));
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "std_msgs/UInt32MultiArray"; };
    const char * getMD5(){ return "4d6a180abc9be191b96a7eda6c8a233d"; };

  };

}
#endif