#ifndef _ROS_object_recognition_msgs_ObjectRecognitionGoal_h
#define _ROS_object_recognition_msgs_ObjectRecognitionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace object_recognition_msgs
{

  class ObjectRecognitionGoal : public ros::Msg
  {
    public:
      bool use_roi = 0;
      std::vector<float> filter_limits;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->use_roi;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->use_roi);
      unsigned filter_limits_length = filter_limits.size();
      outbuffer[offset++] = (filter_limits_length >> 0) & 0xFF;
      outbuffer[offset++] = (filter_limits_length >> 8) & 0xFF;
      outbuffer[offset++] = (filter_limits_length >> 16) & 0xFF;
      outbuffer[offset++] = (filter_limits_length >> 24) & 0xFF;
      for( unsigned i = 0; i < filter_limits_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->filter_limits[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->filter_limits[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_roi = u_.real;
      }
      offset += sizeof(this->use_roi);
      unsigned filter_limits_length = inbuffer[offset++];
      filter_limits_length |= inbuffer[offset++] << 8;
      filter_limits_length |= inbuffer[offset++] << 16;
      filter_limits_length |= inbuffer[offset++] << 24;
      filter_limits.clear();
      filter_limits.reserve(filter_limits_length);
      for( unsigned i = 0; i < filter_limits_length; i++){
      filter_limits.emplace_back();
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
      this->filter_limits.back() = u_.real;
      }
      offset += sizeof(this->filter_limits.back());
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/ObjectRecognitionGoal"; };
    const char * getMD5(){ return "49bea2f03a1bba0ad05926e01e3525fa"; };

  };

}
#endif