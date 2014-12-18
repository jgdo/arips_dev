#ifndef _ROS_sr_ronex_msgs_ReceiverData_h
#define _ROS_sr_ronex_msgs_ReceiverData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include <vector>
#include "sr_ronex_msgs/ImpulseSample.h"

namespace sr_ronex_msgs
{

  class ReceiverData : public ros::Msg
  {
    public:
      bool data_received = 0;
      std::vector<uint16_t> reserved;
      std::vector<sr_ronex_msgs::ImpulseSample> impulse_response;
      uint16_t first_sample_number = 0;
      std::vector<uint16_t> payload;
      uint32_t rx_frame_information = 0;
      uint16_t std_noise = 0;
      uint32_t flags = 0;
      float FPI = 0;
      float timestamp_ns = 0;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      union {
        bool real;
        uint8_t base;
      } u_;
      u_.real = this->data_received;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      }
      offset += sizeof(this->data_received);
      unsigned reserved_length = reserved.size();
      outbuffer[offset++] = (reserved_length >> 0) & 0xFF;
      outbuffer[offset++] = (reserved_length >> 8) & 0xFF;
      outbuffer[offset++] = (reserved_length >> 16) & 0xFF;
      outbuffer[offset++] = (reserved_length >> 24) & 0xFF;
      for( unsigned i = 0; i < reserved_length; i++){
      *(outbuffer + offset + 0) = (this->reserved[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved[i]);
      }
      unsigned impulse_response_length = impulse_response.size();
      outbuffer[offset++] = (impulse_response_length >> 0) & 0xFF;
      outbuffer[offset++] = (impulse_response_length >> 8) & 0xFF;
      outbuffer[offset++] = (impulse_response_length >> 16) & 0xFF;
      outbuffer[offset++] = (impulse_response_length >> 24) & 0xFF;
      for( unsigned i = 0; i < impulse_response_length; i++){
      offset += this->impulse_response[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->first_sample_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->first_sample_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->first_sample_number);
      unsigned payload_length = payload.size();
      outbuffer[offset++] = (payload_length >> 0) & 0xFF;
      outbuffer[offset++] = (payload_length >> 8) & 0xFF;
      outbuffer[offset++] = (payload_length >> 16) & 0xFF;
      outbuffer[offset++] = (payload_length >> 24) & 0xFF;
      for( unsigned i = 0; i < payload_length; i++){
      *(outbuffer + offset + 0) = (this->payload[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->payload[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->payload[i]);
      }
      *(outbuffer + offset + 0) = (this->rx_frame_information >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rx_frame_information >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rx_frame_information >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rx_frame_information >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rx_frame_information);
      *(outbuffer + offset + 0) = (this->std_noise >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->std_noise >> (8 * 1)) & 0xFF;
      offset += sizeof(this->std_noise);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->FPI;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->FPI);
      {
      int32_t * val_= (int32_t *) &(this->timestamp_ns);
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
      if(this->timestamp_ns < 0) *(outbuffer + offset -1) |= 0x80;
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
      this->data_received = u_.real;
      }
      offset += sizeof(this->data_received);
      unsigned reserved_length = inbuffer[offset++];
      reserved_length |= inbuffer[offset++] << 8;
      reserved_length |= inbuffer[offset++] << 16;
      reserved_length |= inbuffer[offset++] << 24;
      reserved.clear();
      reserved.reserve(reserved_length);
      for( unsigned i = 0; i < reserved_length; i++){
      reserved.emplace_back();
      this->reserved.back() =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved.back() |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved.back());
      }
      unsigned impulse_response_length = inbuffer[offset++];
      impulse_response_length |= inbuffer[offset++] << 8;
      impulse_response_length |= inbuffer[offset++] << 16;
      impulse_response_length |= inbuffer[offset++] << 24;
      impulse_response.clear();
      impulse_response.reserve(impulse_response_length);
      for( unsigned i = 0; i < impulse_response_length; i++){
      impulse_response.emplace_back();
      offset += this->impulse_response.back().deserialize(inbuffer + offset);
      }
      this->first_sample_number =  ((uint16_t) (*(inbuffer + offset)));
      this->first_sample_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->first_sample_number);
      unsigned payload_length = inbuffer[offset++];
      payload_length |= inbuffer[offset++] << 8;
      payload_length |= inbuffer[offset++] << 16;
      payload_length |= inbuffer[offset++] << 24;
      payload.clear();
      payload.reserve(payload_length);
      for( unsigned i = 0; i < payload_length; i++){
      payload.emplace_back();
      this->payload.back() =  ((uint16_t) (*(inbuffer + offset)));
      this->payload.back() |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->payload.back());
      }
      this->rx_frame_information =  ((uint32_t) (*(inbuffer + offset)));
      this->rx_frame_information |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rx_frame_information |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->rx_frame_information |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->rx_frame_information);
      this->std_noise =  ((uint16_t) (*(inbuffer + offset)));
      this->std_noise |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->std_noise);
      this->flags =  ((uint32_t) (*(inbuffer + offset)));
      this->flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flags);
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
      this->FPI = u_.real;
      }
      offset += sizeof(this->FPI);
      {
      uint32_t * val_ = (uint32_t*) &(this->timestamp_ns);
      offset += 3;
      *val_ = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ !=0)
        *val_ |= ((exp_)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->timestamp_ns = -this->timestamp_ns;
      }
     return offset;
    }

    const char * getType(){ return "sr_ronex_msgs/ReceiverData"; };
    const char * getMD5(){ return "290b652e8726c46401de5c21009cba66"; };

  };

}
#endif