#ifndef _ROS_object_recognition_msgs_TableArray_h
#define _ROS_object_recognition_msgs_TableArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/Table.h"
#include <vector>

namespace object_recognition_msgs
{

  class TableArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<object_recognition_msgs::Table> tables;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned tables_length = tables.size();
      outbuffer[offset++] = (tables_length >> 0) & 0xFF;
      outbuffer[offset++] = (tables_length >> 8) & 0xFF;
      outbuffer[offset++] = (tables_length >> 16) & 0xFF;
      outbuffer[offset++] = (tables_length >> 24) & 0xFF;
      for( unsigned i = 0; i < tables_length; i++){
      offset += this->tables[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned tables_length = inbuffer[offset++];
      tables_length |= inbuffer[offset++] << 8;
      tables_length |= inbuffer[offset++] << 16;
      tables_length |= inbuffer[offset++] << 24;
      tables.clear();
      tables.reserve(tables_length);
      for( unsigned i = 0; i < tables_length; i++){
      tables.emplace_back();
      offset += this->tables.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/TableArray"; };
    const char * getMD5(){ return "d1c853e5acd0ed273eb6682dc01ab428"; };

  };

}
#endif