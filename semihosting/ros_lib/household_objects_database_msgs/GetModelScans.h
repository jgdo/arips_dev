#ifndef _ROS_SERVICE_GetModelScans_h
#define _ROS_SERVICE_GetModelScans_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseReturnCode.h"
#include <vector>
#include "household_objects_database_msgs/DatabaseScan.h"

namespace household_objects_database_msgs
{

static const char GETMODELSCANS[] = "household_objects_database_msgs/GetModelScans";

  class GetModelScansRequest : public ros::Msg
  {
    public:
      int32_t model_id = 0;
      char * scan_source = nullptr;

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
      {
      uint32_t length_ = strlen( (const char*) this->scan_source);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->scan_source, length_);
      offset += length_;
      }
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
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->scan_source = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELSCANS; };
    const char * getMD5(){ return "4f31b0f27ba251f6d1f17eafced83cb7"; };

  };

  class GetModelScansResponse : public ros::Msg
  {
    public:
      household_objects_database_msgs::DatabaseReturnCode return_code;
      std::vector<household_objects_database_msgs::DatabaseScan> matching_scans;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_code.serialize(outbuffer + offset);
      unsigned matching_scans_length = matching_scans.size();
      outbuffer[offset++] = (matching_scans_length >> 0) & 0xFF;
      outbuffer[offset++] = (matching_scans_length >> 8) & 0xFF;
      outbuffer[offset++] = (matching_scans_length >> 16) & 0xFF;
      outbuffer[offset++] = (matching_scans_length >> 24) & 0xFF;
      for( unsigned i = 0; i < matching_scans_length; i++){
      offset += this->matching_scans[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_code.deserialize(inbuffer + offset);
      unsigned matching_scans_length = inbuffer[offset++];
      matching_scans_length |= inbuffer[offset++] << 8;
      matching_scans_length |= inbuffer[offset++] << 16;
      matching_scans_length |= inbuffer[offset++] << 24;
      matching_scans.clear();
      matching_scans.reserve(matching_scans_length);
      for( unsigned i = 0; i < matching_scans_length; i++){
      matching_scans.emplace_back();
      offset += this->matching_scans.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETMODELSCANS; };
    const char * getMD5(){ return "8d1bb6e95c26a5d891987d9d9195e958"; };

  };

  class GetModelScans {
    public:
    typedef GetModelScansRequest Request;
    typedef GetModelScansResponse Response;
  };

}
#endif
