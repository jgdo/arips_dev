#ifndef _ROS_SERVICE_GetModelState_h
#define _ROS_SERVICE_GetModelState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace gazebo_msgs
{

static const char GETMODELSTATE[] = "gazebo_msgs/GetModelState";

  class GetModelStateRequest : public ros::Msg
  {
    public:
      char * model_name = nullptr;
      char * relative_entity_name = nullptr;

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
      uint32_t length_ = strlen( (const char*) this->relative_entity_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->relative_entity_name, length_);
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
      this->relative_entity_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return GETMODELSTATE; };
    const char * getMD5(){ return "19d412713cefe4a67437e17a951e759e"; };

  };

  class GetModelStateResponse : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;
      geometry_msgs::Twist twist;
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
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

    const char * getType(){ return GETMODELSTATE; };
    const char * getMD5(){ return "1f8f991dc94e0cb27fe61383e0f576bb"; };

  };

  class GetModelState {
    public:
    typedef GetModelStateRequest Request;
    typedef GetModelStateResponse Response;
  };

}
#endif
