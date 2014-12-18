#ifndef _ROS_sensor_msgs_Image_h
#define _ROS_sensor_msgs_Image_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace sensor_msgs
{

  class Image : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t height = 0;
      uint32_t width = 0;
      char * encoding = nullptr;
      uint8_t is_bigendian = 0;
      uint32_t step = 0;
      std::vector<uint8_t> data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      {
      uint32_t length_ = strlen( (const char*) this->encoding);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->encoding, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->is_bigendian >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_bigendian);
      *(outbuffer + offset + 0) = (this->step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step);
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
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->encoding = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->is_bigendian =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->is_bigendian);
      this->step =  ((uint32_t) (*(inbuffer + offset)));
      this->step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->step);
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

    const char * getType(){ return "sensor_msgs/Image"; };
    const char * getMD5(){ return "060021388200f6f0f447d0fcd9c64743"; };

  };

}
#endif