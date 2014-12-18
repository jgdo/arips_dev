#ifndef _ROS_SERVICE_TranslateRecognitionId_h
#define _ROS_SERVICE_TranslateRecognitionId_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace household_objects_database_msgs
{

static const char TRANSLATERECOGNITIONID[] = "household_objects_database_msgs/TranslateRecognitionId";

  class TranslateRecognitionIdRequest : public ros::Msg
  {
    public:
      char * recognition_id = nullptr;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->recognition_id);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->recognition_id, length_);
      offset += length_;
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
      this->recognition_id = (char *)(inbuffer + offset-1);
      offset += length_;
      }
     return offset;
    }

    const char * getType(){ return TRANSLATERECOGNITIONID; };
    const char * getMD5(){ return "4d95610f63ed69a670a8f8aaa3c6aa36"; };

  };

  class TranslateRecognitionIdResponse : public ros::Msg
  {
    public:
      int32_t household_objects_id = 0;
      int32_t ID_NOT_FOUND = 0;
      int32_t DATABASE_ERROR = 0;
      int32_t OTHER_ERROR = 0;
      int32_t result = 0;
      enum { SUCCESS = 0 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->household_objects_id;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->household_objects_id);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->ID_NOT_FOUND;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->ID_NOT_FOUND);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->DATABASE_ERROR;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->DATABASE_ERROR);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->OTHER_ERROR;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->OTHER_ERROR);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->result;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      this->household_objects_id = u_.real;
      }
      offset += sizeof(this->household_objects_id);
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
      this->ID_NOT_FOUND = u_.real;
      }
      offset += sizeof(this->ID_NOT_FOUND);
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
      this->DATABASE_ERROR = u_.real;
      }
      offset += sizeof(this->DATABASE_ERROR);
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
      this->OTHER_ERROR = u_.real;
      }
      offset += sizeof(this->OTHER_ERROR);
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
      this->result = u_.real;
      }
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return TRANSLATERECOGNITIONID; };
    const char * getMD5(){ return "b4afd505fbee150bf06acaffa82e84cf"; };

  };

  class TranslateRecognitionId {
    public:
    typedef TranslateRecognitionIdRequest Request;
    typedef TranslateRecognitionIdResponse Response;
  };

}
#endif
