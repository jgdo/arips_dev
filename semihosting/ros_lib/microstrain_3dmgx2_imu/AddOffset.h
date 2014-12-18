#ifndef _ROS_SERVICE_AddOffset_h
#define _ROS_SERVICE_AddOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace microstrain_3dmgx2_imu
{

static const char ADDOFFSET[] = "microstrain_3dmgx2_imu/AddOffset";

  class AddOffsetRequest : public ros::Msg
  {
    public:
      float add_offset = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      int32_t * val_= (int32_t *) &(this->add_offset);
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
      if(this->add_offset < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t * val_ = (uint32_t*) &(this->add_offset);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->add_offset = -this->add_offset;
      }
     return offset;
    }

    const char * getType(){ return ADDOFFSET; };
    const char * getMD5(){ return "10fe27c5d4591264b9d05acc7497a18a"; };

  };

  class AddOffsetResponse : public ros::Msg
  {
    public:
      float total_offset = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      int32_t * val_= (int32_t *) &(this->total_offset);
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
      if(this->total_offset < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t * val_ = (uint32_t*) &(this->total_offset);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->total_offset = -this->total_offset;
      }
     return offset;
    }

    const char * getType(){ return ADDOFFSET; };
    const char * getMD5(){ return "5dea42ce4656fada4736ce3508b56aca"; };

  };

  class AddOffset {
    public:
    typedef AddOffsetRequest Request;
    typedef AddOffsetResponse Response;
  };

}
#endif
