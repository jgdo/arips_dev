#ifndef _ROS_rosserial_msgs_TopicInfo_h
#define _ROS_rosserial_msgs_TopicInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_msgs
{

  class TopicInfo : public ros::Msg
  {
    public:
      uint16_t topic_id = 0;
      char * topic_name = nullptr;
      char * message_type = nullptr;
      char * md5sum = nullptr;
      int32_t buffer_size = 0;
      enum { ID_PUBLISHER = 0 };
      enum { ID_SUBSCRIBER = 1 };
      enum { ID_SERVICE_SERVER = 2 };
      enum { ID_SERVICE_CLIENT = 4 };
      enum { ID_PARAMETER_REQUEST = 6 };
      enum { ID_LOG = 7 };
      enum { ID_TIME = 10 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->topic_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topic_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->topic_id);
      {
      uint32_t length_ = strlen( (const char*) this->topic_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->message_type);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message_type, length_);
      offset += length_;
      }
      {
      uint32_t length_ = strlen( (const char*) this->md5sum);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->md5sum, length_);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->buffer_size;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->buffer_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->topic_id =  ((uint16_t) (*(inbuffer + offset)));
      this->topic_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->topic_id);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
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
      this->message_type = (char *)(inbuffer + offset-1);
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
      this->md5sum = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buffer_size = u_.real;
      }
      offset += sizeof(this->buffer_size);
     return offset;
    }

    const char * getType(){ return "rosserial_msgs/TopicInfo"; };
    const char * getMD5(){ return "63aa5e8f1bdd6f35c69fe1a1b9d28e9f"; };

  };

}
#endif