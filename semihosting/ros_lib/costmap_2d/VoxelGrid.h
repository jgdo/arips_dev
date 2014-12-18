#ifndef _ROS_costmap_2d_VoxelGrid_h
#define _ROS_costmap_2d_VoxelGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>
#include "geometry_msgs/Point32.h"
#include "geometry_msgs/Vector3.h"

namespace costmap_2d
{

  class VoxelGrid : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<uint32_t> data;
      geometry_msgs::Point32 origin;
      geometry_msgs::Vector3 resolutions;
      uint32_t size_x = 0;
      uint32_t size_y = 0;
      uint32_t size_z = 0;

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
      *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->resolutions.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->size_x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_x);
      *(outbuffer + offset + 0) = (this->size_y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_y);
      *(outbuffer + offset + 0) = (this->size_z >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_z >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_z >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_z >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_z);
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
      this->data.back() =  ((uint32_t) (*(inbuffer + offset)));
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.back() |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.back());
      }
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->resolutions.deserialize(inbuffer + offset);
      this->size_x =  ((uint32_t) (*(inbuffer + offset)));
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_x);
      this->size_y =  ((uint32_t) (*(inbuffer + offset)));
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_y);
      this->size_z =  ((uint32_t) (*(inbuffer + offset)));
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_z);
     return offset;
    }

    const char * getType(){ return "costmap_2d/VoxelGrid"; };
    const char * getMD5(){ return "48a040827e1322073d78ece5a497029c"; };

  };

}
#endif