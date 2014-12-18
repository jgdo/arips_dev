#ifndef _ROS_SERVICE_GetModelList_h
#define _ROS_SERVICE_GetModelList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseReturnCode.h"
#include <vector>

namespace household_objects_database_msgs
{

static const char GETMODELLIST[] = "household_objects_database_msgs/GetModelList";

  class GetModelListRequest : public ros::Msg
  {
    public:
      char * model_set = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->model_set);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_set, length_);
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
      this->model_set = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELLIST; };
    const char * getMD5(){ return "6bdf0a866151f41b8876e73800929933"; };

  };

  class GetModelListResponse : public ros::Msg
  {
    public:
      household_objects_database_msgs::DatabaseReturnCode return_code;
      std::vector<int32_t> model_ids;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_code.serialize(outbuffer + offset);
      unsigned model_ids_length = model_ids.size();
      outbuffer[offset++] = (model_ids_length >> 0) & 0xFF;
      outbuffer[offset++] = (model_ids_length >> 8) & 0xFF;
      outbuffer[offset++] = (model_ids_length >> 16) & 0xFF;
      outbuffer[offset++] = (model_ids_length >> 24) & 0xFF;
      for( unsigned i = 0; i < model_ids_length; i++){
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->model_ids[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->model_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_code.deserialize(inbuffer + offset);
      unsigned model_ids_length = inbuffer[offset++];
      model_ids_length |= inbuffer[offset++] << 8;
      model_ids_length |= inbuffer[offset++] << 16;
      model_ids_length |= inbuffer[offset++] << 24;
      model_ids.clear();
      model_ids.reserve(model_ids_length);
      for( unsigned i = 0; i < model_ids_length; i++){
      model_ids.emplace_back();
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
      this->model_ids.back() = u_.real;
      }
      offset += sizeof(this->model_ids.back());
      }
     return offset;
    }

    const char * getType(){ return GETMODELLIST; };
    const char * getMD5(){ return "81fac8c5d631e612bd9183a923572d53"; };

  };

  class GetModelList {
    public:
    typedef GetModelListRequest Request;
    typedef GetModelListResponse Response;
  };

}
#endif
