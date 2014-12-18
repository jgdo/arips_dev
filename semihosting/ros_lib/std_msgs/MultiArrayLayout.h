#ifndef _ROS_std_msgs_MultiArrayLayout_h
#define _ROS_std_msgs_MultiArrayLayout_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/MultiArrayDimension.h"
#include <vector>

namespace std_msgs
{

  class MultiArrayLayout : public ros::Msg
  {
    public:
      std::vector<std_msgs::MultiArrayDimension> dim;
      uint32_t data_offset = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned dim_length = dim.size();
      outbuffer[offset++] = (dim_length >> 0) & 0xFF;
      outbuffer[offset++] = (dim_length >> 8) & 0xFF;
      outbuffer[offset++] = (dim_length >> 16) & 0xFF;
      outbuffer[offset++] = (dim_length >> 24) & 0xFF;
      for( unsigned i = 0; i < dim_length; i++){
      offset += this->dim[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->data_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned dim_length = inbuffer[offset++];
      dim_length |= inbuffer[offset++] << 8;
      dim_length |= inbuffer[offset++] << 16;
      dim_length |= inbuffer[offset++] << 24;
      dim.clear();
      dim.reserve(dim_length);
      for( unsigned i = 0; i < dim_length; i++){
      dim.emplace_back();
      offset += this->dim.back().deserialize(inbuffer + offset);
      }
      this->data_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data_offset);
     return offset;
    }

    const char * getType(){ return "std_msgs/MultiArrayLayout"; };
    const char * getMD5(){ return "0fed2a11c13e11c5571b4e2a995a91a3"; };

  };

}
#endif