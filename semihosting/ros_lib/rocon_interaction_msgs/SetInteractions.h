#ifndef _ROS_SERVICE_SetInteractions_h
#define _ROS_SERVICE_SetInteractions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "rocon_interaction_msgs/Interaction.h"

namespace rocon_interaction_msgs
{

static const char SETINTERACTIONS[] = "rocon_interaction_msgs/SetInteractions";

  class SetInteractionsRequest : public ros::Msg
  {
    public:
      std::vector<rocon_interaction_msgs::Interaction> interactions;
      bool load = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned interactions_length = interactions.size();
      outbuffer[offset++] = (interactions_length >> 0) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 8) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 16) & 0xFF;
      outbuffer[offset++] = (interactions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < interactions_length; i++){
      offset += this->interactions[i].serialize(outbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->load;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->load);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned interactions_length = inbuffer[offset++];
      interactions_length |= inbuffer[offset++] << 8;
      interactions_length |= inbuffer[offset++] << 16;
      interactions_length |= inbuffer[offset++] << 24;
      interactions.clear();
      interactions.reserve(interactions_length);
      for( unsigned i = 0; i < interactions_length; i++){
      interactions.emplace_back();
      offset += this->interactions.back().deserialize(inbuffer + offset);
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->load = u_.real;
      }
      offset += sizeof(this->load);
     return offset;
    }

    const char * getType(){ return SETINTERACTIONS; };
    const char * getMD5(){ return "ae1c6b4a11ecb557e89f7a169acf4939"; };

  };

  class SetInteractionsResponse : public ros::Msg
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

    const char * getType(){ return SETINTERACTIONS; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetInteractions {
    public:
    typedef SetInteractionsRequest Request;
    typedef SetInteractionsResponse Response;
  };

}
#endif
