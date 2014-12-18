#ifndef _ROS_SERVICE_ReloadControllerLibraries_h
#define _ROS_SERVICE_ReloadControllerLibraries_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace controller_manager_msgs
{

static const char RELOADCONTROLLERLIBRARIES[] = "controller_manager_msgs/ReloadControllerLibraries";

  class ReloadControllerLibrariesRequest : public ros::Msg
  {
    public:
      bool force_kill = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->force_kill;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->force_kill);
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
      this->force_kill = u_.real;
      }
      offset += sizeof(this->force_kill);
     return offset;
    }

    const char * getType(){ return RELOADCONTROLLERLIBRARIES; };
    const char * getMD5(){ return "18442b59be9479097f11c543bddbac62"; };

  };

  class ReloadControllerLibrariesResponse : public ros::Msg
  {
    public:
      bool ok = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->ok;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->ok);
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
      this->ok = u_.real;
      }
      offset += sizeof(this->ok);
     return offset;
    }

    const char * getType(){ return RELOADCONTROLLERLIBRARIES; };
    const char * getMD5(){ return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class ReloadControllerLibraries {
    public:
    typedef ReloadControllerLibrariesRequest Request;
    typedef ReloadControllerLibrariesResponse Response;
  };

}
#endif
