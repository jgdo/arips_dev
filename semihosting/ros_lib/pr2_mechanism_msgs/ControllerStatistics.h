#ifndef _ROS_pr2_mechanism_msgs_ControllerStatistics_h
#define _ROS_pr2_mechanism_msgs_ControllerStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace pr2_mechanism_msgs
{

  class ControllerStatistics : public ros::Msg
  {
    public:
      char * name = nullptr;
      ros::Time timestamp;
      bool running = 0;
      ros::Duration max_time;
      ros::Duration mean_time;
      ros::Duration variance_time;
      int32_t num_control_loop_overruns = 0;
      ros::Time time_last_control_loop_overrun;

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
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->running;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->running);
      *(outbuffer + offset + 0) = (this->max_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_time.sec);
      *(outbuffer + offset + 0) = (this->max_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_time.nsec);
      *(outbuffer + offset + 0) = (this->mean_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mean_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mean_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mean_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean_time.sec);
      *(outbuffer + offset + 0) = (this->mean_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mean_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mean_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mean_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean_time.nsec);
      *(outbuffer + offset + 0) = (this->variance_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->variance_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->variance_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->variance_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variance_time.sec);
      *(outbuffer + offset + 0) = (this->variance_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->variance_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->variance_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->variance_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variance_time.nsec);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->num_control_loop_overruns;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->num_control_loop_overruns);
      *(outbuffer + offset + 0) = (this->time_last_control_loop_overrun.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_last_control_loop_overrun.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_last_control_loop_overrun.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_last_control_loop_overrun.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_last_control_loop_overrun.sec);
      *(outbuffer + offset + 0) = (this->time_last_control_loop_overrun.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_last_control_loop_overrun.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_last_control_loop_overrun.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_last_control_loop_overrun.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_last_control_loop_overrun.nsec);
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
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->running = u_.real;
      }
      offset += sizeof(this->running);
      this->max_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_time.sec);
      this->max_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_time.nsec);
      this->mean_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->mean_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mean_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mean_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mean_time.sec);
      this->mean_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->mean_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mean_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mean_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mean_time.nsec);
      this->variance_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->variance_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->variance_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->variance_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->variance_time.sec);
      this->variance_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->variance_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->variance_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->variance_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->variance_time.nsec);
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
      this->num_control_loop_overruns = u_.real;
      }
      offset += sizeof(this->num_control_loop_overruns);
      this->time_last_control_loop_overrun.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_last_control_loop_overrun.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_last_control_loop_overrun.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_last_control_loop_overrun.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_last_control_loop_overrun.sec);
      this->time_last_control_loop_overrun.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_last_control_loop_overrun.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_last_control_loop_overrun.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_last_control_loop_overrun.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_last_control_loop_overrun.nsec);
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_msgs/ControllerStatistics"; };
    const char * getMD5(){ return "6d15d137eea402018e3c7c8dbecd4b95"; };

  };

}
#endif