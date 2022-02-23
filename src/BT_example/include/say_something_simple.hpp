#ifndef __SAY_SOMETHING_SIMPLE_H_
#define __SAY_SOMETHING_SIMPLE_H_

#include "behaviortree_cpp_v3/action_node.h"

// Simple function that return a NodeStatus
BT::NodeStatus SaySomethingSimple(BT::TreeNode &self)
{
  BT::Optional<std::string> msg =self.getInput<std::string>("message");

  // Check if optional is valid. If not, throw its error
  if(!msg)
  {
    throw BT::RuntimeError("missing required input [message]: ", msg.error());
  }

  // use the method value() to extract the valid message.
  std::cout << "Robot says: " << msg.value() << std::endl;
  return BT::NodeStatus::SUCCESS;
}

static BT::PortsList providedPorts();

#endif