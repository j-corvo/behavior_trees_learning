#ifndef __BATERRY_INTERFACE_H_
#define __BATTERY_INTERFACE_H_

#include "behaviortree_cpp_v3/action_node.h"

BT::NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

#endif
