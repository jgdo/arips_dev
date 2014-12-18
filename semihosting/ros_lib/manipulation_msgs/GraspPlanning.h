#ifndef _ROS_SERVICE_GraspPlanning_h
#define _ROS_SERVICE_GraspPlanning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "manipulation_msgs/GraspPlanningErrorCode.h"
#include <vector>
#include "manipulation_msgs/GraspableObject.h"
#include "manipulation_msgs/Grasp.h"

namespace manipulation_msgs
{

static const char GRASPPLANNING[] = "manipulation_msgs/GraspPlanning";

  class GraspPlanningRequest : public ros::Msg
  {
    public:
      char * arm_name = nullptr;
      manipulation_msgs::GraspableObject target;
      char * collision_object_name = nullptr;
      char * collision_support_surface_name = nullptr;
      std::vector<manipulation_msgs::Grasp> grasps_to_evaluate;
      std::vector<manipulation_msgs::GraspableObject> movable_obstacles;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->arm_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->arm_name, length_);
      offset += length_;
      }
      offset += this->target.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->collision_object_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision_object_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->collision_support_surface_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision_support_surface_name, length_);
      offset += length_;
      }
      unsigned grasps_to_evaluate_length = grasps_to_evaluate.size();
      outbuffer[offset++] = (grasps_to_evaluate_length >> 0) & 0xFF;
      outbuffer[offset++] = (grasps_to_evaluate_length >> 8) & 0xFF;
      outbuffer[offset++] = (grasps_to_evaluate_length >> 16) & 0xFF;
      outbuffer[offset++] = (grasps_to_evaluate_length >> 24) & 0xFF;
      for( unsigned i = 0; i < grasps_to_evaluate_length; i++){
      offset += this->grasps_to_evaluate[i].serialize(outbuffer + offset);
      }
      unsigned movable_obstacles_length = movable_obstacles.size();
      outbuffer[offset++] = (movable_obstacles_length >> 0) & 0xFF;
      outbuffer[offset++] = (movable_obstacles_length >> 8) & 0xFF;
      outbuffer[offset++] = (movable_obstacles_length >> 16) & 0xFF;
      outbuffer[offset++] = (movable_obstacles_length >> 24) & 0xFF;
      for( unsigned i = 0; i < movable_obstacles_length; i++){
      offset += this->movable_obstacles[i].serialize(outbuffer + offset);
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
      this->arm_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->target.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->collision_object_name = (char *)(inbuffer + offset-1);
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
      this->collision_support_surface_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned grasps_to_evaluate_length = inbuffer[offset++];
      grasps_to_evaluate_length |= inbuffer[offset++] << 8;
      grasps_to_evaluate_length |= inbuffer[offset++] << 16;
      grasps_to_evaluate_length |= inbuffer[offset++] << 24;
      grasps_to_evaluate.clear();
      grasps_to_evaluate.reserve(grasps_to_evaluate_length);
      for( unsigned i = 0; i < grasps_to_evaluate_length; i++){
      grasps_to_evaluate.emplace_back();
      offset += this->grasps_to_evaluate.back().deserialize(inbuffer + offset);
      }
      unsigned movable_obstacles_length = inbuffer[offset++];
      movable_obstacles_length |= inbuffer[offset++] << 8;
      movable_obstacles_length |= inbuffer[offset++] << 16;
      movable_obstacles_length |= inbuffer[offset++] << 24;
      movable_obstacles.clear();
      movable_obstacles.reserve(movable_obstacles_length);
      for( unsigned i = 0; i < movable_obstacles_length; i++){
      movable_obstacles.emplace_back();
      offset += this->movable_obstacles.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "077dca08a07415d82d6ab047890161f4"; };

  };

  class GraspPlanningResponse : public ros::Msg
  {
    public:
      std::vector<manipulation_msgs::Grasp> grasps;
      manipulation_msgs::GraspPlanningErrorCode error_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned grasps_length = grasps.size();
      outbuffer[offset++] = (grasps_length >> 0) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 8) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 16) & 0xFF;
      outbuffer[offset++] = (grasps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < grasps_length; i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned grasps_length = inbuffer[offset++];
      grasps_length |= inbuffer[offset++] << 8;
      grasps_length |= inbuffer[offset++] << 16;
      grasps_length |= inbuffer[offset++] << 24;
      grasps.clear();
      grasps.reserve(grasps_length);
      for( unsigned i = 0; i < grasps_length; i++){
      grasps.emplace_back();
      offset += this->grasps.back().deserialize(inbuffer + offset);
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "ff7a88c4aec40207164535a24dc9c440"; };

  };

  class GraspPlanning {
    public:
    typedef GraspPlanningRequest Request;
    typedef GraspPlanningResponse Response;
  };

}
#endif
