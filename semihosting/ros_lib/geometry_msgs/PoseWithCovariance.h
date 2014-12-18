#ifndef _ROS_geometry_msgs_PoseWithCovariance_h
#define _ROS_geometry_msgs_PoseWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include <vector>

namespace geometry_msgs
{

  class PoseWithCovariance : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;
      float covariance[36];
      static const unsigned covariance_length = 36;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      for( unsigned i = 0; i < 36; i++){
      {
      int32_t * val_= (int32_t *) &(this->covariance[i]);
      int32_t exp_ = (((*val_)>>23)&255);
      if(exp_ != 0)
        exp_ += 1023-127;
      int32_t sig_ = *val_;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_<<5) & 0xff;
      *(outbuffer + offset++) = (sig_>>3) & 0xff;
      *(outbuffer + offset++) = (sig_>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_<<4) & 0xF0) | ((sig_>>19)&0x0F);
      *(outbuffer + offset++) = (exp_>>4) & 0x7F;
      if(this->covariance[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      for( unsigned i = 0; i < 36; i++){
      {
      uint32_t * val_ = (uint32_t*) &(this->covariance[i]);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->covariance[i] = -this->covariance[i];
      }
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/PoseWithCovariance"; };
    const char * getMD5(){ return "c23e848cf1b7533a8d7c259073a97e6f"; };

  };

}
#endif