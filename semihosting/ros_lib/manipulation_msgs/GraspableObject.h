#ifndef _ROS_manipulation_msgs_GraspableObject_h
#define _ROS_manipulation_msgs_GraspableObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseModelPose.h"
#include <vector>
#include "sensor_msgs/PointCloud.h"
#include "manipulation_msgs/SceneRegion.h"

namespace manipulation_msgs
{

  class GraspableObject : public ros::Msg
  {
    public:
      char * reference_frame_id = nullptr;
      std::vector<household_objects_database_msgs::DatabaseModelPose> potential_models;
      sensor_msgs::PointCloud cluster;
      manipulation_msgs::SceneRegion region;
      char * collision_name = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->reference_frame_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->reference_frame_id, length_);
      offset += length_;
      }
      unsigned potential_models_length = potential_models.size();
      outbuffer[offset++] = (potential_models_length >> 0) & 0xFF;
      outbuffer[offset++] = (potential_models_length >> 8) & 0xFF;
      outbuffer[offset++] = (potential_models_length >> 16) & 0xFF;
      outbuffer[offset++] = (potential_models_length >> 24) & 0xFF;
      for( unsigned i = 0; i < potential_models_length; i++){
      offset += this->potential_models[i].serialize(outbuffer + offset);
      }
      offset += this->cluster.serialize(outbuffer + offset);
      offset += this->region.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->collision_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision_name, length_);
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
      this->reference_frame_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned potential_models_length = inbuffer[offset++];
      potential_models_length |= inbuffer[offset++] << 8;
      potential_models_length |= inbuffer[offset++] << 16;
      potential_models_length |= inbuffer[offset++] << 24;
      potential_models.clear();
      potential_models.reserve(potential_models_length);
      for( unsigned i = 0; i < potential_models_length; i++){
      potential_models.emplace_back();
      offset += this->potential_models.back().deserialize(inbuffer + offset);
      }
      offset += this->cluster.deserialize(inbuffer + offset);
      offset += this->region.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->collision_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspableObject"; };
    const char * getMD5(){ return "e2efd13d8e2bbb4697a5d71f167bceaa"; };

  };

}
#endif