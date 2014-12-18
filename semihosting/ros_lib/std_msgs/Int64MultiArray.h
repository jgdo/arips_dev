#ifndef _ROS_std_msgs_Int64MultiArray_h
#define _ROS_std_msgs_Int64MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/MultiArrayLayout.h"
#include <vector>

namespace std_msgs
{

  class Int64MultiArray : public ros::Msg
  {
    public:
      std_msgs::MultiArrayLayout layout;
      std::vector<int64_t> data;

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
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.real = this->data[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_.base >> (8 * 7)) & 0xFF;
      }
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
      {
      union {
        int64_t real;
        uint64_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->data.back() = u_.real;
      }
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "std_msgs/Int64MultiArray"; };
    const char * getMD5(){ return "54865aa6c65be0448113a2afc6a49270"; };

  };

}
#endif