#ifndef __BATERRY_INTERFACE_HPP_
#define __BATTERY_INTERFACE_HPP_

#include "behaviortree_cpp_v3/action_node.h"

BT::NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

#endif
