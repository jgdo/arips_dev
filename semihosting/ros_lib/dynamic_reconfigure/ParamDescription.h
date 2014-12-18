#ifndef _ROS_dynamic_reconfigure_ParamDescription_h
#define _ROS_dynamic_reconfigure_ParamDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_reconfigure
{

  class ParamDescription : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * type = nullptr;
      uint32_t level = 0;
      char * description = nullptr;
      char * edit_method = nullptr;

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
      *(outbuffer + offset + 0) = (this->level >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->level >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->level >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->level >> (8 * 3)) & 0xFF;
      offset += sizeof(this->level);
      {
      uint32_t length_ = strlen( (const char*) this->description);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->edit_method);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->edit_method, length_);
      offset += length_;
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
      this->level =  ((uint32_t) (*(inbuffer + offset)));
      this->level |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->level |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->level |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->level);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->description = (char *)(inbuffer + offset-1);
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
      this->edit_method = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "dynamic_reconfigure/ParamDescription"; };
    const char * getMD5(){ return "7434fcb9348c13054e0c3b267c8cb34d"; };

  };

}
#endif