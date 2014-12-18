#ifndef _ROS_r2_msgs_Gains_h
#define _ROS_r2_msgs_Gains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace r2_msgs
{

  class Gains : public ros::Msg
  {
    public:
      std::vector<char*> joint_names;
      std::vector<float> K;
      std::vector<float> D;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned joint_names_length = joint_names.size();
      outbuffer[offset++] = (joint_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->joint_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_);
      offset += length_;
      }
      }
      unsigned K_length = K.size();
      outbuffer[offset++] = (K_length >> 0) & 0xFF;
      outbuffer[offset++] = (K_length >> 8) & 0xFF;
      outbuffer[offset++] = (K_length >> 16) & 0xFF;
      outbuffer[offset++] = (K_length >> 24) & 0xFF;
      for( unsigned i = 0; i < K_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->K[i]);
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
      if(this->K[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned D_length = D.size();
      outbuffer[offset++] = (D_length >> 0) & 0xFF;
      outbuffer[offset++] = (D_length >> 8) & 0xFF;
      outbuffer[offset++] = (D_length >> 16) & 0xFF;
      outbuffer[offset++] = (D_length >> 24) & 0xFF;
      for( unsigned i = 0; i < D_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->D[i]);
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
      if(this->D[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned joint_names_length = inbuffer[offset++];
      joint_names_length |= inbuffer[offset++] << 8;
      joint_names_length |= inbuffer[offset++] << 16;
      joint_names_length |= inbuffer[offset++] << 24;
      joint_names.clear();
      joint_names.reserve(joint_names_length);
      for( unsigned i = 0; i < joint_names_length; i++){
      joint_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->joint_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned K_length = inbuffer[offset++];
      K_length |= inbuffer[offset++] << 8;
      K_length |= inbuffer[offset++] << 16;
      K_length |= inbuffer[offset++] << 24;
      K.clear();
      K.reserve(K_length);
      for( unsigned i = 0; i < K_length; i++){
      K.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->K.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->K.back() = -this->K.back();
      }
      }
      unsigned D_length = inbuffer[offset++];
      D_length |= inbuffer[offset++] << 8;
      D_length |= inbuffer[offset++] << 16;
      D_length |= inbuffer[offset++] << 24;
      D.clear();
      D.reserve(D_length);
      for( unsigned i = 0; i < D_length; i++){
      D.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->D.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->D.back() = -this->D.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "r2_msgs/Gains"; };
    const char * getMD5(){ return "689bcaebe3b1d4a08d9dd0ca1971d522"; };

  };

}
#endif