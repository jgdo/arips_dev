#ifndef _ROS_SERVICE_QueryCalibrationState_h
#define _ROS_SERVICE_QueryCalibrationState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_controllers_msgs
{

static const char QUERYCALIBRATIONSTATE[] = "pr2_controllers_msgs/QueryCalibrationState";

  class QueryCalibrationStateRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return QUERYCALIBRATIONSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class QueryCalibrationStateResponse : public ros::Msg
  {
    public:
      bool is_calibrated = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_calibrated;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_calibrated);
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
      this->is_calibrated = u_.real;
      }
      offset += sizeof(this->is_calibrated);
     return offset;
    }

    const char * getType(){ return QUERYCALIBRATIONSTATE; };
    const char * getMD5(){ return "28af3beedcb84986b8e470dc5470507d"; };

  };

  class QueryCalibrationState {
    public:
    typedef QueryCalibrationStateRequest Request;
    typedef QueryCalibrationStateResponse Response;
  };

}
#endif
