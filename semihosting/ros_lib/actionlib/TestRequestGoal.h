#ifndef _ROS_actionlib_TestRequestGoal_h
#define _ROS_actionlib_TestRequestGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace actionlib
{

  class TestRequestGoal : public ros::Msg
  {
    public:
      int32_t terminate_status = 0;
      bool ignore_cancel = 0;
      char * result_text = nullptr;
      int32_t the_result = 0;
      bool is_simple_client = 0;
      ros::Duration delay_accept;
      ros::Duration delay_terminate;
      ros::Duration pause_status;
      enum { TERMINATE_SUCCESS =  0 };
      enum { TERMINATE_ABORTED =  1 };
      enum { TERMINATE_REJECTED =  2 };
      enum { TERMINATE_LOSE =  3 };
      enum { TERMINATE_DROP =  4 };
      enum { TERMINATE_EXCEPTION =  5 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->terminate_status;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->terminate_status);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->ignore_cancel;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->ignore_cancel);
      {
      uint32_t length_ = strlen( (const char*) this->result_text);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result_text, length_);
      offset += length_;
      }
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->the_result;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->the_result);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->is_simple_client;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->is_simple_client);
      *(outbuffer + offset + 0) = (this->delay_accept.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->delay_accept.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->delay_accept.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->delay_accept.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay_accept.sec);
      *(outbuffer + offset + 0) = (this->delay_accept.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->delay_accept.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->delay_accept.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->delay_accept.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay_accept.nsec);
      *(outbuffer + offset + 0) = (this->delay_terminate.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->delay_terminate.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->delay_terminate.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->delay_terminate.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay_terminate.sec);
      *(outbuffer + offset + 0) = (this->delay_terminate.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->delay_terminate.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->delay_terminate.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->delay_terminate.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay_terminate.nsec);
      *(outbuffer + offset + 0) = (this->pause_status.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pause_status.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pause_status.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pause_status.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pause_status.sec);
      *(outbuffer + offset + 0) = (this->pause_status.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pause_status.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pause_status.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pause_status.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pause_status.nsec);
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
      this->terminate_status = u_.real;
      }
      offset += sizeof(this->terminate_status);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignore_cancel = u_.real;
      }
      offset += sizeof(this->ignore_cancel);
      {
      uint32_t length_;
      memcpy(&length_, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_-1]=0;
      this->result_text = (char *)(inbuffer + offset-1);
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
      this->the_result = u_.real;
      }
      offset += sizeof(this->the_result);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_simple_client = u_.real;
      }
      offset += sizeof(this->is_simple_client);
      this->delay_accept.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->delay_accept.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->delay_accept.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->delay_accept.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->delay_accept.sec);
      this->delay_accept.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->delay_accept.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->delay_accept.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->delay_accept.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->delay_accept.nsec);
      this->delay_terminate.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->delay_terminate.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->delay_terminate.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->delay_terminate.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->delay_terminate.sec);
      this->delay_terminate.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->delay_terminate.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->delay_terminate.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->delay_terminate.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->delay_terminate.nsec);
      this->pause_status.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->pause_status.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pause_status.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pause_status.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pause_status.sec);
      this->pause_status.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->pause_status.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pause_status.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pause_status.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pause_status.nsec);
     return offset;
    }

    const char * getType(){ return "actionlib/TestRequestGoal"; };
    const char * getMD5(){ return "db5d00ba98302d6c6dd3737e9a03ceea"; };

  };

}
#endif