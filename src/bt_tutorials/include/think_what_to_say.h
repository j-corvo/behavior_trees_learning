#ifndef __THINK_WHAT_TO_SAY_H_
#define __THINK_WHAT_TO_SAY_H_

#include "behaviortree_cpp_v3/action_node.h"

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
  /**
   * @brief Construct a new ThinkWhatToSay object
   * 
   * @param name 
   * @param config 
   */
  ThinkWhatToSay(const std::string &name, const BT::NodeConfiguration &config)
      : BT::SyncActionNode(name, config) {}

  /**
   * @brief Destroy the ThinkWhatToSay object
   * 
   */
  ~ThinkWhatToSay() {}

  /**
   * @brief Declare input/output ports of the ThinkWhatToSay object
   *
   * @return BT::PortsList
   */
  static BT::PortsList providedPorts()
  {
    return {BT::OutputPort<std::string>("text")};
  }

  /**
   * @brief Execute node
   *
   * @return BT::NodeStatus
   */
  BT::NodeStatus tick() override;
};

#endif