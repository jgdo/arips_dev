#ifndef _ROS_brics_actuator_JointConstraint_h
#define _ROS_brics_actuator_JointConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointConstraint : public ros::Msg
  {
    public:
      char * type = nullptr;
      brics_actuator::JointValue value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_);
      offset += length_;
      }
      offset += this->value.serialize(outbuffer + offset);
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
      this->type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointConstraint"; };
    const char * getMD5(){ return "f77db04949b26b64f80564df22f00ecb"; };

  };

}
#endif