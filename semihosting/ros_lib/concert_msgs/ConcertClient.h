#ifndef _ROS_concert_msgs_ConcertClient_h
#define _ROS_concert_msgs_ConcertClient_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "rocon_app_manager_msgs/App.h"
#include <vector>

namespace concert_msgs
{

  class ConcertClient : public ros::Msg
  {
    public:
      char * name = nullptr;
      char * gateway_name = nullptr;
      char * platform = nullptr;
      char * system = nullptr;
      char * robot = nullptr;
      char * client_status = nullptr;
      char * app_status = nullptr;
      char * status = nullptr;
      ros::Time last_connection_timestamp;
      std::vector<rocon_app_manager_msgs::App> apps;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->gateway_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gateway_name, length_);
      offset += length_;
      }
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
      uint32_t length_ = strlen( (const char*) this->client_status);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->client_status, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->app_status);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->app_status, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->status);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->last_connection_timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_connection_timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_connection_timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_connection_timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_connection_timestamp.sec);
      *(outbuffer + offset + 0) = (this->last_connection_timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_connection_timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_connection_timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_connection_timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_connection_timestamp.nsec);
      unsigned apps_length = apps.size();
      outbuffer[offset++] = (apps_length >> 0) & 0xFF;
      outbuffer[offset++] = (apps_length >> 8) & 0xFF;
      outbuffer[offset++] = (apps_length >> 16) & 0xFF;
      outbuffer[offset++] = (apps_length >> 24) & 0xFF;
      for( unsigned i = 0; i < apps_length; i++){
      offset += this->apps[i].serialize(outbuffer + offset);
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
      this->name = (char *)(inbuffer + offset-1);
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
      this->gateway_name = (char *)(inbuffer + offset-1);
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
      this->client_status = (char *)(inbuffer + offset-1);
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
      this->app_status = (char *)(inbuffer + offset-1);
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
      this->status = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->last_connection_timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_connection_timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_connection_timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_connection_timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_connection_timestamp.sec);
      this->last_connection_timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_connection_timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_connection_timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_connection_timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_connection_timestamp.nsec);
      unsigned apps_length = inbuffer[offset++];
      apps_length |= inbuffer[offset++] << 8;
      apps_length |= inbuffer[offset++] << 16;
      apps_length |= inbuffer[offset++] << 24;
      apps.clear();
      apps.reserve(apps_length);
      for( unsigned i = 0; i < apps_length; i++){
      apps.emplace_back();
      offset += this->apps.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/ConcertClient"; };
    const char * getMD5(){ return "b3a232588ecbbea02126d208e1faa1a9"; };

  };

}
#endif