#ifndef _ROS_rocon_std_msgs_StringArray_h
#define _ROS_rocon_std_msgs_StringArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>

namespace rocon_std_msgs
{

  class StringArray : public ros::Msg
  {
    public:
      std::vector<char*> strings;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned strings_length = strings.size();
      outbuffer[offset++] = (strings_length >> 0) & 0xFF;
      outbuffer[offset++] = (strings_length >> 8) & 0xFF;
      outbuffer[offset++] = (strings_length >> 16) & 0xFF;
      outbuffer[offset++] = (strings_length >> 24) & 0xFF;
      for( unsigned i = 0; i < strings_length; i++){
      {
      uint32_t length_ = strlen( (const char*) this->strings[i]);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->strings[i], length_);
      offset += length_;
      }
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned strings_length = inbuffer[offset++];
      strings_length |= inbuffer[offset++] << 8;
      strings_length |= inbuffer[offset++] << 16;
      strings_length |= inbuffer[offset++] << 24;
      strings.clear();
      strings.reserve(strings_length);
      for( unsigned i = 0; i < strings_length; i++){
      strings.emplace_back();
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->strings.back() = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      }
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/StringArray"; };
    const char * getMD5(){ return "51789d20146e565223d0963361aecda1"; };

  };

}
#endif