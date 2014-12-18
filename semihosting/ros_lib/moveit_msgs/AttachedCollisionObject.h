#ifndef _ROS_moveit_msgs_AttachedCollisionObject_h
#define _ROS_moveit_msgs_AttachedCollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/CollisionObject.h"
#include <vector>
#include "trajectory_msgs/JointTrajectory.h"

namespace moveit_msgs
{

  class AttachedCollisionObject : public ros::Msg
  {
    public:
      char * link_name = nullptr;
      moveit_msgs::CollisionObject object;
      std::vector<char*> touch_links;
      trajectory_msgs::JointTrajectory detach_posture;
      float weight = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->link_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_);
      offset += length_;
      }
      offset += this->object.serialize(outbuffer + offset);
      unsigned touch_links_length = touch_links.size();
      outbuffer[offset++] = (touch_links_length >> 0) & 0xFF;
      outbuffer[offset++] = (touch_links_length >> 8) & 0xFF;
      outbuffer[offset++] = (touch_links_length >> 16) & 0xFF;
      outbuffer[offset++] = (touch_links_length >> 24) & 0xFF;
      for( unsigned i = 0; i < touch_links_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->touch_links[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->touch_links[i], length_);
      offset += length_;
      }
      }
      offset += this->detach_posture.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->weight);
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
      if(this->weight < 0) *(outbuffer + offset -1) |= 0x80;
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
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->object.deserialize(inbuffer + offset);
      unsigned touch_links_length = inbuffer[offset++];
      touch_links_length |= inbuffer[offset++] << 8;
      touch_links_length |= inbuffer[offset++] << 16;
      touch_links_length |= inbuffer[offset++] << 24;
      touch_links.clear();
      touch_links.reserve(touch_links_length);
      for( unsigned i = 0; i < touch_links_length; i++){
      touch_links.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->touch_links.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      offset += this->detach_posture.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->weight);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->weight = -this->weight;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AttachedCollisionObject"; };
    const char * getMD5(){ return "3ceac60b21e85bbd6c5b0ab9d476b752"; };

  };

}
#endif