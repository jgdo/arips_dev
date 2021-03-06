#ifndef _ROS_SERVICE_SpawnModel_h
#define _ROS_SERVICE_SpawnModel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace gazebo_msgs
{

static const char SPAWNMODEL[] = "gazebo_msgs/SpawnModel";

  class SpawnModelRequest : public ros::Msg
  {
    public:
      char * model_name = nullptr;
      char * model_xml = nullptr;
      char * robot_namespace = nullptr;
      geometry_msgs::Pose initial_pose;
      char * reference_frame = nullptr;

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
      uint32_t length_ = strlen( (const char*) this->model_xml);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model_xml, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->robot_namespace);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot_namespace, length_);
      offset += length_;
      }
      offset += this->initial_pose.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->reference_frame);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->reference_frame, length_);
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
      this->model_xml = (char *)(inbuffer + offset-1);
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
      this->robot_namespace = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->initial_pose.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->reference_frame = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SPAWNMODEL; };
    const char * getMD5(){ return "6d0eba5753761cd57e6263a056b79930"; };

  };

  class SpawnModelResponse : public ros::Msg
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

    const char * getType(){ return SPAWNMODEL; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SpawnModel {
    public:
    typedef SpawnModelRequest Request;
    typedef SpawnModelResponse Response;
  };

}
#endif
