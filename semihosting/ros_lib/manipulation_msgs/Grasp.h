#ifndef _ROS_manipulation_msgs_Grasp_h
#define _ROS_manipulation_msgs_Grasp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PoseStamped.h"
#include "manipulation_msgs/GripperTranslation.h"
#include <vector>

namespace manipulation_msgs
{

  class Grasp : public ros::Msg
  {
    public:
      char * id = nullptr;
      sensor_msgs::JointState pre_grasp_posture;
      sensor_msgs::JointState grasp_posture;
      geometry_msgs::PoseStamped grasp_pose;
      float grasp_quality = 0;
      manipulation_msgs::GripperTranslation approach;
      manipulation_msgs::GripperTranslation retreat;
      float max_contact_force = 0;
      std::vector<char*> allowed_touch_objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_);
      offset += length_;
      }
      offset += this->pre_grasp_posture.serialize(outbuffer + offset);
      offset += this->grasp_posture.serialize(outbuffer + offset);
      offset += this->grasp_pose.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->grasp_quality);
      int32_t exp_ = (((*val_)>>23)&255);
      if(exp_ != 0)
        exp_ += 1023-127;
      int32_t sig_ = *val_;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_<<5) & 0xff;
      *(outbuffer + offset++) = (sig_>>3) & 0xff;
      *(outbuffer + offset++) = (sig_>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_<<4) & 0xF0) | ((sig_>>19)&0x0F);
      *(outbuffer + offset++) = (exp_>>4) & 0x7F;
      if(this->grasp_quality < 0) *(outbuffer + offset -1) |= 0x80;
      }
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->retreat.serialize(outbuffer + offset);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->max_contact_force;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->max_contact_force);
      unsigned allowed_touch_objects_length = allowed_touch_objects.size();
      outbuffer[offset++] = (allowed_touch_objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (allowed_touch_objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < allowed_touch_objects_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->allowed_touch_objects[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->allowed_touch_objects[i], length_);
      offset += length_;
      }
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
      this->id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->pre_grasp_posture.deserialize(inbuffer + offset);
      offset += this->grasp_posture.deserialize(inbuffer + offset);
      offset += this->grasp_pose.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->grasp_quality);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->grasp_quality = -this->grasp_quality;
      }
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->retreat.deserialize(inbuffer + offset);
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
      this->max_contact_force = u_.real;
      }
      offset += sizeof(this->max_contact_force);
      unsigned allowed_touch_objects_length = inbuffer[offset++];
      allowed_touch_objects_length |= inbuffer[offset++] << 8;
      allowed_touch_objects_length |= inbuffer[offset++] << 16;
      allowed_touch_objects_length |= inbuffer[offset++] << 24;
      allowed_touch_objects.clear();
      allowed_touch_objects.reserve(allowed_touch_objects_length);
      for( unsigned i = 0; i < allowed_touch_objects_length; i++){
      allowed_touch_objects.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->allowed_touch_objects.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/Grasp"; };
    const char * getMD5(){ return "83bd11da422ea1917259ee456c0e315a"; };

  };

}
#endif