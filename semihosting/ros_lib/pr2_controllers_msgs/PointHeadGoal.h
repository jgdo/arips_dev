#ifndef _ROS_pr2_controllers_msgs_PointHeadGoal_h
#define _ROS_pr2_controllers_msgs_PointHeadGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3.h"
#include "ros/duration.h"

namespace pr2_controllers_msgs
{

  class PointHeadGoal : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped target;
      geometry_msgs::Vector3 pointing_axis;
      char * pointing_frame = nullptr;
      ros::Duration min_duration;
      float max_velocity = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target.serialize(outbuffer + offset);
      offset += this->pointing_axis.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->pointing_frame);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->pointing_frame, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->min_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.sec);
      *(outbuffer + offset + 0) = (this->min_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_duration.nsec);
      {
      int32_t * val_= (int32_t *) &(this->max_velocity);
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
      if(this->max_velocity < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target.deserialize(inbuffer + offset);
      offset += this->pointing_axis.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->pointing_frame = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->min_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.sec);
      this->min_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->min_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->min_duration.nsec);
      {
      uint32_t * val_ = (uint32_t*) &(this->max_velocity);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_velocity = -this->max_velocity;
      }
     return offset;
    }

    const char * getType(){ return "pr2_controllers_msgs/PointHeadGoal"; };
    const char * getMD5(){ return "8b92b1cd5e06c8a94c917dc3209a4c1d"; };

  };

}
#endif