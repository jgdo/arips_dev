#ifndef _ROS_SERVICE_GetAppList_h
#define _ROS_SERVICE_GetAppList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_app_manager_msgs/App.h"
#include <vector>

namespace rocon_app_manager_msgs
{

static const char GETAPPLIST[] = "rocon_app_manager_msgs/GetAppList";

  class GetAppListRequest : public ros::Msg
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

    const char * getType(){ return GETAPPLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetAppListResponse : public ros::Msg
  {
    public:
      std::vector<rocon_app_manager_msgs::App> available_apps;
      std::vector<rocon_app_manager_msgs::App> running_apps;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned available_apps_length = available_apps.size();
      outbuffer[offset++] = (available_apps_length >> 0) & 0xFF;
      outbuffer[offset++] = (available_apps_length >> 8) & 0xFF;
      outbuffer[offset++] = (available_apps_length >> 16) & 0xFF;
      outbuffer[offset++] = (available_apps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < available_apps_length; i++){
      offset += this->available_apps[i].serialize(outbuffer + offset);
      }
      unsigned running_apps_length = running_apps.size();
      outbuffer[offset++] = (running_apps_length >> 0) & 0xFF;
      outbuffer[offset++] = (running_apps_length >> 8) & 0xFF;
      outbuffer[offset++] = (running_apps_length >> 16) & 0xFF;
      outbuffer[offset++] = (running_apps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < running_apps_length; i++){
      offset += this->running_apps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned available_apps_length = inbuffer[offset++];
      available_apps_length |= inbuffer[offset++] << 8;
      available_apps_length |= inbuffer[offset++] << 16;
      available_apps_length |= inbuffer[offset++] << 24;
      available_apps.clear();
      available_apps.reserve(available_apps_length);
      for( unsigned i = 0; i < available_apps_length; i++){
      available_apps.emplace_back();
      offset += this->available_apps.back().deserialize(inbuffer + offset);
      }
      unsigned running_apps_length = inbuffer[offset++];
      running_apps_length |= inbuffer[offset++] << 8;
      running_apps_length |= inbuffer[offset++] << 16;
      running_apps_length |= inbuffer[offset++] << 24;
      running_apps.clear();
      running_apps.reserve(running_apps_length);
      for( unsigned i = 0; i < running_apps_length; i++){
      running_apps.emplace_back();
      offset += this->running_apps.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return GETAPPLIST; };
    const char * getMD5(){ return "dc2c4094a09bf136a3e1a0c1ee817df8"; };

  };

  class GetAppList {
    public:
    typedef GetAppListRequest Request;
    typedef GetAppListResponse Response;
  };

}
#endif
