#ifndef _ROS_rocon_interaction_msgs_InteractiveClients_h
#define _ROS_rocon_interaction_msgs_InteractiveClients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_interaction_msgs/InteractiveClient.h"
#include <vector>

namespace rocon_interaction_msgs
{

  class InteractiveClients : public ros::Msg
  {
    public:
      std::vector<rocon_interaction_msgs::InteractiveClient> idle_clients;
      std::vector<rocon_interaction_msgs::InteractiveClient> running_clients;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned idle_clients_length = idle_clients.size();
      outbuffer[offset++] = (idle_clients_length >> 0) & 0xFF;
      outbuffer[offset++] = (idle_clients_length >> 8) & 0xFF;
      outbuffer[offset++] = (idle_clients_length >> 16) & 0xFF;
      outbuffer[offset++] = (idle_clients_length >> 24) & 0xFF;
      for( unsigned i = 0; i < idle_clients_length; i++){
      offset += this->idle_clients[i].serialize(outbuffer + offset);
      }
      unsigned running_clients_length = running_clients.size();
      outbuffer[offset++] = (running_clients_length >> 0) & 0xFF;
      outbuffer[offset++] = (running_clients_length >> 8) & 0xFF;
      outbuffer[offset++] = (running_clients_length >> 16) & 0xFF;
      outbuffer[offset++] = (running_clients_length >> 24) & 0xFF;
      for( unsigned i = 0; i < running_clients_length; i++){
      offset += this->running_clients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned idle_clients_length = inbuffer[offset++];
      idle_clients_length |= inbuffer[offset++] << 8;
      idle_clients_length |= inbuffer[offset++] << 16;
      idle_clients_length |= inbuffer[offset++] << 24;
      idle_clients.clear();
      idle_clients.reserve(idle_clients_length);
      for( unsigned i = 0; i < idle_clients_length; i++){
      idle_clients.emplace_back();
      offset += this->idle_clients.back().deserialize(inbuffer + offset);
      }
      unsigned running_clients_length = inbuffer[offset++];
      running_clients_length |= inbuffer[offset++] << 8;
      running_clients_length |= inbuffer[offset++] << 16;
      running_clients_length |= inbuffer[offset++] << 24;
      running_clients.clear();
      running_clients.reserve(running_clients_length);
      for( unsigned i = 0; i < running_clients_length; i++){
      running_clients.emplace_back();
      offset += this->running_clients.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/InteractiveClients"; };
    const char * getMD5(){ return "c0b28b11ae6440803066fd05a6e7e90e"; };

  };

}
#endif