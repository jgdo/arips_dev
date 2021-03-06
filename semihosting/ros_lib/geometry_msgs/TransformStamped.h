#ifndef _ROS_geometry_msgs_TransformStamped_h
#define _ROS_geometry_msgs_TransformStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Transform.h"

namespace geometry_msgs
{

  class TransformStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * child_frame_id = nullptr;
      geometry_msgs::Transform transform;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->child_frame_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame_id, length_);
      offset += length_;
      }
      offset += this->transform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->child_frame_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->transform.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "geometry_msgs/TransformStamped"; };
    const char * getMD5(){ return "b5764a33bfeb3588febc2682852579b0"; };

  };

}
#endif