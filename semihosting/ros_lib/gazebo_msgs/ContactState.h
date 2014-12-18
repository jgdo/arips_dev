#ifndef _ROS_gazebo_msgs_ContactState_h
#define _ROS_gazebo_msgs_ContactState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Wrench.h"
#include <vector>
#include "geometry_msgs/Vector3.h"

namespace gazebo_msgs
{

  class ContactState : public ros::Msg
  {
    public:
      char * info = nullptr;
      char * collision1_name = nullptr;
      char * collision2_name = nullptr;
      std::vector<geometry_msgs::Wrench> wrenches;
      geometry_msgs::Wrench total_wrench;
      std::vector<geometry_msgs::Vector3> contact_positions;
      std::vector<geometry_msgs::Vector3> contact_normals;
      std::vector<float> depths;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->info);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->info, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->collision1_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision1_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->collision2_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision2_name, length_);
      offset += length_;
      }
      unsigned wrenches_length = wrenches.size();
      outbuffer[offset++] = (wrenches_length >> 0) & 0xFF;
      outbuffer[offset++] = (wrenches_length >> 8) & 0xFF;
      outbuffer[offset++] = (wrenches_length >> 16) & 0xFF;
      outbuffer[offset++] = (wrenches_length >> 24) & 0xFF;
      for( unsigned i = 0; i < wrenches_length; i++){
      offset += this->wrenches[i].serialize(outbuffer + offset);
      }
      offset += this->total_wrench.serialize(outbuffer + offset);
      unsigned contact_positions_length = contact_positions.size();
      outbuffer[offset++] = (contact_positions_length >> 0) & 0xFF;
      outbuffer[offset++] = (contact_positions_length >> 8) & 0xFF;
      outbuffer[offset++] = (contact_positions_length >> 16) & 0xFF;
      outbuffer[offset++] = (contact_positions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < contact_positions_length; i++){
      offset += this->contact_positions[i].serialize(outbuffer + offset);
      }
      unsigned contact_normals_length = contact_normals.size();
      outbuffer[offset++] = (contact_normals_length >> 0) & 0xFF;
      outbuffer[offset++] = (contact_normals_length >> 8) & 0xFF;
      outbuffer[offset++] = (contact_normals_length >> 16) & 0xFF;
      outbuffer[offset++] = (contact_normals_length >> 24) & 0xFF;
      for( unsigned i = 0; i < contact_normals_length; i++){
      offset += this->contact_normals[i].serialize(outbuffer + offset);
      }
      unsigned depths_length = depths.size();
      outbuffer[offset++] = (depths_length >> 0) & 0xFF;
      outbuffer[offset++] = (depths_length >> 8) & 0xFF;
      outbuffer[offset++] = (depths_length >> 16) & 0xFF;
      outbuffer[offset++] = (depths_length >> 24) & 0xFF;
      for( unsigned i = 0; i < depths_length; i++){
      {
      int32_t * val_= (int32_t *) &(this->depths[i]);
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
      if(this->depths[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      this->info = (char *)(inbuffer + offset-1);
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
      this->collision1_name = (char *)(inbuffer + offset-1);
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
      this->collision2_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned wrenches_length = inbuffer[offset++];
      wrenches_length |= inbuffer[offset++] << 8;
      wrenches_length |= inbuffer[offset++] << 16;
      wrenches_length |= inbuffer[offset++] << 24;
      wrenches.clear();
      wrenches.reserve(wrenches_length);
      for( unsigned i = 0; i < wrenches_length; i++){
      wrenches.emplace_back();
      offset += this->wrenches.back().deserialize(inbuffer + offset);
      }
      offset += this->total_wrench.deserialize(inbuffer + offset);
      unsigned contact_positions_length = inbuffer[offset++];
      contact_positions_length |= inbuffer[offset++] << 8;
      contact_positions_length |= inbuffer[offset++] << 16;
      contact_positions_length |= inbuffer[offset++] << 24;
      contact_positions.clear();
      contact_positions.reserve(contact_positions_length);
      for( unsigned i = 0; i < contact_positions_length; i++){
      contact_positions.emplace_back();
      offset += this->contact_positions.back().deserialize(inbuffer + offset);
      }
      unsigned contact_normals_length = inbuffer[offset++];
      contact_normals_length |= inbuffer[offset++] << 8;
      contact_normals_length |= inbuffer[offset++] << 16;
      contact_normals_length |= inbuffer[offset++] << 24;
      contact_normals.clear();
      contact_normals.reserve(contact_normals_length);
      for( unsigned i = 0; i < contact_normals_length; i++){
      contact_normals.emplace_back();
      offset += this->contact_normals.back().deserialize(inbuffer + offset);
      }
      unsigned depths_length = inbuffer[offset++];
      depths_length |= inbuffer[offset++] << 8;
      depths_length |= inbuffer[offset++] << 16;
      depths_length |= inbuffer[offset++] << 24;
      depths.clear();
      depths.reserve(depths_length);
      for( unsigned i = 0; i < depths_length; i++){
      depths.emplace_back();
      {
      uint32_t * val_ = (uint32_t*) &(this->depths.back());
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->depths.back() = -this->depths.back();
      }
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ContactState"; };
    const char * getMD5(){ return "48c0ffb054b8c444f870cecea1ee50d9"; };

  };

}
#endif