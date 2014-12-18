#ifndef _ROS_cmvision_Blobs_h
#define _ROS_cmvision_Blobs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cmvision/Blob.h"
#include <vector>

namespace cmvision
{

  class Blobs : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t image_width = 0;
      uint32_t image_height = 0;
      uint32_t blob_count = 0;
      std::vector<cmvision::Blob> blobs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      *(outbuffer + offset + 0) = (this->image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      *(outbuffer + offset + 0) = (this->blob_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blob_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->blob_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->blob_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blob_count);
      unsigned blobs_length = blobs.size();
      outbuffer[offset++] = (blobs_length >> 0) & 0xFF;
      outbuffer[offset++] = (blobs_length >> 8) & 0xFF;
      outbuffer[offset++] = (blobs_length >> 16) & 0xFF;
      outbuffer[offset++] = (blobs_length >> 24) & 0xFF;
      for( unsigned i = 0; i < blobs_length; i++){
      offset += this->blobs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->image_width =  ((uint32_t) (*(inbuffer + offset)));
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_width);
      this->image_height =  ((uint32_t) (*(inbuffer + offset)));
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_height);
      this->blob_count =  ((uint32_t) (*(inbuffer + offset)));
      this->blob_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->blob_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->blob_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->blob_count);
      unsigned blobs_length = inbuffer[offset++];
      blobs_length |= inbuffer[offset++] << 8;
      blobs_length |= inbuffer[offset++] << 16;
      blobs_length |= inbuffer[offset++] << 24;
      blobs.clear();
      blobs.reserve(blobs_length);
      for( unsigned i = 0; i < blobs_length; i++){
      blobs.emplace_back();
      offset += this->blobs.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "cmvision/Blobs"; };
    const char * getMD5(){ return "9c46147119a8e441f5446a5432b95bda"; };

  };

}
#endif