#ifndef _ROS_SERVICE_ListMaps_h
#define _ROS_SERVICE_ListMaps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "map_store/MapListEntry.h"

namespace map_store
{

static const char LISTMAPS[] = "map_store/ListMaps";

  class ListMapsRequest : public ros::Msg
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

    const char * getType(){ return LISTMAPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListMapsResponse : public ros::Msg
  {
    public:
      std::vector<map_store::MapListEntry> map_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned map_list_length = map_list.size();
      outbuffer[offset++] = (map_list_length >> 0) & 0xFF;
      outbuffer[offset++] = (map_list_length >> 8) & 0xFF;
      outbuffer[offset++] = (map_list_length >> 16) & 0xFF;
      outbuffer[offset++] = (map_list_length >> 24) & 0xFF;
      for( unsigned i = 0; i < map_list_length; i++){
      offset += this->map_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned map_list_length = inbuffer[offset++];
      map_list_length |= inbuffer[offset++] << 8;
      map_list_length |= inbuffer[offset++] << 16;
      map_list_length |= inbuffer[offset++] << 24;
      map_list.clear();
      map_list.reserve(map_list_length);
      for( unsigned i = 0; i < map_list_length; i++){
      map_list.emplace_back();
      offset += this->map_list.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return LISTMAPS; };
    const char * getMD5(){ return "ca5a33dd106a2c24cfd54c927d214957"; };

  };

  class ListMaps {
    public:
    typedef ListMapsRequest Request;
    typedef ListMapsResponse Response;
  };

}
#endif
