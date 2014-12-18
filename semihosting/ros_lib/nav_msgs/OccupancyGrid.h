#ifndef _ROS_nav_msgs_OccupancyGrid_h
#define _ROS_nav_msgs_OccupancyGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/MapMetaData.h"
#include <vector>

namespace nav_msgs
{

  class OccupancyGrid : public ros::Msg
  {
    public:
      std_msgs::Header header;
      nav_msgs::MapMetaData info;
      std::vector<int8_t> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->data[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
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
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data.back() = u_.real;
      }
      offset += sizeof(this->data.back());
      }
     return offset;
    }

    const char * getType(){ return "nav_msgs/OccupancyGrid"; };
    const char * getMD5(){ return "3381f2d731d4076ec5c71b0759edbe4e"; };

  };

}
#endif