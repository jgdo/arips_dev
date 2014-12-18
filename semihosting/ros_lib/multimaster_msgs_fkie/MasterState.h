#ifndef _ROS_multimaster_msgs_fkie_MasterState_h
#define _ROS_multimaster_msgs_fkie_MasterState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/ROSMaster.h"

namespace multimaster_msgs_fkie
{

  class MasterState : public ros::Msg
  {
    public:
      char * state = nullptr;
      multimaster_msgs_fkie::ROSMaster master;
      enum { STATE_NEW = 'new' };
      enum { STATE_REMOVED = 'removed' };
      enum { STATE_CHANGED = 'changed' };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->state);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_);
      offset += length_;
      }
      offset += this->master.serialize(outbuffer + offset);
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
      this->state = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->master.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/MasterState"; };
    const char * getMD5(){ return "80884072ff659ac99555a763e9ba0b23"; };

  };

}
#endif