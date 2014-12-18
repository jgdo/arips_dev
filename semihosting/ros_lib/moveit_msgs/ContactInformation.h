#ifndef _ROS_moveit_msgs_ContactInformation_h
#define _ROS_moveit_msgs_ContactInformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace moveit_msgs
{

  class ContactInformation : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Point position;
      geometry_msgs::Vector3 normal;
      float depth = 0;
      char * contact_body_1 = nullptr;
      uint32_t body_type_1 = 0;
      char * contact_body_2 = nullptr;
      uint32_t body_type_2 = 0;
      enum { ROBOT_LINK = 0 };
      enum { WORLD_OBJECT = 1 };
      enum { ROBOT_ATTACHED = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->normal.serialize(outbuffer + offset);
      {
      int32_t * val_= (int32_t *) &(this->depth);
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
      if(this->depth < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      uint32_t length_ = strlen( (const char*) this->contact_body_1);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->contact_body_1, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->body_type_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_type_1 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_type_1 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_type_1 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_type_1);
      {
      uint32_t length_ = strlen( (const char*) this->contact_body_2);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->contact_body_2, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->body_type_2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_type_2 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_type_2 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_type_2 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_type_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->normal.deserialize(inbuffer + offset);
      {
      uint32_t * val_ = (uint32_t*) &(this->depth);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->depth = -this->depth;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->contact_body_1 = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->body_type_1 =  ((uint32_t) (*(inbuffer + offset)));
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->body_type_1 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->body_type_1);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->contact_body_2 = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->body_type_2 =  ((uint32_t) (*(inbuffer + offset)));
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->body_type_2 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->body_type_2);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ContactInformation"; };
    const char * getMD5(){ return "116228ca08b0c286ec5ca32a50fdc17b"; };

  };

}
#endif