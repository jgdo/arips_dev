#ifndef _ROS_SERVICE_GetStateValidity_h
#define _ROS_SERVICE_GetStateValidity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/ConstraintEvalResult.h"
#include "moveit_msgs/CostSource.h"
#include "moveit_msgs/ContactInformation.h"
#include "moveit_msgs/RobotState.h"
#include <vector>
#include "moveit_msgs/Constraints.h"

namespace moveit_msgs
{

static const char GETSTATEVALIDITY[] = "moveit_msgs/GetStateValidity";

  class GetStateValidityRequest : public ros::Msg
  {
    public:
      moveit_msgs::RobotState robot_state;
      char * group_name = nullptr;
      moveit_msgs::Constraints constraints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->group_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_);
      offset += length_;
      }
      offset += this->constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "b569c609cafad20ba7d0e46e70e7cab1"; };

  };

  class GetStateValidityResponse : public ros::Msg
  {
    public:
      bool valid = 0;
      std::vector<moveit_msgs::ContactInformation> contacts;
      std::vector<moveit_msgs::CostSource> cost_sources;
      std::vector<moveit_msgs::ConstraintEvalResult> constraint_result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->valid;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->valid);
      unsigned contacts_length = contacts.size();
      outbuffer[offset++] = (contacts_length >> 0) & 0xFF;
      outbuffer[offset++] = (contacts_length >> 8) & 0xFF;
      outbuffer[offset++] = (contacts_length >> 16) & 0xFF;
      outbuffer[offset++] = (contacts_length >> 24) & 0xFF;
      for( unsigned i = 0; i < contacts_length; i++){
      offset += this->contacts[i].serialize(outbuffer + offset);
      }
      unsigned cost_sources_length = cost_sources.size();
      outbuffer[offset++] = (cost_sources_length >> 0) & 0xFF;
      outbuffer[offset++] = (cost_sources_length >> 8) & 0xFF;
      outbuffer[offset++] = (cost_sources_length >> 16) & 0xFF;
      outbuffer[offset++] = (cost_sources_length >> 24) & 0xFF;
      for( unsigned i = 0; i < cost_sources_length; i++){
      offset += this->cost_sources[i].serialize(outbuffer + offset);
      }
      unsigned constraint_result_length = constraint_result.size();
      outbuffer[offset++] = (constraint_result_length >> 0) & 0xFF;
      outbuffer[offset++] = (constraint_result_length >> 8) & 0xFF;
      outbuffer[offset++] = (constraint_result_length >> 16) & 0xFF;
      outbuffer[offset++] = (constraint_result_length >> 24) & 0xFF;
      for( unsigned i = 0; i < constraint_result_length; i++){
      offset += this->constraint_result[i].serialize(outbuffer + offset);
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
      this->valid = u_.real;
      }
      offset += sizeof(this->valid);
      unsigned contacts_length = inbuffer[offset++];
      contacts_length |= inbuffer[offset++] << 8;
      contacts_length |= inbuffer[offset++] << 16;
      contacts_length |= inbuffer[offset++] << 24;
      contacts.clear();
      contacts.reserve(contacts_length);
      for( unsigned i = 0; i < contacts_length; i++){
      contacts.emplace_back();
      offset += this->contacts.back().deserialize(inbuffer + offset);
      }
      unsigned cost_sources_length = inbuffer[offset++];
      cost_sources_length |= inbuffer[offset++] << 8;
      cost_sources_length |= inbuffer[offset++] << 16;
      cost_sources_length |= inbuffer[offset++] << 24;
      cost_sources.clear();
      cost_sources.reserve(cost_sources_length);
      for( unsigned i = 0; i < cost_sources_length; i++){
      cost_sources.emplace_back();
      offset += this->cost_sources.back().deserialize(inbuffer + offset);
      }
      unsigned constraint_result_length = inbuffer[offset++];
      constraint_result_length |= inbuffer[offset++] << 8;
      constraint_result_length |= inbuffer[offset++] << 16;
      constraint_result_length |= inbuffer[offset++] << 24;
      constraint_result.clear();
      constraint_result.reserve(constraint_result_length);
      for( unsigned i = 0; i < constraint_result_length; i++){
      constraint_result.emplace_back();
      offset += this->constraint_result.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "e326fb22b7448f29c0e726d9270d9929"; };

  };

  class GetStateValidity {
    public:
    typedef GetStateValidityRequest Request;
    typedef GetStateValidityResponse Response;
  };

}
#endif
