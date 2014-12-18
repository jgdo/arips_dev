#ifndef _ROS_concert_msgs_ConcertClients_h
#define _ROS_concert_msgs_ConcertClients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/ConcertClient.h"
#include <vector>

namespace concert_msgs
{

  class ConcertClients : public ros::Msg
  {
    public:
      std::vector<concert_msgs::ConcertClient> clients;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned clients_length = clients.size();
      outbuffer[offset++] = (clients_length >> 0) & 0xFF;
      outbuffer[offset++] = (clients_length >> 8) & 0xFF;
      outbuffer[offset++] = (clients_length >> 16) & 0xFF;
      outbuffer[offset++] = (clients_length >> 24) & 0xFF;
      for( unsigned i = 0; i < clients_length; i++){
      offset += this->clients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned clients_length = inbuffer[offset++];
      clients_length |= inbuffer[offset++] << 8;
      clients_length |= inbuffer[offset++] << 16;
      clients_length |= inbuffer[offset++] << 24;
      clients.clear();
      clients.reserve(clients_length);
      for( unsigned i = 0; i < clients_length; i++){
      clients.emplace_back();
      offset += this->clients.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/ConcertClients"; };
    const char * getMD5(){ return "9572afe4f30b1567d33f03cf448620a8"; };

  };

}
#endif