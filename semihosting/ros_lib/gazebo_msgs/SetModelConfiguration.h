#ifndef _ROS_SERVICE_SetModelConfiguration_h
#define _ROS_SERVICE_SetModelConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace gazebo_msgs
{

static const char SETMODELCONFIGURATION[] = "gazebo_msgs/SetModelConfiguration";

  class SetModelConfigurationRequest : public ros::Msg
  {
    public:
      char * model_name = nullptr;
      char * urdf_param_name = nullptr;
      std::vector<char*> joint_names;
      std::vector<float> joint_positions;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->model_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->urdf_param_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->urdf_param_name, length_);
      offset += length_;
      }
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
      unsigned joint_positions_length = joint_positions.size();
      outbuffer[offset++] = (joint_positions_length >> 0) & 0xFF;
      outbuffer[offset++] = (joint_positions_length >> 8) & 0xFF;
      outbuffer[offset++] = (joint_positions_length >> 16) & 0xFF;
      outbuffer[offset++] = (joint_positions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < joint_positions_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->joint_positions[i]);
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
      if(this->joint_positions[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->urdf_param_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
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
      unsigned joint_positions_length = inbuffer[offset++];
      joint_positions_length |= inbuffer[offset++] << 8;
      joint_positions_length |= inbuffer[offset++] << 16;
      joint_positions_length |= inbuffer[offset++] << 24;
      joint_positions.clear();
      joint_positions.reserve(joint_positions_length);
      for( unsigned i = 0; i < joint_positions_length; i++){
      joint_positions.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->joint_positions.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->joint_positions.back() = -this->joint_positions.back();
      }
      }
     return offset;
    }

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "160eae60f51fabff255480c70afa289f"; };

  };

  class SetModelConfigurationResponse : public ros::Msg
  {
    public:
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetModelConfiguration {
    public:
    typedef SetModelConfigurationRequest Request;
    typedef SetModelConfigurationResponse Response;
  };

}
#endif
