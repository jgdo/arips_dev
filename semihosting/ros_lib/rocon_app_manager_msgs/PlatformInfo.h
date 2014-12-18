#ifndef _ROS_rocon_app_manager_msgs_PlatformInfo_h
#define _ROS_rocon_app_manager_msgs_PlatformInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_app_manager_msgs/Icon.h"

namespace rocon_app_manager_msgs
{

  class PlatformInfo : public ros::Msg
  {
    public:
      char * platform = nullptr;
      char * system = nullptr;
      char * robot = nullptr;
      char * name = nullptr;
      rocon_app_manager_msgs::Icon icon;
      enum { PLATFORM_ANY = * };
      enum { PLATFORM_LINUX = linux };
      enum { PLATFORM_WINDOZE = windoze };
      enum { PLATFORM_ANDROID = android };
      enum { SYSTEM_CUSTOM = custom };
      enum { SYSTEM_ROS = ros };
      enum { SYSTEM_OPROS = opros };
      enum { ROBOT_ANY = * };
      enum { ROBOT_PC = pc };
      enum { ROBOT_ROBOSEM = robosem };
      enum { ROBOT_KOBUKI = kobuki };
      enum { ROBOT_TURTLEBOT = turtlebot };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->platform);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->platform, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->system);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->system, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->robot);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      offset += this->icon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->platform = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->system = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      offset += this->icon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_app_manager_msgs/PlatformInfo"; };
    const char * getMD5(){ return "18db61d835a2c85545a016989914665e"; };

  };

}
#endif