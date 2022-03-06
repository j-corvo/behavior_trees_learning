#ifndef __CalculateGoal_HPP_
#define __CalculateGoal_HPP_

#include "behaviortree_cpp_v3/action_node.h"
#include "convert_from_string.hpp"

using namespace BT;

class CalculateGoal : public SyncActionNode
{
public:
  CalculateGoal(const std::string &name, const NodeConfiguration &config) : SyncActionNode(name, config)
  {
  }

  static PortsList providedPorts()
  {
    return {OutputPort<Position2D>("goal")};
  }

  NodeStatus tick() override
  {
    Position2D mygoal = {1.1, 2.3};
    setOutput<Position2D>("goal", mygoal);
    return NodeStatus::SUCCESS;
  }
};

class PrintTarget : public SyncActionNode
{
public:
  PrintTarget(const std::string &name, const NodeConfiguration &config) : SyncActionNode(name, config)
  {
  }

  static PortsList providedPorts()
  {
    // Optionally, a port can have a human readable description
    const char *description = "Simply print the goal on console...";
    return {InputPort<Position2D>("target", description)};
  }

  NodeStatus tick() override
  {
    auto res = getInput<Position2D>("target");
    if (!res)
    {
      throw RuntimeError("error reading port [target]:", res.error());
    }
    Position2D target = res.value();
    printf("Target positions: [ %.1f, %.1f ]\n", target.x, target.y);
    return NodeStatus::SUCCESS;
  }
};

#endif