#ifndef __SAY_SOMETHING_H_
#define __SAY_SOMETHING_H_

#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

/**
 * @brief SyncActionNode (synchronous action) with an input port.
 *
 */
class SaySomething : public BT::SyncActionNode
{
  public:
    
    /**
     * @brief Construct a new SaySomething object
     * 
     * @param name 
     * @param config 
     */
    SaySomething(const std::string &name, const BT::NodeConfiguration &config) 
      : BT::SyncActionNode(name, config) {}

    /**
     * @brief Destroy the SaySomething object
     * 
     */
    ~SaySomething() {}

    /**
     * @brief Declare input/output ports of the ThinkWhatToSay object
     *
     * @return BT::PortsList
     */
    static BT::PortsList providedPorts()
    {
      // This action has a single input port called "message"
      // Any port must have a name. The type is optional.
      return { BT::InputPort<std::string>("message")};
    }

    /**
     * @brief Method to execute the action (Action Node)
     * 
     * @return BT::NodeStatus 
     */
    BT::NodeStatus tick() override;
};

/**
 * @brief Simple function that return a NodeStatus
 *
 * @param self
 * @return BT::NodeStatus
 */
BT::NodeStatus SaySomethingSimple(BT::TreeNode &self);

/**
 * @brief Declare input/output ports of SaySomethingSimple node
 * 
 * SimpleActionNodes can not define their own method providedPorts().
 * We should pass a PortsList explicitly if we want the Action to
 * be able to use getInput() or setOutput();
 *
 * @return BT::PortsList
 */
static BT::PortsList providedPorts();

#endif