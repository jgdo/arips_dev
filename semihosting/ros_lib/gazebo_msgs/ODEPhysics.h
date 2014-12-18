#ifndef _ROS_gazebo_msgs_ODEPhysics_h
#define _ROS_gazebo_msgs_ODEPhysics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

  class ODEPhysics : public ros::Msg
  {
    public:
      bool auto_disable_bodies = 0;
      uint32_t sor_pgs_precon_iters = 0;
      uint32_t sor_pgs_iters = 0;
      float sor_pgs_w = 0;
      float sor_pgs_rms_error_tol = 0;
      float contact_surface_layer = 0;
      float contact_max_correcting_vel = 0;
      float cfm = 0;
      float erp = 0;
      uint32_t max_contacts = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->auto_disable_bodies;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->auto_disable_bodies);
      *(outbuffer + offset + 0) = (this->sor_pgs_precon_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_precon_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_precon_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_precon_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_precon_iters);
      *(outbuffer + offset + 0) = (this->sor_pgs_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_iters);
      {
      int32_t * val_= (int32_t *) &(this->sor_pgs_w);
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
      if(this->sor_pgs_w < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->sor_pgs_rms_error_tol);
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
      if(this->sor_pgs_rms_error_tol < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->contact_surface_layer);
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
      if(this->contact_surface_layer < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->contact_max_correcting_vel);
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
      if(this->contact_max_correcting_vel < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->cfm);
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
      if(this->cfm < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      int32_t * val_= (int32_t *) &(this->erp);
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
      if(this->erp < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset + 0) = (this->max_contacts >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_contacts >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_contacts >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_contacts >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_contacts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_disable_bodies = u_.real;
      }
      offset += sizeof(this->auto_disable_bodies);
      this->sor_pgs_precon_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_precon_iters);
      this->sor_pgs_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_iters);
      {
      uint32_t * val_ = (uint32_t*) &(this->sor_pgs_w);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sor_pgs_w = -this->sor_pgs_w;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->sor_pgs_rms_error_tol);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sor_pgs_rms_error_tol = -this->sor_pgs_rms_error_tol;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->contact_surface_layer);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->contact_surface_layer = -this->contact_surface_layer;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->contact_max_correcting_vel);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->contact_max_correcting_vel = -this->contact_max_correcting_vel;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->cfm);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cfm = -this->cfm;
      }
      {
      uint32_t * val_ = (uint32_t*) &(this->erp);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->erp = -this->erp;
      }
      this->max_contacts =  ((uint32_t) (*(inbuffer + offset)));
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_contacts);
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ODEPhysics"; };
    const char * getMD5(){ return "667d56ddbd547918c32d1934503dc335"; };

  };

}
#endif