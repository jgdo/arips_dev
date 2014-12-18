#ifndef _ROS_sensor_msgs_PointCloud_h
#define _ROS_sensor_msgs_PointCloud_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"
#include <vector>
#include "sensor_msgs/ChannelFloat32.h"

namespace sensor_msgs
{

  class PointCloud : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<geometry_msgs::Point32> points;
      std::vector<sensor_msgs::ChannelFloat32> channels;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned points_length = points.size();
      outbuffer[offset++] = (points_length >> 0) & 0xFF;
      outbuffer[offset++] = (points_length >> 8) & 0xFF;
      outbuffer[offset++] = (points_length >> 16) & 0xFF;
      outbuffer[offset++] = (points_length >> 24) & 0xFF;
      for( unsigned i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      unsigned channels_length = channels.size();
      outbuffer[offset++] = (channels_length >> 0) & 0xFF;
      outbuffer[offset++] = (channels_length >> 8) & 0xFF;
      outbuffer[offset++] = (channels_length >> 16) & 0xFF;
      outbuffer[offset++] = (channels_length >> 24) & 0xFF;
      for( unsigned i = 0; i < channels_length; i++){
      offset += this->channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned points_length = inbuffer[offset++];
      points_length |= inbuffer[offset++] << 8;
      points_length |= inbuffer[offset++] << 16;
      points_length |= inbuffer[offset++] << 24;
      points.clear();
      points.reserve(points_length);
      for( unsigned i = 0; i < points_length; i++){
      points.emplace_back();
      offset += this->points.back().deserialize(inbuffer + offset);
      }
      unsigned channels_length = inbuffer[offset++];
      channels_length |= inbuffer[offset++] << 8;
      channels_length |= inbuffer[offset++] << 16;
      channels_length |= inbuffer[offset++] << 24;
      channels.clear();
      channels.reserve(channels_length);
      for( unsigned i = 0; i < channels_length; i++){
      channels.emplace_back();
      offset += this->channels.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/PointCloud"; };
    const char * getMD5(){ return "d8e9c3f5afbdd8a130fd1d2763945fca"; };

  };

}
#endif