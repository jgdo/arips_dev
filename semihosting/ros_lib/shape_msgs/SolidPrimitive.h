#ifndef _ROS_shape_msgs_SolidPrimitive_h
#define _ROS_shape_msgs_SolidPrimitive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace shape_msgs
{

  class SolidPrimitive : public ros::Msg
  {
    public:
      uint8_t type = 0;
      std::vector<float> dimensions;
      enum { BOX = 1 };
      enum { SPHERE = 2 };
      enum { CYLINDER = 3 };
      enum { CONE = 4 };
      enum { BOX_X = 0 };
      enum { BOX_Y = 1 };
      enum { BOX_Z = 2 };
      enum { SPHERE_RADIUS = 0 };
      enum { CYLINDER_HEIGHT = 0 };
      enum { CYLINDER_RADIUS = 1 };
      enum { CONE_HEIGHT = 0 };
      enum { CONE_RADIUS = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      unsigned dimensions_length = dimensions.size();
      outbuffer[offset++] = (dimensions_length >> 0) & 0xFF;
      outbuffer[offset++] = (dimensions_length >> 8) & 0xFF;
      outbuffer[offset++] = (dimensions_length >> 16) & 0xFF;
      outbuffer[offset++] = (dimensions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < dimensions_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->dimensions[i]);
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
      if(this->dimensions[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      unsigned dimensions_length = inbuffer[offset++];
      dimensions_length |= inbuffer[offset++] << 8;
      dimensions_length |= inbuffer[offset++] << 16;
      dimensions_length |= inbuffer[offset++] << 24;
      dimensions.clear();
      dimensions.reserve(dimensions_length);
      for( unsigned i = 0; i < dimensions_length; i++){
      dimensions.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->dimensions.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->dimensions.back() = -this->dimensions.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/SolidPrimitive"; };
    const char * getMD5(){ return "d8f8cbc74c5ff283fca29569ccefb45d"; };

  };

}
#endif