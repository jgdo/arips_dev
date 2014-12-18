#ifndef _ROS_sensor_msgs_PointField_h
#define _ROS_sensor_msgs_PointField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

  class PointField : public ros::Msg
  {
    public:
      char * name = nullptr;
      uint32_t offset = 0;
      uint8_t datatype = 0;
      uint32_t count = 0;
      enum { INT8 =  1 };
      enum { UINT8 =  2 };
      enum { INT16 =  3 };
      enum { UINT16 =  4 };
      enum { INT32 =  5 };
      enum { UINT32 =  6 };
      enum { FLOAT32 =  7 };
      enum { FLOAT64 =  8 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      *(outbuffer + offset + 0) = (this->datatype >> (8 * 0)) & 0xFF;
      offset += sizeof(this->datatype);
      *(outbuffer + offset + 0) = (this->count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->offset =  ((uint32_t) (*(inbuffer + offset)));
      this->offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset);
      this->datatype =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->datatype);
      this->count =  ((uint32_t) (*(inbuffer + offset)));
      this->count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->count);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/PointField"; };
    const char * getMD5(){ return "268eacb2962780ceac86cbd17e328150"; };

  };

}
#endif