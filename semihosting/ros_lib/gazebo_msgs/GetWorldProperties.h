#ifndef _ROS_SERVICE_GetWorldProperties_h
#define _ROS_SERVICE_GetWorldProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace gazebo_msgs
{

static const char GETWORLDPROPERTIES[] = "gazebo_msgs/GetWorldProperties";

  class GetWorldPropertiesRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETWORLDPROPERTIES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetWorldPropertiesResponse : public ros::Msg
  {
    public:
      float sim_time = 0;
      std::vector<char*> model_names;
      bool rendering_enabled = 0;
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      int32_t * val_= (int32_t *) &(this->sim_time);
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
      if(this->sim_time < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned model_names_length = model_names.size();
      outbuffer[offset++] = (model_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (model_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (model_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (model_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < model_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->model_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_names[i], length_);
      offset += length_;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->rendering_enabled;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->rendering_enabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t * val_ = (uint32_t*) &(this->sim_time);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sim_time = -this->sim_time;
      }
      unsigned model_names_length = inbuffer[offset++];
      model_names_length |= inbuffer[offset++] << 8;
      model_names_length |= inbuffer[offset++] << 16;
      model_names_length |= inbuffer[offset++] << 24;
      model_names.clear();
      model_names.reserve(model_names_length);
      for( unsigned i = 0; i < model_names_length; i++){
      model_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->model_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rendering_enabled = u_.real;
      }
      offset += sizeof(this->rendering_enabled);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_.real;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETWORLDPROPERTIES; };
    const char * getMD5(){ return "36bb0f2eccf4d8be971410c22818ba3f"; };

  };

  class GetWorldProperties {
    public:
    typedef GetWorldPropertiesRequest Request;
    typedef GetWorldPropertiesResponse Response;
  };

}
#endif
