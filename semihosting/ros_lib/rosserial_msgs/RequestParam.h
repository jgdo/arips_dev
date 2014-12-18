#ifndef _ROS_SERVICE_RequestParam_h
#define _ROS_SERVICE_RequestParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rosserial_msgs
{

static const char REQUESTPARAM[] = "rosserial_msgs/RequestParam";

  class RequestParamRequest : public ros::Msg
  {
    public:
      char * name = nullptr;

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
     return offset;
    }

    const char * getType(){ return REQUESTPARAM; };
    const char * getMD5(){ return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class RequestParamResponse : public ros::Msg
  {
    public:
      std::vector<int32_t> ints;
      std::vector<float> floats;
      std::vector<char*> strings;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned ints_length = ints.size();
      outbuffer[offset++] = (ints_length >> 0) & 0xFF;
      outbuffer[offset++] = (ints_length >> 8) & 0xFF;
      outbuffer[offset++] = (ints_length >> 16) & 0xFF;
      outbuffer[offset++] = (ints_length >> 24) & 0xFF;
      for( unsigned i = 0; i < ints_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->ints[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->ints[i]);
      }
      unsigned floats_length = floats.size();
      outbuffer[offset++] = (floats_length >> 0) & 0xFF;
      outbuffer[offset++] = (floats_length >> 8) & 0xFF;
      outbuffer[offset++] = (floats_length >> 16) & 0xFF;
      outbuffer[offset++] = (floats_length >> 24) & 0xFF;
      for( unsigned i = 0; i < floats_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->floats[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->floats[i]);
      }
      unsigned strings_length = strings.size();
      outbuffer[offset++] = (strings_length >> 0) & 0xFF;
      outbuffer[offset++] = (strings_length >> 8) & 0xFF;
      outbuffer[offset++] = (strings_length >> 16) & 0xFF;
      outbuffer[offset++] = (strings_length >> 24) & 0xFF;
      for( unsigned i = 0; i < strings_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->strings[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->strings[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned ints_length = inbuffer[offset++];
      ints_length |= inbuffer[offset++] << 8;
      ints_length |= inbuffer[offset++] << 16;
      ints_length |= inbuffer[offset++] << 24;
      ints.clear();
      ints.reserve(ints_length);
      for( unsigned i = 0; i < ints_length; i++){
      ints.emplace_back();
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
      this->ints.back() = u_.real;
      }
      offset += sizeof(this->ints.back());
      }
      unsigned floats_length = inbuffer[offset++];
      floats_length |= inbuffer[offset++] << 8;
      floats_length |= inbuffer[offset++] << 16;
      floats_length |= inbuffer[offset++] << 24;
      floats.clear();
      floats.reserve(floats_length);
      for( unsigned i = 0; i < floats_length; i++){
      floats.emplace_back();
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->floats.back() = u_.real;
      }
      offset += sizeof(this->floats.back());
      }
      unsigned strings_length = inbuffer[offset++];
      strings_length |= inbuffer[offset++] << 8;
      strings_length |= inbuffer[offset++] << 16;
      strings_length |= inbuffer[offset++] << 24;
      strings.clear();
      strings.reserve(strings_length);
      for( unsigned i = 0; i < strings_length; i++){
      strings.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->strings.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return REQUESTPARAM; };
    const char * getMD5(){ return "9f0e98bda65981986ddf53afa7a40e49"; };

  };

  class RequestParam {
    public:
    typedef RequestParamRequest Request;
    typedef RequestParamResponse Response;
  };

}
#endif
