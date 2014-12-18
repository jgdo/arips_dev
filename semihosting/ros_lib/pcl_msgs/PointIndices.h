#ifndef _ROS_pcl_msgs_PointIndices_h
#define _ROS_pcl_msgs_PointIndices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace pcl_msgs
{

  class PointIndices : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<int32_t> indices;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned indices_length = indices.size();
      outbuffer[offset++] = (indices_length >> 0) & 0xFF;
      outbuffer[offset++] = (indices_length >> 8) & 0xFF;
      outbuffer[offset++] = (indices_length >> 16) & 0xFF;
      outbuffer[offset++] = (indices_length >> 24) & 0xFF;
      for( unsigned i = 0; i < indices_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->indices[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->indices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned indices_length = inbuffer[offset++];
      indices_length |= inbuffer[offset++] << 8;
      indices_length |= inbuffer[offset++] << 16;
      indices_length |= inbuffer[offset++] << 24;
      indices.clear();
      indices.reserve(indices_length);
      for( unsigned i = 0; i < indices_length; i++){
      indices.emplace_back();
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->indices.back() = u_.real;
      }
      offset += sizeof(this->indices.back());
      }
     return offset;
    }

    const char * getType(){ return "pcl_msgs/PointIndices"; };
    const char * getMD5(){ return "458c7998b7eaf99908256472e273b3d4"; };

  };

}
#endif