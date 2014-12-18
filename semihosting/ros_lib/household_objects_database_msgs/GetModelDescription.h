#ifndef _ROS_SERVICE_GetModelDescription_h
#define _ROS_SERVICE_GetModelDescription_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseReturnCode.h"
#include <vector>

namespace household_objects_database_msgs
{

static const char GETMODELDESCRIPTION[] = "household_objects_database_msgs/GetModelDescription";

  class GetModelDescriptionRequest : public ros::Msg
  {
    public:
      int32_t model_id = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->model_id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->model_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      this->model_id = u_.real;
      }
      offset += sizeof(this->model_id);
     return offset;
    }

    const char * getType(){ return GETMODELDESCRIPTION; };
    const char * getMD5(){ return "28cb0598daf3b969068a38cd07aaa9f6"; };

  };

  class GetModelDescriptionResponse : public ros::Msg
  {
    public:
      household_objects_database_msgs::DatabaseReturnCode return_code;
      std::vector<char*> tags;
      char * name = nullptr;
      char * maker = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_code.serialize(outbuffer + offset);
      unsigned tags_length = tags.size();
      outbuffer[offset++] = (tags_length >> 0) & 0xFF;
      outbuffer[offset++] = (tags_length >> 8) & 0xFF;
      outbuffer[offset++] = (tags_length >> 16) & 0xFF;
      outbuffer[offset++] = (tags_length >> 24) & 0xFF;
      for( unsigned i = 0; i < tags_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->tags[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tags[i], length_);
      offset += length_;
      }
      }
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->maker);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->maker, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_code.deserialize(inbuffer + offset);
      unsigned tags_length = inbuffer[offset++];
      tags_length |= inbuffer[offset++] << 8;
      tags_length |= inbuffer[offset++] << 16;
      tags_length |= inbuffer[offset++] << 24;
      tags.clear();
      tags.reserve(tags_length);
      for( unsigned i = 0; i < tags_length; i++){
      tags.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->tags.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
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
      this->maker = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELDESCRIPTION; };
    const char * getMD5(){ return "e6c55e34b143695104d37ad9b33c72c0"; };

  };

  class GetModelDescription {
    public:
    typedef GetModelDescriptionRequest Request;
    typedef GetModelDescriptionResponse Response;
  };

}
#endif
