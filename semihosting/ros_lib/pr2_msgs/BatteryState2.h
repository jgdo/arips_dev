#ifndef _ROS_pr2_msgs_BatteryState2_h
#define _ROS_pr2_msgs_BatteryState2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include <vector>

namespace pr2_msgs
{

  class BatteryState2 : public ros::Msg
  {
    public:
      bool present = 0;
      bool charging = 0;
      bool discharging = 0;
      bool power_present = 0;
      bool power_no_good = 0;
      bool inhibited = 0;
      ros::Time last_battery_update;
      int16_t battery_register[48];
      static const unsigned battery_register_length = 48;
      bool battery_update_flag[48];
      static const unsigned battery_update_flag_length = 48;
      ros::Time battery_register_update[48];
      static const unsigned battery_register_update_length = 48;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->present;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->present);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->charging;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->charging);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->discharging;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->discharging);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->power_present;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->power_present);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->power_no_good;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->power_no_good);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->inhibited;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->inhibited);
      *(outbuffer + offset + 0) = (this->last_battery_update.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_battery_update.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_battery_update.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_battery_update.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_battery_update.sec);
      *(outbuffer + offset + 0) = (this->last_battery_update.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_battery_update.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_battery_update.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_battery_update.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_battery_update.nsec);
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->battery_register[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->battery_register[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->battery_update_flag[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->battery_update_flag[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      *(outbuffer + offset + 0) = (this->battery_register_update[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->battery_register_update[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->battery_register_update[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->battery_register_update[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_register_update[i].sec);
      *(outbuffer + offset + 0) = (this->battery_register_update[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->battery_register_update[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->battery_register_update[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->battery_register_update[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_register_update[i].nsec);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->present = u_.real;
      }
      offset += sizeof(this->present);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charging = u_.real;
      }
      offset += sizeof(this->charging);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->discharging = u_.real;
      }
      offset += sizeof(this->discharging);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_present = u_.real;
      }
      offset += sizeof(this->power_present);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_no_good = u_.real;
      }
      offset += sizeof(this->power_no_good);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->inhibited = u_.real;
      }
      offset += sizeof(this->inhibited);
      this->last_battery_update.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_battery_update.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_battery_update.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_battery_update.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_battery_update.sec);
      this->last_battery_update.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_battery_update.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_battery_update.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_battery_update.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_battery_update.nsec);
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->battery_register[i] = u_.real;
      }
      offset += sizeof(this->battery_register[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_update_flag[i] = u_.real;
      }
      offset += sizeof(this->battery_update_flag[i]);
      }
      for( unsigned i = 0; i < 48; i++){
      this->battery_register_update[i].sec =  ((uint32_t) (*(inbuffer + offset)));
      this->battery_register_update[i].sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->battery_register_update[i].sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->battery_register_update[i].sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->battery_register_update[i].sec);
      this->battery_register_update[i].nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->battery_register_update[i].nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->battery_register_update[i].nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->battery_register_update[i].nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->battery_register_update[i].nsec);
      }
     return offset;
    }

    const char * getType(){ return "pr2_msgs/BatteryState2"; };
    const char * getMD5(){ return "91b4acb000aa990ac3006834f9a99669"; };

  };

}
#endif