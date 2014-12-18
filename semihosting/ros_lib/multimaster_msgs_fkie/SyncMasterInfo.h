#ifndef _ROS_multimaster_msgs_fkie_SyncMasterInfo_h
#define _ROS_multimaster_msgs_fkie_SyncMasterInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "multimaster_msgs_fkie/SyncTopicInfo.h"
#include "multimaster_msgs_fkie/SyncServiceInfo.h"

namespace multimaster_msgs_fkie
{

  class SyncMasterInfo : public ros::Msg
  {
    public:
      char * masteruri = nullptr;
      std::vector<char*> nodes;
      std::vector<multimaster_msgs_fkie::SyncTopicInfo> publisher;
      std::vector<multimaster_msgs_fkie::SyncTopicInfo> subscriber;
      std::vector<multimaster_msgs_fkie::SyncServiceInfo> services;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->masteruri);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->masteruri, length_);
      offset += length_;
      }
      unsigned nodes_length = nodes.size();
      outbuffer[offset++] = (nodes_length >> 0) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 8) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 16) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < nodes_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->nodes[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_);
      offset += length_;
      }
      }
      unsigned publisher_length = publisher.size();
      outbuffer[offset++] = (publisher_length >> 0) & 0xFF;
      outbuffer[offset++] = (publisher_length >> 8) & 0xFF;
      outbuffer[offset++] = (publisher_length >> 16) & 0xFF;
      outbuffer[offset++] = (publisher_length >> 24) & 0xFF;
      for( unsigned i = 0; i < publisher_length; i++){
      offset += this->publisher[i].serialize(outbuffer + offset);
      }
      unsigned subscriber_length = subscriber.size();
      outbuffer[offset++] = (subscriber_length >> 0) & 0xFF;
      outbuffer[offset++] = (subscriber_length >> 8) & 0xFF;
      outbuffer[offset++] = (subscriber_length >> 16) & 0xFF;
      outbuffer[offset++] = (subscriber_length >> 24) & 0xFF;
      for( unsigned i = 0; i < subscriber_length; i++){
      offset += this->subscriber[i].serialize(outbuffer + offset);
      }
      unsigned services_length = services.size();
      outbuffer[offset++] = (services_length >> 0) & 0xFF;
      outbuffer[offset++] = (services_length >> 8) & 0xFF;
      outbuffer[offset++] = (services_length >> 16) & 0xFF;
      outbuffer[offset++] = (services_length >> 24) & 0xFF;
      for( unsigned i = 0; i < services_length; i++){
      offset += this->services[i].serialize(outbuffer + offset);
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
      this->masteruri = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      unsigned nodes_length = inbuffer[offset++];
      nodes_length |= inbuffer[offset++] << 8;
      nodes_length |= inbuffer[offset++] << 16;
      nodes_length |= inbuffer[offset++] << 24;
      nodes.clear();
      nodes.reserve(nodes_length);
      for( unsigned i = 0; i < nodes_length; i++){
      nodes.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->nodes.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
      unsigned publisher_length = inbuffer[offset++];
      publisher_length |= inbuffer[offset++] << 8;
      publisher_length |= inbuffer[offset++] << 16;
      publisher_length |= inbuffer[offset++] << 24;
      publisher.clear();
      publisher.reserve(publisher_length);
      for( unsigned i = 0; i < publisher_length; i++){
      publisher.emplace_back();
      offset += this->publisher.back().deserialize(inbuffer + offset);
      }
      unsigned subscriber_length = inbuffer[offset++];
      subscriber_length |= inbuffer[offset++] << 8;
      subscriber_length |= inbuffer[offset++] << 16;
      subscriber_length |= inbuffer[offset++] << 24;
      subscriber.clear();
      subscriber.reserve(subscriber_length);
      for( unsigned i = 0; i < subscriber_length; i++){
      subscriber.emplace_back();
      offset += this->subscriber.back().deserialize(inbuffer + offset);
      }
      unsigned services_length = inbuffer[offset++];
      services_length |= inbuffer[offset++] << 8;
      services_length |= inbuffer[offset++] << 16;
      services_length |= inbuffer[offset++] << 24;
      services.clear();
      services.reserve(services_length);
      for( unsigned i = 0; i < services_length; i++){
      services.emplace_back();
      offset += this->services.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/SyncMasterInfo"; };
    const char * getMD5(){ return "ba4b02792114bcc4bae507c60dd14d66"; };

  };

}
#endif