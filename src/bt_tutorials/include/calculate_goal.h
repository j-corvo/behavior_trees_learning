#ifndef __CalculateGoal_H_
#define __CalculateGoal_H_

#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"
#include "convert_from_string.h"


class CalculateGoal : public BT::SyncActionNode
{
public:
  CalculateGoal(const std::string &name, const BT::NodeConfiguration &config) : BT::SyncActionNode(name, config)
  {
  }

  static BT::PortsList providedPorts()
  {
    return {BT::OutputPort<Position2D>("goal")};
  }

  BT::NodeStatus tick() override;
};

class PrintTarget : public BT::SyncActionNode
{
  public:
    PrintTarget(const std::string &name, const BT::NodeConfiguration &config) : BT::SyncActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
      // Optionally, a port can have a human readable description
      const char *description = "Simply print the goal on console...";
      return {BT::InputPort<Position2D>("target", description)};
    }

    BT::NodeStatus tick() override;
};

void RegisterNodes(BT::BehaviorTreeFactory &factory); 

#endif