#ifndef _ROS_SERVICE_MakeNavPlan_h
#define _ROS_SERVICE_MakeNavPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include <vector>

namespace navfn
{

static const char MAKENAVPLAN[] = "navfn/MakeNavPlan";

  class MakeNavPlanRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped start;
      geometry_msgs::PoseStamped goal;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAKENAVPLAN; };
    const char * getMD5(){ return "2fe3126bd5b2d56edd5005220333d4fd"; };

  };

  class MakeNavPlanResponse : public ros::Msg
  {
    public:
      uint8_t plan_found = 0;
      char * error_message = nullptr;
      std::vector<geometry_msgs::PoseStamped> path;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->plan_found >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_found);
      {
      uint32_t length_ = strlen( (const char*) this->error_message);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_);
      offset += length_;
      }
      unsigned path_length = path.size();
      outbuffer[offset++] = (path_length >> 0) & 0xFF;
      outbuffer[offset++] = (path_length >> 8) & 0xFF;
      outbuffer[offset++] = (path_length >> 16) & 0xFF;
      outbuffer[offset++] = (path_length >> 24) & 0xFF;
      for( unsigned i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->plan_found =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->plan_found);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned path_length = inbuffer[offset++];
      path_length |= inbuffer[offset++] << 8;
      path_length |= inbuffer[offset++] << 16;
      path_length |= inbuffer[offset++] << 24;
      path.clear();
      path.reserve(path_length);
      for( unsigned i = 0; i < path_length; i++){
      path.emplace_back();
      offset += this->path.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return MAKENAVPLAN; };
    const char * getMD5(){ return "8b8ed7edf1b237dc9ddda8c8ffed5d3a"; };

  };

  class MakeNavPlan {
    public:
    typedef MakeNavPlanRequest Request;
    typedef MakeNavPlanResponse Response;
  };

}
#endif
