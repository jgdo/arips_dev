#ifndef _ROS_turtlebot_actions_FindFiducialGoal_h
#define _ROS_turtlebot_actions_FindFiducialGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot_actions
{

  class FindFiducialGoal : public ros::Msg
  {
    public:
      char * camera_name = nullptr;
      uint8_t pattern_width = 0;
      uint8_t pattern_height = 0;
      float pattern_size = 0;
      uint8_t pattern_type = 0;
      enum { CHESSBOARD =  1 };
      enum { CIRCLES_GRID =  2 };
      enum { ASYMMETRIC_CIRCLES_GRID = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      {
      uint32_t length_ = strlen( (const char*) this->camera_name);
      memcpy(outbuffer + offset, &length_, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->camera_name, length_);
      offset += length_;
      }
      *(outbuffer + offset + 0) = (this->pattern_width >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pattern_width);
      *(outbuffer + offset + 0) = (this->pattern_height >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pattern_height);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->pattern_size;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->pattern_size);
      *(outbuffer + offset + 0) = (this->pattern_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pattern_type);
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
      this->camera_name = (char *)(inbuffer + offset-1);
      offset += length_;
      }
      this->pattern_width =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pattern_width);
      this->pattern_height =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pattern_height);
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
      this->pattern_size = u_.real;
      }
      offset += sizeof(this->pattern_size);
      this->pattern_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pattern_type);
     return offset;
    }

    const char * getType(){ return "turtlebot_actions/FindFiducialGoal"; };
    const char * getMD5(){ return "8906385fe785bb5733551eb61968fe5b"; };

  };

}
#endif