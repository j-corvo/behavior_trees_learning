#ifndef __GRIPPER_INTERFACE_H_
#define __GRIPPER_INTERFACE_H_

#include "behaviortree_cpp_v3/action_node.h"

// We want to wrap into an ActionNode the methods open() and close()
class GripperInterface
{
public:
  GripperInterface() : _open(true) {}

  BT::NodeStatus open()
  {
    _open = true;
    std::cout << "GripperInterface::open" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

  BT::NodeStatus close()
  {
    std::cout << "GripperInterface::close" << std::endl;
    _open = false;
    return BT::NodeStatus::SUCCESS;
  }

private:
  bool _open; // shared information
};

#endif