#pragma once

#include "behaviortree_cpp_v3/action_node.h"

#include "movebase_node.hpp"

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

  NodeStatus tick() override
  {
    auto res = getInput<Pose2D>("pose");
    if (!res)
    {
      throw RuntimeError("error reading port [pose]:", res.error());
    }
    Pose2D pose = res.value();
    printf("Goal: [ %.1f, %.1f, %.1f ]\n", pose.x, pose.y, pose.theta);
    return NodeStatus::SUCCESS;
  }
};