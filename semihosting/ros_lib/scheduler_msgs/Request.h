#ifndef _ROS_scheduler_msgs_Request_h
#define _ROS_scheduler_msgs_Request_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "scheduler_msgs/Resource.h"
#include <vector>
#include "ros/time.h"
#include "ros/duration.h"

namespace scheduler_msgs
{

  class Request : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      std::vector<scheduler_msgs::Resource> resources;
      uint8_t status = 0;
      uint8_t reason = 0;
      ros::Time availability;
      ros::Duration hold_time;
      int16_t priority = 0;
      enum { NEW =  0    };
      enum { RESERVED =  1    };
      enum { WAITING =  2    };
      enum { GRANTED =  3    };
      enum { PREEMPTING =  4    };
      enum { CANCELING =  5    };
      enum { CLOSED =  6    };
      enum { NONE =  0    };
      enum { PREEMPTED =  1    };
      enum { BUSY =  2    };
      enum { UNAVAILABLE =  3    };
      enum { TIMEOUT =  4    };
      enum { BACKGROUND_PRIORITY =  -20000       };
      enum { LOW_PRIORITY =  -10000              };
      enum { DEFAULT_PRIORITY =  0               };
      enum { HIGH_PRIORITY =  10000              };
      enum { CRITICAL_PRIORITY =  20000          };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      unsigned resources_length = resources.size();
      outbuffer[offset++] = (resources_length >> 0) & 0xFF;
      outbuffer[offset++] = (resources_length >> 8) & 0xFF;
      outbuffer[offset++] = (resources_length >> 16) & 0xFF;
      outbuffer[offset++] = (resources_length >> 24) & 0xFF;
      for( unsigned i = 0; i < resources_length; i++){
      offset += this->resources[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->reason >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reason);
      *(outbuffer + offset + 0) = (this->availability.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->availability.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->availability.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->availability.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->availability.sec);
      *(outbuffer + offset + 0) = (this->availability.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->availability.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->availability.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->availability.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->availability.nsec);
      *(outbuffer + offset + 0) = (this->hold_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hold_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hold_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hold_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hold_time.sec);
      *(outbuffer + offset + 0) = (this->hold_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hold_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hold_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hold_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hold_time.nsec);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.real = this->priority;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      }
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      unsigned resources_length = inbuffer[offset++];
      resources_length |= inbuffer[offset++] << 8;
      resources_length |= inbuffer[offset++] << 16;
      resources_length |= inbuffer[offset++] << 24;
      resources.clear();
      resources.reserve(resources_length);
      for( unsigned i = 0; i < resources_length; i++){
      resources.emplace_back();
      offset += this->resources.back().deserialize(inbuffer + offset);
      }
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->reason =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reason);
      this->availability.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->availability.sec);
      this->availability.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->availability.nsec);
      this->hold_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hold_time.sec);
      this->hold_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hold_time.nsec);
      {
      union {
        int16_t real;
        uint16_t base;
      } u_;
      u_.base = 0;
      u_.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_.real;
      }
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/Request"; };
    const char * getMD5(){ return "378a2d120dc8ab31d1f091c50d6033b5"; };

  };

}
#endif