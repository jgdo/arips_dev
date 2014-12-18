#ifndef _ROS_object_recognition_msgs_RecognizedObjectArray_h
#define _ROS_object_recognition_msgs_RecognizedObjectArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/RecognizedObject.h"
#include <vector>

namespace object_recognition_msgs
{

  class RecognizedObjectArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std::vector<object_recognition_msgs::RecognizedObject> objects;
      std::vector<float> cooccurrence;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned objects_length = objects.size();
      outbuffer[offset++] = (objects_length >> 0) & 0xFF;
      outbuffer[offset++] = (objects_length >> 8) & 0xFF;
      outbuffer[offset++] = (objects_length >> 16) & 0xFF;
      outbuffer[offset++] = (objects_length >> 24) & 0xFF;
      for( unsigned i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      unsigned cooccurrence_length = cooccurrence.size();
      outbuffer[offset++] = (cooccurrence_length >> 0) & 0xFF;
      outbuffer[offset++] = (cooccurrence_length >> 8) & 0xFF;
      outbuffer[offset++] = (cooccurrence_length >> 16) & 0xFF;
      outbuffer[offset++] = (cooccurrence_length >> 24) & 0xFF;
      for( unsigned i = 0; i < cooccurrence_length; i++){
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->cooccurrence[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->cooccurrence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      unsigned objects_length = inbuffer[offset++];
      objects_length |= inbuffer[offset++] << 8;
      objects_length |= inbuffer[offset++] << 16;
      objects_length |= inbuffer[offset++] << 24;
      objects.clear();
      objects.reserve(objects_length);
      for( unsigned i = 0; i < objects_length; i++){
      objects.emplace_back();
      offset += this->objects.back().deserialize(inbuffer + offset);
      }
      unsigned cooccurrence_length = inbuffer[offset++];
      cooccurrence_length |= inbuffer[offset++] << 8;
      cooccurrence_length |= inbuffer[offset++] << 16;
      cooccurrence_length |= inbuffer[offset++] << 24;
      cooccurrence.clear();
      cooccurrence.reserve(cooccurrence_length);
      for( unsigned i = 0; i < cooccurrence_length; i++){
      cooccurrence.emplace_back();
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cooccurrence.back() = u_.real;
      }
      offset += sizeof(this->cooccurrence.back());
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/RecognizedObjectArray"; };
    const char * getMD5(){ return "bad6b1546b9ebcabb49fb3b858d78964"; };

  };

}
#endif