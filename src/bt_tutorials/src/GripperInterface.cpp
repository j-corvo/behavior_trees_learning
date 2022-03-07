#include "gripper_interface.h"

BT::NodeStatus GripperInterface::open()
{
  _opened = true;
  std::cout << "GripperInterface::open" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GripperInterface::close()
{
  std::cout << "GripperInterface::close" << std::endl;
  _opened = false;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
