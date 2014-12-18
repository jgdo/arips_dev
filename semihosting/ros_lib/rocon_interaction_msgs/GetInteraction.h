#ifndef _ROS_SERVICE_GetInteraction_h
#define _ROS_SERVICE_GetInteraction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_interaction_msgs/Interaction.h"

namespace rocon_interaction_msgs
{

static const char GETINTERACTION[] = "rocon_interaction_msgs/GetInteraction";

  class GetInteractionRequest : public ros::Msg
  {
    public:
      int32_t hash = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->hash;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->hash);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hash = u_.real;
      }
      offset += sizeof(this->hash);
     return offset;
    }

    const char * getType(){ return GETINTERACTION; };
    const char * getMD5(){ return "bff57ffe69467a2a244fb9a7d371e074"; };

  };

  class GetInteractionResponse : public ros::Msg
  {
    public:
      bool result = 0;
      rocon_interaction_msgs::Interaction interaction;

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
      offset += this->interaction.serialize(outbuffer + offset);
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
      offset += this->interaction.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETINTERACTION; };
    const char * getMD5(){ return "b3033a6bfddff94b51160acd01568ff0"; };

  };

  class GetInteraction {
    public:
    typedef GetInteractionRequest Request;
    typedef GetInteractionResponse Response;
  };

}
#endif
