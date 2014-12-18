#ifndef _ROS_sensor_msgs_MultiEchoLaserScan_h
#define _ROS_sensor_msgs_MultiEchoLaserScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/LaserEcho.h"
#include <vector>

namespace sensor_msgs
{

  class MultiEchoLaserScan : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float angle_min = 0;
      float angle_max = 0;
      float angle_increment = 0;
      float time_increment = 0;
      float scan_time = 0;
      float range_min = 0;
      float range_max = 0;
      std::vector<sensor_msgs::LaserEcho> ranges;
      std::vector<sensor_msgs::LaserEcho> intensities;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->angle_min;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->angle_min);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->angle_max;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->angle_max);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->angle_increment;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->angle_increment);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->time_increment;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->time_increment);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->scan_time;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->scan_time);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->range_min;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->range_min);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->range_max;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->range_max);
      unsigned ranges_length = ranges.size();
      outbuffer[offset++] = (ranges_length >> 0) & 0xFF;
      outbuffer[offset++] = (ranges_length >> 8) & 0xFF;
      outbuffer[offset++] = (ranges_length >> 16) & 0xFF;
      outbuffer[offset++] = (ranges_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ranges_length; i++){
      offset += this->ranges[i].serialize(outbuffer + offset);
      }
      unsigned intensities_length = intensities.size();
      outbuffer[offset++] = (intensities_length >> 0) & 0xFF;
      outbuffer[offset++] = (intensities_length >> 8) & 0xFF;
      outbuffer[offset++] = (intensities_length >> 16) & 0xFF;
      outbuffer[offset++] = (intensities_length >> 24) & 0xFF;
      for( unsigned i = 0; i < intensities_length; i++){
      offset += this->intensities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_min = u_.real;
      }
      offset += sizeof(this->angle_min);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_max = u_.real;
      }
      offset += sizeof(this->angle_max);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_increment = u_.real;
      }
      offset += sizeof(this->angle_increment);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_increment = u_.real;
      }
      offset += sizeof(this->time_increment);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_time = u_.real;
      }
      offset += sizeof(this->scan_time);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_min = u_.real;
      }
      offset += sizeof(this->range_min);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_max = u_.real;
      }
      offset += sizeof(this->range_max);
      unsigned ranges_length = inbuffer[offset++];
      ranges_length |= inbuffer[offset++] << 8;
      ranges_length |= inbuffer[offset++] << 16;
      ranges_length |= inbuffer[offset++] << 24;
      ranges.clear();
      ranges.reserve(ranges_length);
      for( unsigned i = 0; i < ranges_length; i++){
      ranges.emplace_back();
      offset += this->ranges.back().deserialize(inbuffer + offset);
      }
      unsigned intensities_length = inbuffer[offset++];
      intensities_length |= inbuffer[offset++] << 8;
      intensities_length |= inbuffer[offset++] << 16;
      intensities_length |= inbuffer[offset++] << 24;
      intensities.clear();
      intensities.reserve(intensities_length);
      for( unsigned i = 0; i < intensities_length; i++){
      intensities.emplace_back();
      offset += this->intensities.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/MultiEchoLaserScan"; };
    const char * getMD5(){ return "6fefb0c6da89d7c8abe4b339f5c2f8fb"; };

  };

}
#endif