#ifndef __GRIPPER_INTERFACE_H_
#define __GRIPPER_INTERFACE_H_

#include "behaviortree_cpp_v3/basic_types.h"

class GripperInterface
{
public:
  GripperInterface() : _opened(true) {}

  BT::NodeStatus open();

  BT::NodeStatus close();

private:
  bool _opened;
};

BT::NodeStatus CheckBattery();

#endif