#ifndef _ROS_concert_msgs_LinkGraph_h
#define _ROS_concert_msgs_LinkGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/LinkNode.h"
#include <vector>
#include "concert_msgs/LinkConnection.h"
#include "concert_msgs/LinkEdge.h"

namespace concert_msgs
{

  class LinkGraph : public ros::Msg
  {
    public:
      std::vector<concert_msgs::LinkNode> nodes;
      std::vector<concert_msgs::LinkConnection> topics;
      std::vector<concert_msgs::LinkConnection> actions;
      std::vector<concert_msgs::LinkEdge> edges;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned nodes_length = nodes.size();
      outbuffer[offset++] = (nodes_length >> 0) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 8) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 16) & 0xFF;
      outbuffer[offset++] = (nodes_length >> 24) & 0xFF;
      for( unsigned i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      unsigned topics_length = topics.size();
      outbuffer[offset++] = (topics_length >> 0) & 0xFF;
      outbuffer[offset++] = (topics_length >> 8) & 0xFF;
      outbuffer[offset++] = (topics_length >> 16) & 0xFF;
      outbuffer[offset++] = (topics_length >> 24) & 0xFF;
      for( unsigned i = 0; i < topics_length; i++){
      offset += this->topics[i].serialize(outbuffer + offset);
      }
      unsigned actions_length = actions.size();
      outbuffer[offset++] = (actions_length >> 0) & 0xFF;
      outbuffer[offset++] = (actions_length >> 8) & 0xFF;
      outbuffer[offset++] = (actions_length >> 16) & 0xFF;
      outbuffer[offset++] = (actions_length >> 24) & 0xFF;
      for( unsigned i = 0; i < actions_length; i++){
      offset += this->actions[i].serialize(outbuffer + offset);
      }
      unsigned edges_length = edges.size();
      outbuffer[offset++] = (edges_length >> 0) & 0xFF;
      outbuffer[offset++] = (edges_length >> 8) & 0xFF;
      outbuffer[offset++] = (edges_length >> 16) & 0xFF;
      outbuffer[offset++] = (edges_length >> 24) & 0xFF;
      for( unsigned i = 0; i < edges_length; i++){
      offset += this->edges[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      unsigned nodes_length = inbuffer[offset++];
      nodes_length |= inbuffer[offset++] << 8;
      nodes_length |= inbuffer[offset++] << 16;
      nodes_length |= inbuffer[offset++] << 24;
      nodes.clear();
      nodes.reserve(nodes_length);
      for( unsigned i = 0; i < nodes_length; i++){
      nodes.emplace_back();
      offset += this->nodes.back().deserialize(inbuffer + offset);
      }
      unsigned topics_length = inbuffer[offset++];
      topics_length |= inbuffer[offset++] << 8;
      topics_length |= inbuffer[offset++] << 16;
      topics_length |= inbuffer[offset++] << 24;
      topics.clear();
      topics.reserve(topics_length);
      for( unsigned i = 0; i < topics_length; i++){
      topics.emplace_back();
      offset += this->topics.back().deserialize(inbuffer + offset);
      }
      unsigned actions_length = inbuffer[offset++];
      actions_length |= inbuffer[offset++] << 8;
      actions_length |= inbuffer[offset++] << 16;
      actions_length |= inbuffer[offset++] << 24;
      actions.clear();
      actions.reserve(actions_length);
      for( unsigned i = 0; i < actions_length; i++){
      actions.emplace_back();
      offset += this->actions.back().deserialize(inbuffer + offset);
      }
      unsigned edges_length = inbuffer[offset++];
      edges_length |= inbuffer[offset++] << 8;
      edges_length |= inbuffer[offset++] << 16;
      edges_length |= inbuffer[offset++] << 24;
      edges.clear();
      edges.reserve(edges_length);
      for( unsigned i = 0; i < edges_length; i++){
      edges.emplace_back();
      offset += this->edges.back().deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/LinkGraph"; };
    const char * getMD5(){ return "6b8d2cdce844002beff4e2b35b1567e2"; };

  };

}
#endif