#ifndef __GRIPPER_INTERFACE_HPP_
#define __GRIPPER_INTERFACE_HPP_

#include "behaviortree_cpp_v3/action_node.h"

class GripperInterface
{
public:
  GripperInterface() : _opened(true)
  {
  }

  BT::NodeStatus open();

  BT::NodeStatus close();

private:
  bool _opened;
};

#endif