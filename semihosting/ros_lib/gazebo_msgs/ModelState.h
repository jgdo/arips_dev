#ifndef _ROS_gazebo_msgs_ModelState_h
#define _ROS_gazebo_msgs_ModelState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace gazebo_msgs
{

  class ModelState : public ros::Msg
  {
    public:
      char * model_name = nullptr;
      geometry_msgs::Pose pose;
      geometry_msgs::Twist twist;
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
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
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

    const char * getType(){ return "gazebo_msgs/ModelState"; };
    const char * getMD5(){ return "9330fd35f2fcd82d457e54bd54e10593"; };

  };

}
#endif