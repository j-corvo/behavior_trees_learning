
#ifndef __CROSSDOOR_H_
#define __CROSSDOOR_H_

#include "behaviortree_cpp_v3/bt_factory.h"

namespace CrossDoor
{
  inline void SleepMS(int ms)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  }

  BT::NodeStatus IsDoorOpen();

  BT::NodeStatus IsDoorLocked();

  BT::NodeStatus UnlockDoor();

  BT::NodeStatus PassThroughDoor();

  BT::NodeStatus PassThroughWindow();

  BT::NodeStatus OpenDoor();

  BT::NodeStatus CloseDoor();

  void RegisterNodes(BT::BehaviorTreeFactory &factory);
}

#endif