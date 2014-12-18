#ifndef _ROS_SERVICE_SetCameraInfo_h
#define _ROS_SERVICE_SetCameraInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CameraInfo.h"

namespace sensor_msgs
{

static const char SETCAMERAINFO[] = "sensor_msgs/SetCameraInfo";

  class SetCameraInfoRequest : public ros::Msg
  {
    public:
      sensor_msgs::CameraInfo camera_info;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->camera_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->camera_info.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETCAMERAINFO; };
    const char * getMD5(){ return "ee34be01fdeee563d0d99cd594d5581d"; };

  };

  class SetCameraInfoResponse : public ros::Msg
  {
    public:
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
      offset += length_;
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
      this->success = u_.real;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SETCAMERAINFO; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetCameraInfo {
    public:
    typedef SetCameraInfoRequest Request;
    typedef SetCameraInfoResponse Response;
  };

}
#endif
