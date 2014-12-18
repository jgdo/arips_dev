#ifndef _ROS_SERVICE_GetPositionFK_h
#define _ROS_SERVICE_GetPositionFK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "moveit_msgs/MoveItErrorCodes.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/Header.h"
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

static const char GETPOSITIONFK[] = "moveit_msgs/GetPositionFK";

  class GetPositionFKRequest : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<char*> fk_link_names;
      moveit_msgs::RobotState robot_state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned fk_link_names_length = fk_link_names.size();
      outbuffer[offset++] = (fk_link_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fk_link_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->fk_link_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fk_link_names[i], length_);
      offset += length_;
      }
      }
      offset += this->robot_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned fk_link_names_length = inbuffer[offset++];
      fk_link_names_length |= inbuffer[offset++] << 8;
      fk_link_names_length |= inbuffer[offset++] << 16;
      fk_link_names_length |= inbuffer[offset++] << 24;
      fk_link_names.clear();
      fk_link_names.reserve(fk_link_names_length);
      for( unsigned i = 0; i < fk_link_names_length; i++){
      fk_link_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->fk_link_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      offset += this->robot_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSITIONFK; };
    const char * getMD5(){ return "1d1ed72044ed56f6246c31b522781797"; };

  };

  class GetPositionFKResponse : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::PoseStamped> pose_stamped;
      std::vector<char*> fk_link_names;
      moveit_msgs::MoveItErrorCodes error_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned pose_stamped_length = pose_stamped.size();
      outbuffer[offset++] = (pose_stamped_length >> 0) & 0xFF;
      outbuffer[offset++] = (pose_stamped_length >> 8) & 0xFF;
      outbuffer[offset++] = (pose_stamped_length >> 16) & 0xFF;
      outbuffer[offset++] = (pose_stamped_length >> 24) & 0xFF;
      for( unsigned i = 0; i < pose_stamped_length; i++){
      offset += this->pose_stamped[i].serialize(outbuffer + offset);
      }
      unsigned fk_link_names_length = fk_link_names.size();
      outbuffer[offset++] = (fk_link_names_length >> 0) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 8) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 16) & 0xFF;
      outbuffer[offset++] = (fk_link_names_length >> 24) & 0xFF;
      for( unsigned i = 0; i < fk_link_names_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->fk_link_names[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fk_link_names[i], length_);
      offset += length_;
      }
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned pose_stamped_length = inbuffer[offset++];
      pose_stamped_length |= inbuffer[offset++] << 8;
      pose_stamped_length |= inbuffer[offset++] << 16;
      pose_stamped_length |= inbuffer[offset++] << 24;
      pose_stamped.clear();
      pose_stamped.reserve(pose_stamped_length);
      for( unsigned i = 0; i < pose_stamped_length; i++){
      pose_stamped.emplace_back();
      offset += this->pose_stamped.back().deserialize(inbuffer + offset);
      }
      unsigned fk_link_names_length = inbuffer[offset++];
      fk_link_names_length |= inbuffer[offset++] << 8;
      fk_link_names_length |= inbuffer[offset++] << 16;
      fk_link_names_length |= inbuffer[offset++] << 24;
      fk_link_names.clear();
      fk_link_names.reserve(fk_link_names_length);
      for( unsigned i = 0; i < fk_link_names_length; i++){
      fk_link_names.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->fk_link_names.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSITIONFK; };
    const char * getMD5(){ return "297215cf4fdfe0008356995ae621dae6"; };

  };

  class GetPositionFK {
    public:
    typedef GetPositionFKRequest Request;
    typedef GetPositionFKResponse Response;
  };

}
#endif
