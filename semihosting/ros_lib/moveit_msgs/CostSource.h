#ifndef _ROS_moveit_msgs_CostSource_h
#define _ROS_moveit_msgs_CostSource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace moveit_msgs
{

  class CostSource : public ros::Msg
  {
    public:
      float cost_density = 0;
      geometry_msgs::Vector3 aabb_min;
      geometry_msgs::Vector3 aabb_max;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      int32_t * val_= (int32_t *) &(this->cost_density);
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
      if(this->cost_density < 0) *(outbuffer + offset -1) |= 0x80;
      }
      offset += this->aabb_min.serialize(outbuffer + offset);
      offset += this->aabb_max.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t * val_ = (uint32_t*) &(this->cost_density);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cost_density = -this->cost_density;
      }
      offset += this->aabb_min.deserialize(inbuffer + offset);
      offset += this->aabb_max.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/CostSource"; };
    const char * getMD5(){ return "abb7e013237dacaaa8b97e704102f908"; };

  };

}
#endif