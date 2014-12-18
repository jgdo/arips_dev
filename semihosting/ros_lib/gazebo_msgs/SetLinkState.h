#ifndef _ROS_SERVICE_SetLinkState_h
#define _ROS_SERVICE_SetLinkState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gazebo_msgs/LinkState.h"

namespace gazebo_msgs
{

static const char SETLINKSTATE[] = "gazebo_msgs/SetLinkState";

  class SetLinkStateRequest : public ros::Msg
  {
    public:
      gazebo_msgs::LinkState link_state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->link_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->link_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETLINKSTATE; };
    const char * getMD5(){ return "22a2c757d56911b6f27868159e9a872d"; };

  };

  class SetLinkStateResponse : public ros::Msg
  {
    public:
      bool success = 0;
      char * status_message = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->success;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_ = strlen( (const char*) this->status_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_);
      offset += length_;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_.real;
      }
      offset += sizeof(this->success);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return SETLINKSTATE; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetLinkState {
    public:
    typedef SetLinkStateRequest Request;
    typedef SetLinkStateResponse Response;
  };

}
#endif
