#ifndef _ROS_SERVICE_SaveScan_h
#define _ROS_SERVICE_SaveScan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "household_objects_database_msgs/DatabaseReturnCode.h"

namespace household_objects_database_msgs
{

static const char SAVESCAN[] = "household_objects_database_msgs/SaveScan";

  class SaveScanRequest : public ros::Msg
  {
    public:
      int32_t scaled_model_id = 0;
      geometry_msgs::PoseStamped ground_truth_pose;
      char * bagfile_location = nullptr;
      char * scan_source = nullptr;
      char * cloud_topic = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->scaled_model_id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->scaled_model_id);
      offset += this->ground_truth_pose.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->bagfile_location);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->bagfile_location, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->scan_source);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->scan_source, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->cloud_topic);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->cloud_topic, length_);
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
      this->scaled_model_id = u_.real;
      }
      offset += sizeof(this->scaled_model_id);
      offset += this->ground_truth_pose.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->bagfile_location = (char *)(inbuffer + offset-1);
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
      this->scan_source = (char *)(inbuffer + offset-1);
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
      this->cloud_topic = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SAVESCAN; };
    const char * getMD5(){ return "492f49d320aa26325df5fb078c297fa5"; };

  };

  class SaveScanResponse : public ros::Msg
  {
    public:
      household_objects_database_msgs::DatabaseReturnCode return_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SAVESCAN; };
    const char * getMD5(){ return "b49fccceeb56b964ed23601916a24082"; };

  };

  class SaveScan {
    public:
    typedef SaveScanRequest Request;
    typedef SaveScanResponse Response;
  };

}
#endif
