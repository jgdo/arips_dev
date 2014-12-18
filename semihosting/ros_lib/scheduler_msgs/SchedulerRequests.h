#ifndef _ROS_scheduler_msgs_SchedulerRequests_h
#define _ROS_scheduler_msgs_SchedulerRequests_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "uuid_msgs/UniqueID.h"
#include "scheduler_msgs/Request.h"
#include <vector>

namespace scheduler_msgs
{

  class SchedulerRequests : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uuid_msgs::UniqueID requester;
      std::vector<scheduler_msgs::Request> requests;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->requester.serialize(outbuffer + offset);
      unsigned requests_length = requests.size();
      outbuffer[offset++] = (requests_length >> 0) & 0xFF;
      outbuffer[offset++] = (requests_length >> 8) & 0xFF;
      outbuffer[offset++] = (requests_length >> 16) & 0xFF;
      outbuffer[offset++] = (requests_length >> 24) & 0xFF;
      for( unsigned i = 0; i < requests_length; i++){
      offset += this->requests[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->requester.deserialize(inbuffer + offset);
      unsigned requests_length = inbuffer[offset++];
      requests_length |= inbuffer[offset++] << 8;
      requests_length |= inbuffer[offset++] << 16;
      requests_length |= inbuffer[offset++] << 24;
      requests.clear();
      requests.reserve(requests_length);
      for( unsigned i = 0; i < requests_length; i++){
      requests.emplace_back();
      offset += this->requests.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/SchedulerRequests"; };
    const char * getMD5(){ return "71b4c4d1a41d240629a030fbbda9c701"; };

  };

}
#endif