#ifndef _ROS_dynamic_reconfigure_Group_h
#define _ROS_dynamic_reconfigure_Group_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_reconfigure/ParamDescription.h"
#include <vector>

namespace dynamic_reconfigure
{

  class Group : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * type = nullptr;
      std::vector<dynamic_reconfigure::ParamDescription> parameters;
      int32_t parent = 0;
      int32_t id = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_);
      offset += length_;
      }
      unsigned parameters_length = parameters.size();
      outbuffer[offset++] = (parameters_length >> 0) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 8) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 16) & 0xFF;
      outbuffer[offset++] = (parameters_length >> 24) & 0xFF;
      for( unsigned i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->parent;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->parent);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->id);
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
      this->name = (char *)(inbuffer + offset-1);
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
      this->type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned parameters_length = inbuffer[offset++];
      parameters_length |= inbuffer[offset++] << 8;
      parameters_length |= inbuffer[offset++] << 16;
      parameters_length |= inbuffer[offset++] << 24;
      parameters.clear();
      parameters.reserve(parameters_length);
      for( unsigned i = 0; i < parameters_length; i++){
      parameters.emplace_back();
      offset += this->parameters.back().deserialize(inbuffer + offset);
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->parent = u_.real;
      }
      offset += sizeof(this->parent);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_.real;
      }
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return "dynamic_reconfigure/Group"; };
    const char * getMD5(){ return "9e8cd9e9423c94823db3614dd8b1cf7a"; };

  };

}
#endif