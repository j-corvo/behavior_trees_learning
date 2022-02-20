#ifndef __APPROACH_OBJECT_H_
#define __APPROACH_OBJECT_H_

#include "behaviortree_cpp_v3/action_node.h"

class ApproachObject : public BT::SyncActionNode
{
public:
  ApproachObject(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  // You must override the virtual function tick()
  BT::NodeStatus tick() override
  {
    std::cout << "ApproachObject: " << this->name() << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

#endif