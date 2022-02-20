#ifndef __THINK_WHAT_TO_SAY_H_
#define __THINK_WHAT_TO_SAY_H_

#include "behaviortree_cpp_v3/action_node.h"

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
  ThinkWhatToSay(const std::string &name, const BT::NodeConfiguration &config)
      : SyncActionNode(name, config)
  {
  }

  static BT::PortsList providedPorts()
  {
    return {BT::OutputPort<std::string>("text")};
  }

  // This Action writes a value into the port "text"
  BT::NodeStatus tick() override
  {
    // the output may change at each tick(). Here we keep it simple.
    setOutput("text", "The answer is 42");
    return BT::NodeStatus::SUCCESS;
  }
};

#endif