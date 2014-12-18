#ifndef _ROS_manipulation_msgs_CartesianGains_h
#define _ROS_manipulation_msgs_CartesianGains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace manipulation_msgs
{

  class CartesianGains : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<float> gains;
      std::vector<float> fixed_frame;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned gains_length = gains.size();
      outbuffer[offset++] = (gains_length >> 0) & 0xFF;
      outbuffer[offset++] = (gains_length >> 8) & 0xFF;
      outbuffer[offset++] = (gains_length >> 16) & 0xFF;
      outbuffer[offset++] = (gains_length >> 24) & 0xFF;
      for( unsigned i = 0; i < gains_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->gains[i]);
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
      if(this->gains[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned fixed_frame_length = fixed_frame.size();
      outbuffer[offset++] = (fixed_frame_length >> 0) & 0xFF;
      outbuffer[offset++] = (fixed_frame_length >> 8) & 0xFF;
      outbuffer[offset++] = (fixed_frame_length >> 16) & 0xFF;
      outbuffer[offset++] = (fixed_frame_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fixed_frame_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->fixed_frame[i]);
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
      if(this->fixed_frame[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned gains_length = inbuffer[offset++];
      gains_length |= inbuffer[offset++] << 8;
      gains_length |= inbuffer[offset++] << 16;
      gains_length |= inbuffer[offset++] << 24;
      gains.clear();
      gains.reserve(gains_length);
      for( unsigned i = 0; i < gains_length; i++){
      gains.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->gains.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->gains.back() = -this->gains.back();
      }
      }
      unsigned fixed_frame_length = inbuffer[offset++];
      fixed_frame_length |= inbuffer[offset++] << 8;
      fixed_frame_length |= inbuffer[offset++] << 16;
      fixed_frame_length |= inbuffer[offset++] << 24;
      fixed_frame.clear();
      fixed_frame.reserve(fixed_frame_length);
      for( unsigned i = 0; i < fixed_frame_length; i++){
      fixed_frame.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->fixed_frame.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->fixed_frame.back() = -this->fixed_frame.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/CartesianGains"; };
    const char * getMD5(){ return "ab347f046ca5736a156ec424cbb63635"; };

  };

}
#endif