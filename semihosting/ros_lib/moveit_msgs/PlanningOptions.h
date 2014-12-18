#ifndef _ROS_moveit_msgs_PlanningOptions_h
#define _ROS_moveit_msgs_PlanningOptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlanningScene.h"

namespace moveit_msgs
{

  class PlanningOptions : public ros::Msg
  {
    public:
      moveit_msgs::PlanningScene planning_scene_diff;
      bool plan_only = 0;
      bool look_around = 0;
      int32_t look_around_attempts = 0;
      float max_safe_execution_cost = 0;
      bool replan = 0;
      int32_t replan_attempts = 0;
      float replan_delay = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->planning_scene_diff.serialize(outbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->plan_only;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->plan_only);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->look_around;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->look_around);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->look_around_attempts;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->look_around_attempts);
      {
      int32_t * val_= (int32_t *) &(this->max_safe_execution_cost);
      int32_t exp_ = (((*val_)>>23)&255);
      if(exp_ != 0)
        exp_ += 1023-127;
      int32_t sig_ = *val_;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_<<5) & 0xff;
      *(outbuffer + offset++) = (sig_>>3) & 0xff;
      *(outbuffer + offset++) = (sig_>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_<<4) & 0xF0) | ((sig_>>19)&0x0F);
      *(outbuffer + offset++) = (exp_>>4) & 0x7F;
      if(this->max_safe_execution_cost < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->replan;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->replan);
      {
      union {
        int32_t real;
        uint32_t base;
      } u_;
      u_.real = this->replan_attempts;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->replan_attempts);
      {
      int32_t * val_= (int32_t *) &(this->replan_delay);
      int32_t exp_ = (((*val_)>>23)&255);
      if(exp_ != 0)
        exp_ += 1023-127;
      int32_t sig_ = *val_;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_<<5) & 0xff;
      *(outbuffer + offset++) = (sig_>>3) & 0xff;
      *(outbuffer + offset++) = (sig_>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_<<4) & 0xF0) | ((sig_>>19)&0x0F);
      *(outbuffer + offset++) = (exp_>>4) & 0x7F;
      if(this->replan_delay < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->planning_scene_diff.deserialize(inbuffer + offset);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_only = u_.real;
      }
      offset += sizeof(this->plan_only);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->look_around = u_.real;
      }
      offset += sizeof(this->look_around);
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
      this->look_around_attempts = u_.real;
      }
      offset += sizeof(this->look_around_attempts);
      {
      uint32_t * val_ = (uint32_t*) &(this->max_safe_execution_cost);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_safe_execution_cost = -this->max_safe_execution_cost;
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replan = u_.real;
      }
      offset += sizeof(this->replan);
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
      this->replan_attempts = u_.real;
      }
      offset += sizeof(this->replan_attempts);
      {
      uint32_t * val_ = (uint32_t*) &(this->replan_delay);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->replan_delay = -this->replan_delay;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningOptions"; };
    const char * getMD5(){ return "3934e50ede2ecea03e532aade900ab50"; };

  };

}
#endif