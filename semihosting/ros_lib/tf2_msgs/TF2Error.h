#ifndef _ROS_tf2_msgs_TF2Error_h
#define _ROS_tf2_msgs_TF2Error_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tf2_msgs
{

  class TF2Error : public ros::Msg
  {
    public:
      uint8_t error = 0;
      char * error_string = nullptr;
      enum { NO_ERROR =  0 };
      enum { LOOKUP_ERROR =  1 };
      enum { CONNECTIVITY_ERROR =  2 };
      enum { EXTRAPOLATION_ERROR =  3 };
      enum { INVALID_ARGUMENT_ERROR =  4 };
      enum { TIMEOUT_ERROR =  5 };
      enum { TRANSFORM_ERROR =  6 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error);
      {
      uint32_t length_ = strlen( (const char*) this->error_string);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_string, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->error_string = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "tf2_msgs/TF2Error"; };
    const char * getMD5(){ return "bc6848fd6fd750c92e38575618a4917d"; };

  };

}
#endif