#ifndef _ROS_sensor_msgs_PointCloud2_h
#define _ROS_sensor_msgs_PointCloud2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointField.h"
#include <vector>

namespace sensor_msgs
{

  class PointCloud2 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t height = 0;
      uint32_t width = 0;
      std::vector<sensor_msgs::PointField> fields;
      bool is_bigendian = 0;
      uint32_t point_step = 0;
      uint32_t row_step = 0;
      std::vector<uint8_t> data;
      bool is_dense = 0;

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
      unsigned fields_length = fields.size();
      outbuffer[offset++] = (fields_length >> 0) & 0xFF;
      outbuffer[offset++] = (fields_length >> 8) & 0xFF;
      outbuffer[offset++] = (fields_length >> 16) & 0xFF;
      outbuffer[offset++] = (fields_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fields_length; i++){
      offset += this->fields[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_bigendian;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_bigendian);
      *(outbuffer + offset + 0) = (this->point_step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_step);
      *(outbuffer + offset + 0) = (this->row_step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->row_step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->row_step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->row_step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->row_step);
      unsigned data_length = data.size();
      outbuffer[offset++] = (data_length >> 0) & 0xFF;
      outbuffer[offset++] = (data_length >> 8) & 0xFF;
      outbuffer[offset++] = (data_length >> 16) & 0xFF;
      outbuffer[offset++] = (data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_dense;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_dense);
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
      unsigned fields_length = inbuffer[offset++];
      fields_length |= inbuffer[offset++] << 8;
      fields_length |= inbuffer[offset++] << 16;
      fields_length |= inbuffer[offset++] << 24;
      fields.clear();
      fields.reserve(fields_length);
      for( unsigned i = 0; i < fields_length; i++){
      fields.emplace_back();
      offset += this->fields.back().deserialize(inbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_bigendian = u_.real;
      }
      offset += sizeof(this->is_bigendian);
      this->point_step =  ((uint32_t) (*(inbuffer + offset)));
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->point_step);
      this->row_step =  ((uint32_t) (*(inbuffer + offset)));
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->row_step);
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
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_dense = u_.real;
      }
      offset += sizeof(this->is_dense);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/PointCloud2"; };
    const char * getMD5(){ return "1158d486dd51d683ce2f1be655c3c181"; };

  };

}
#endif