#ifndef _ROS_moveit_msgs_PositionConstraint_h
#define _ROS_moveit_msgs_PositionConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "moveit_msgs/BoundingVolume.h"

namespace moveit_msgs
{

  class PositionConstraint : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * link_name = nullptr;
      geometry_msgs::Vector3 target_point_offset;
      moveit_msgs::BoundingVolume constraint_region;
      float weight = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->link_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_);
      offset += length_;
      }
      offset += this->target_point_offset.serialize(outbuffer + offset);
      offset += this->constraint_region.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->weight);
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
      if(this->weight < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->target_point_offset.deserialize(inbuffer + offset);
      offset += this->constraint_region.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->weight);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->weight = -this->weight;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PositionConstraint"; };
    const char * getMD5(){ return "c83edf208d87d3aa3169f47775a58e6a"; };

  };

}
#endif