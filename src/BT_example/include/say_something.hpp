#ifndef __SAY_SOMETHING_HPP_
#define __SAY_SOMETHING_HPP_

#include "behaviortree_cpp_v3/action_node.h"

// SyncActionNode (synchronous action) with an input port.
class SaySomething : public BT::SyncActionNode
{
  public:
    // If your Node has ports, you must use this constructor signature
    SaySomething(const std::string &name, const BT::NodeConfiguration &config) : BT::SyncActionNode(name, config) {}

    // Destructor
    ~SaySomething() {}

    // It is mandatory to define this static method.
    static BT::PortsList providedPorts()
    {
      // This action has a single input port called "message"
      // Any port must have a name. The type is optional.
      return { BT::InputPort<std::string>("message")};
    }

    // As usual, you must override the virtual function tick()
    BT::NodeStatus tick() override
    {
      BT::Optional<std::string> msg = getInput<std::string>("message");
      // Check if optional is valid. If not, throw its error
      if (!msg)
      {
        throw BT::RuntimeError("missing required input [message]: ", msg.error() );
      }

      // use the method value() to extract the valid message.
      std::cout << "Robot says: " << msg.value() << std::endl;
      return BT::NodeStatus::SUCCESS;
    }
};

#endif