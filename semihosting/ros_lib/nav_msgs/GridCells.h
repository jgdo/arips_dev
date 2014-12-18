#ifndef _ROS_nav_msgs_GridCells_h
#define _ROS_nav_msgs_GridCells_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include <vector>

namespace nav_msgs
{

  class GridCells : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float cell_width = 0;
      float cell_height = 0;
      std::vector<geometry_msgs::Point> cells;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->cell_width;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->cell_width);
      {
      union {
        float real;
        uint32_t base;
      } u_;
      u_.real = this->cell_height;
      *(outbuffer + offset + 0) = (u_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_.base >> (8 * 3)) & 0xFF;
      }
      offset += sizeof(this->cell_height);
      unsigned cells_length = cells.size();
      outbuffer[offset++] = (cells_length >> 0) & 0xFF;
      outbuffer[offset++] = (cells_length >> 8) & 0xFF;
      outbuffer[offset++] = (cells_length >> 16) & 0xFF;
      outbuffer[offset++] = (cells_length >> 24) & 0xFF;
      for( unsigned i = 0; i < cells_length; i++){
      offset += this->cells[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      this->cell_width = u_.real;
      }
      offset += sizeof(this->cell_width);
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
      this->cell_height = u_.real;
      }
      offset += sizeof(this->cell_height);
      unsigned cells_length = inbuffer[offset++];
      cells_length |= inbuffer[offset++] << 8;
      cells_length |= inbuffer[offset++] << 16;
      cells_length |= inbuffer[offset++] << 24;
      cells.clear();
      cells.reserve(cells_length);
      for( unsigned i = 0; i < cells_length; i++){
      cells.emplace_back();
      offset += this->cells.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "nav_msgs/GridCells"; };
    const char * getMD5(){ return "b9e4f5df6d28e272ebde00a3994830f5"; };

  };

}
#endif