#ifndef _ROS_SERVICE_SimpleInvite_h
#define _ROS_SERVICE_SimpleInvite_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_app_manager_msgs
{

static const char SIMPLEINVITE[] = "rocon_app_manager_msgs/SimpleInvite";

  class SimpleInviteRequest : public ros::Msg
  {
    public:
      bool cancel = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->cancel;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->cancel);
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
      this->cancel = u_.real;
      }
      offset += sizeof(this->cancel);
     return offset;
    }

    const char * getType(){ return SIMPLEINVITE; };
    const char * getMD5(){ return "3068cf5967475b8bd5f4f03d455391f8"; };

  };

  class SimpleInviteResponse : public ros::Msg
  {
    public:
      bool result = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->result;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->result);
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
      this->result = u_.real;
      }
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SIMPLEINVITE; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SimpleInvite {
    public:
    typedef SimpleInviteRequest Request;
    typedef SimpleInviteResponse Response;
  };

}
#endif
