#ifndef _ROS_SERVICE_SetCostmap_h
#define _ROS_SERVICE_SetCostmap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace navfn
{

static const char SETCOSTMAP[] = "navfn/SetCostmap";

  class SetCostmapRequest : public ros::Msg
  {
    public:
      std::vector<uint8_t> costs;
      uint16_t height = 0;
      uint16_t width = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned costs_length = costs.size();
      outbuffer[offset++] = (costs_length >> 0) & 0xFF;
      outbuffer[offset++] = (costs_length >> 8) & 0xFF;
      outbuffer[offset++] = (costs_length >> 16) & 0xFF;
      outbuffer[offset++] = (costs_length >> 24) & 0xFF;
      for( unsigned i = 0; i < costs_length; i++){
      *(outbuffer + offset + 0) = (this->costs[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->costs[i]);
      }
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned costs_length = inbuffer[offset++];
      costs_length |= inbuffer[offset++] << 8;
      costs_length |= inbuffer[offset++] << 16;
      costs_length |= inbuffer[offset++] << 24;
      costs.clear();
      costs.reserve(costs_length);
      for( unsigned i = 0; i < costs_length; i++){
      costs.emplace_back();
      this->costs.back() =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->costs.back());
      }
      this->height =  ((uint16_t) (*(inbuffer + offset)));
      this->height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->height);
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
     return offset;
    }

    const char * getType(){ return SETCOSTMAP; };
    const char * getMD5(){ return "370ec969cdb71f9cde7c7cbe0d752308"; };

  };

  class SetCostmapResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETCOSTMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetCostmap {
    public:
    typedef SetCostmapRequest Request;
    typedef SetCostmapResponse Response;
  };

}
#endif
