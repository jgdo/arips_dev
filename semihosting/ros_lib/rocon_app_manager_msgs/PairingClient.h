#ifndef _ROS_rocon_app_manager_msgs_PairingClient_h
#define _ROS_rocon_app_manager_msgs_PairingClient_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_app_manager_msgs/KeyValue.h"
#include <vector>

namespace rocon_app_manager_msgs
{

  class PairingClient : public ros::Msg
  {
    public:
      char * client_type = nullptr;
      std::vector<rocon_app_manager_msgs::KeyValue> manager_data;
      std::vector<rocon_app_manager_msgs::KeyValue> app_data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->client_type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->client_type, length_);
      offset += length_;
      }
      unsigned manager_data_length = manager_data.size();
      outbuffer[offset++] = (manager_data_length >> 0) & 0xFF;
      outbuffer[offset++] = (manager_data_length >> 8) & 0xFF;
      outbuffer[offset++] = (manager_data_length >> 16) & 0xFF;
      outbuffer[offset++] = (manager_data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < manager_data_length; i++){
      offset += this->manager_data[i].serialize(outbuffer + offset);
      }
      unsigned app_data_length = app_data.size();
      outbuffer[offset++] = (app_data_length >> 0) & 0xFF;
      outbuffer[offset++] = (app_data_length >> 8) & 0xFF;
      outbuffer[offset++] = (app_data_length >> 16) & 0xFF;
      outbuffer[offset++] = (app_data_length >> 24) & 0xFF;
      for( unsigned i = 0; i < app_data_length; i++){
      offset += this->app_data[i].serialize(outbuffer + offset);
      }
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
      this->client_type = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned manager_data_length = inbuffer[offset++];
      manager_data_length |= inbuffer[offset++] << 8;
      manager_data_length |= inbuffer[offset++] << 16;
      manager_data_length |= inbuffer[offset++] << 24;
      manager_data.clear();
      manager_data.reserve(manager_data_length);
      for( unsigned i = 0; i < manager_data_length; i++){
      manager_data.emplace_back();
      offset += this->manager_data.back().deserialize(inbuffer + offset);
      }
      unsigned app_data_length = inbuffer[offset++];
      app_data_length |= inbuffer[offset++] << 8;
      app_data_length |= inbuffer[offset++] << 16;
      app_data_length |= inbuffer[offset++] << 24;
      app_data.clear();
      app_data.reserve(app_data_length);
      for( unsigned i = 0; i < app_data_length; i++){
      app_data.emplace_back();
      offset += this->app_data.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "rocon_app_manager_msgs/PairingClient"; };
    const char * getMD5(){ return "0a8112672c3fbf73cb62ec78d67e41bb"; };

  };

}
#endif