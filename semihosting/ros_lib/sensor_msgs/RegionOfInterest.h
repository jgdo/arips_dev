#ifndef _ROS_sensor_msgs_RegionOfInterest_h
#define _ROS_sensor_msgs_RegionOfInterest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

  class RegionOfInterest : public ros::Msg
  {
    public:
      uint32_t x_offset = 0;
      uint32_t y_offset = 0;
      uint32_t height = 0;
      uint32_t width = 0;
      bool do_rectify = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->x_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_offset);
      *(outbuffer + offset + 0) = (this->y_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_offset);
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
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->do_rectify;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->do_rectify);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->x_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->x_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->x_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->x_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->x_offset);
      this->y_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->y_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->y_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->y_offset);
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
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->do_rectify = u_.real;
      }
      offset += sizeof(this->do_rectify);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/RegionOfInterest"; };
    const char * getMD5(){ return "bdb633039d588fcccb441a4d43ccfe09"; };

  };

}
#endif