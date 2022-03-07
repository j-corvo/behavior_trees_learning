#pragma once

#include "behaviortree_cpp_v3/action_node.h"

#include "movebase.h"

using namespace BT;

class PrintPose2D : public SyncActionNode
{
public:
  PrintPose2D(const std::string &name, const NodeConfiguration &config) : SyncActionNode(name, config)
  {
  }

  static PortsList providedPorts()
  {
    // Optionally, a port can have a human readable description
    const char *description = "Simply print the goal on console...";
    return {InputPort<Pose2D>("pose", description)};
  }

  NodeStatus tick() override;

};