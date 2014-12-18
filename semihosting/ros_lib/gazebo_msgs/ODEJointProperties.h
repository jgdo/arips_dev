#ifndef _ROS_gazebo_msgs_ODEJointProperties_h
#define _ROS_gazebo_msgs_ODEJointProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace gazebo_msgs
{

  class ODEJointProperties : public ros::Msg
  {
    public:
      std::vector<float> damping;
      std::vector<float> hiStop;
      std::vector<float> loStop;
      std::vector<float> erp;
      std::vector<float> cfm;
      std::vector<float> stop_erp;
      std::vector<float> stop_cfm;
      std::vector<float> fudge_factor;
      std::vector<float> fmax;
      std::vector<float> vel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned damping_length = damping.size();
      outbuffer[offset++] = (damping_length >> 0) & 0xFF;
      outbuffer[offset++] = (damping_length >> 8) & 0xFF;
      outbuffer[offset++] = (damping_length >> 16) & 0xFF;
      outbuffer[offset++] = (damping_length >> 24) & 0xFF;
      for( unsigned i = 0; i < damping_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->damping[i]);
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
      if(this->damping[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned hiStop_length = hiStop.size();
      outbuffer[offset++] = (hiStop_length >> 0) & 0xFF;
      outbuffer[offset++] = (hiStop_length >> 8) & 0xFF;
      outbuffer[offset++] = (hiStop_length >> 16) & 0xFF;
      outbuffer[offset++] = (hiStop_length >> 24) & 0xFF;
      for( unsigned i = 0; i < hiStop_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->hiStop[i]);
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
      if(this->hiStop[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned loStop_length = loStop.size();
      outbuffer[offset++] = (loStop_length >> 0) & 0xFF;
      outbuffer[offset++] = (loStop_length >> 8) & 0xFF;
      outbuffer[offset++] = (loStop_length >> 16) & 0xFF;
      outbuffer[offset++] = (loStop_length >> 24) & 0xFF;
      for( unsigned i = 0; i < loStop_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->loStop[i]);
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
      if(this->loStop[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned erp_length = erp.size();
      outbuffer[offset++] = (erp_length >> 0) & 0xFF;
      outbuffer[offset++] = (erp_length >> 8) & 0xFF;
      outbuffer[offset++] = (erp_length >> 16) & 0xFF;
      outbuffer[offset++] = (erp_length >> 24) & 0xFF;
      for( unsigned i = 0; i < erp_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->erp[i]);
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
      if(this->erp[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned cfm_length = cfm.size();
      outbuffer[offset++] = (cfm_length >> 0) & 0xFF;
      outbuffer[offset++] = (cfm_length >> 8) & 0xFF;
      outbuffer[offset++] = (cfm_length >> 16) & 0xFF;
      outbuffer[offset++] = (cfm_length >> 24) & 0xFF;
      for( unsigned i = 0; i < cfm_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->cfm[i]);
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
      if(this->cfm[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned stop_erp_length = stop_erp.size();
      outbuffer[offset++] = (stop_erp_length >> 0) & 0xFF;
      outbuffer[offset++] = (stop_erp_length >> 8) & 0xFF;
      outbuffer[offset++] = (stop_erp_length >> 16) & 0xFF;
      outbuffer[offset++] = (stop_erp_length >> 24) & 0xFF;
      for( unsigned i = 0; i < stop_erp_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->stop_erp[i]);
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
      if(this->stop_erp[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned stop_cfm_length = stop_cfm.size();
      outbuffer[offset++] = (stop_cfm_length >> 0) & 0xFF;
      outbuffer[offset++] = (stop_cfm_length >> 8) & 0xFF;
      outbuffer[offset++] = (stop_cfm_length >> 16) & 0xFF;
      outbuffer[offset++] = (stop_cfm_length >> 24) & 0xFF;
      for( unsigned i = 0; i < stop_cfm_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->stop_cfm[i]);
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
      if(this->stop_cfm[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned fudge_factor_length = fudge_factor.size();
      outbuffer[offset++] = (fudge_factor_length >> 0) & 0xFF;
      outbuffer[offset++] = (fudge_factor_length >> 8) & 0xFF;
      outbuffer[offset++] = (fudge_factor_length >> 16) & 0xFF;
      outbuffer[offset++] = (fudge_factor_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fudge_factor_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->fudge_factor[i]);
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
      if(this->fudge_factor[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned fmax_length = fmax.size();
      outbuffer[offset++] = (fmax_length >> 0) & 0xFF;
      outbuffer[offset++] = (fmax_length >> 8) & 0xFF;
      outbuffer[offset++] = (fmax_length >> 16) & 0xFF;
      outbuffer[offset++] = (fmax_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fmax_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->fmax[i]);
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
      if(this->fmax[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      unsigned vel_length = vel.size();
      outbuffer[offset++] = (vel_length >> 0) & 0xFF;
      outbuffer[offset++] = (vel_length >> 8) & 0xFF;
      outbuffer[offset++] = (vel_length >> 16) & 0xFF;
      outbuffer[offset++] = (vel_length >> 24) & 0xFF;
      for( unsigned i = 0; i < vel_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->vel[i]);
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
      if(this->vel[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned damping_length = inbuffer[offset++];
      damping_length |= inbuffer[offset++] << 8;
      damping_length |= inbuffer[offset++] << 16;
      damping_length |= inbuffer[offset++] << 24;
      damping.clear();
      damping.reserve(damping_length);
      for( unsigned i = 0; i < damping_length; i++){
      damping.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->damping.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->damping.back() = -this->damping.back();
      }
      }
      unsigned hiStop_length = inbuffer[offset++];
      hiStop_length |= inbuffer[offset++] << 8;
      hiStop_length |= inbuffer[offset++] << 16;
      hiStop_length |= inbuffer[offset++] << 24;
      hiStop.clear();
      hiStop.reserve(hiStop_length);
      for( unsigned i = 0; i < hiStop_length; i++){
      hiStop.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->hiStop.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hiStop.back() = -this->hiStop.back();
      }
      }
      unsigned loStop_length = inbuffer[offset++];
      loStop_length |= inbuffer[offset++] << 8;
      loStop_length |= inbuffer[offset++] << 16;
      loStop_length |= inbuffer[offset++] << 24;
      loStop.clear();
      loStop.reserve(loStop_length);
      for( unsigned i = 0; i < loStop_length; i++){
      loStop.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->loStop.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->loStop.back() = -this->loStop.back();
      }
      }
      unsigned erp_length = inbuffer[offset++];
      erp_length |= inbuffer[offset++] << 8;
      erp_length |= inbuffer[offset++] << 16;
      erp_length |= inbuffer[offset++] << 24;
      erp.clear();
      erp.reserve(erp_length);
      for( unsigned i = 0; i < erp_length; i++){
      erp.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->erp.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->erp.back() = -this->erp.back();
      }
      }
      unsigned cfm_length = inbuffer[offset++];
      cfm_length |= inbuffer[offset++] << 8;
      cfm_length |= inbuffer[offset++] << 16;
      cfm_length |= inbuffer[offset++] << 24;
      cfm.clear();
      cfm.reserve(cfm_length);
      for( unsigned i = 0; i < cfm_length; i++){
      cfm.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->cfm.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cfm.back() = -this->cfm.back();
      }
      }
      unsigned stop_erp_length = inbuffer[offset++];
      stop_erp_length |= inbuffer[offset++] << 8;
      stop_erp_length |= inbuffer[offset++] << 16;
      stop_erp_length |= inbuffer[offset++] << 24;
      stop_erp.clear();
      stop_erp.reserve(stop_erp_length);
      for( unsigned i = 0; i < stop_erp_length; i++){
      stop_erp.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->stop_erp.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->stop_erp.back() = -this->stop_erp.back();
      }
      }
      unsigned stop_cfm_length = inbuffer[offset++];
      stop_cfm_length |= inbuffer[offset++] << 8;
      stop_cfm_length |= inbuffer[offset++] << 16;
      stop_cfm_length |= inbuffer[offset++] << 24;
      stop_cfm.clear();
      stop_cfm.reserve(stop_cfm_length);
      for( unsigned i = 0; i < stop_cfm_length; i++){
      stop_cfm.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->stop_cfm.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->stop_cfm.back() = -this->stop_cfm.back();
      }
      }
      unsigned fudge_factor_length = inbuffer[offset++];
      fudge_factor_length |= inbuffer[offset++] << 8;
      fudge_factor_length |= inbuffer[offset++] << 16;
      fudge_factor_length |= inbuffer[offset++] << 24;
      fudge_factor.clear();
      fudge_factor.reserve(fudge_factor_length);
      for( unsigned i = 0; i < fudge_factor_length; i++){
      fudge_factor.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->fudge_factor.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->fudge_factor.back() = -this->fudge_factor.back();
      }
      }
      unsigned fmax_length = inbuffer[offset++];
      fmax_length |= inbuffer[offset++] << 8;
      fmax_length |= inbuffer[offset++] << 16;
      fmax_length |= inbuffer[offset++] << 24;
      fmax.clear();
      fmax.reserve(fmax_length);
      for( unsigned i = 0; i < fmax_length; i++){
      fmax.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->fmax.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->fmax.back() = -this->fmax.back();
      }
      }
      unsigned vel_length = inbuffer[offset++];
      vel_length |= inbuffer[offset++] << 8;
      vel_length |= inbuffer[offset++] << 16;
      vel_length |= inbuffer[offset++] << 24;
      vel.clear();
      vel.reserve(vel_length);
      for( unsigned i = 0; i < vel_length; i++){
      vel.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->vel.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->vel.back() = -this->vel.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ODEJointProperties"; };
    const char * getMD5(){ return "1b744c32a920af979f53afe2f9c3511f"; };

  };

}
#endif