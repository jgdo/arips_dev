#ifndef _ROS_pr2_msgs_PowerBoardState_h
#define _ROS_pr2_msgs_PowerBoardState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include <vector>

namespace pr2_msgs
{

  class PowerBoardState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * name = nullptr;
      uint32_t serial_num = 0;
      float input_voltage = 0;
      int8_t master_state = 0;
      int8_t circuit_state[3];
      static const unsigned circuit_state_length = 3;
      float circuit_voltage[3];
      static const unsigned circuit_voltage_length = 3;
      bool run_stop = 0;
      bool wireless_stop = 0;
      enum { STATE_NOPOWER = 0 };
      enum { STATE_STANDBY = 1 };
      enum { STATE_PUMPING = 2 };
      enum { STATE_ON = 3 };
      enum { STATE_ENABLED = 3   };
      enum { STATE_DISABLED = 4 };
      enum { MASTER_NOPOWER = 0 };
      enum { MASTER_STANDBY = 1 };
      enum { MASTER_ON = 2 };
      enum { MASTER_OFF = 3 };
      enum { MASTER_SHUTDOWN = 4 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      uint32_t length_ = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->serial_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->serial_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->serial_num >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial_num);
      {
      int32_t * val_= (int32_t *) &(this->input_voltage);
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
      if(this->input_voltage < 0) *(outbuffer + offset -1) |= 0x80;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->master_state;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->master_state);
      for( unsigned i = 0; i < 3; i++){
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.real = this->circuit_state[i];
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->circuit_state[i]);
      }
      for( unsigned i = 0; i < 3; i++){
      {
      int32_t * val_= (int32_t *) &(this->circuit_voltage[i]);
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
      if(this->circuit_voltage[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->run_stop;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->run_stop);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->wireless_stop;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->wireless_stop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      this->serial_num =  ((uint32_t) (*(inbuffer + offset)));
      this->serial_num |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->serial_num |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->serial_num |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->serial_num);
      {
      uint32_t * val_ = (uint32_t*) &(this->input_voltage);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->input_voltage = -this->input_voltage;
      }
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->master_state = u_.real;
      }
      offset += sizeof(this->master_state);
      for( unsigned i = 0; i < 3; i++){
      {
      union {
        int8_t real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->circuit_state[i] = u_.real;
      }
      offset += sizeof(this->circuit_state[i]);
      }
      for( unsigned i = 0; i < 3; i++){
      {
      uint32_t * val_ = (uint32_t*) &(this->circuit_voltage[i]);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->circuit_voltage[i] = -this->circuit_voltage[i];
      }
      }
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->run_stop = u_.real;
      }
      offset += sizeof(this->run_stop);
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wireless_stop = u_.real;
      }
      offset += sizeof(this->wireless_stop);
     return offset;
    }

    const char * getType(){ return "pr2_msgs/PowerBoardState"; };
    const char * getMD5(){ return "08899b671e6a1a449e7ce0000da8ae7b"; };

  };

}
#endif