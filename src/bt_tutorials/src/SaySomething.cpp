#include "say_something.h"

/**
 * @brief Outputs the message wrote in the output port
 * 
 * @return BT::NodeStatus 
 */
BT::NodeStatus SaySomething::tick() 
{
  auto msg = getInput<std::string>("message");
  // Check if optional is valid. If not, throw its error
  if (!msg)
  {
    throw BT::RuntimeError("missing required input [message]: ", msg.error());
  }

  // use the method value() to extract the valid message.
  std::cout << "Robot says: " << msg.value() << std::endl;
  return BT::NodeStatus::SUCCESS;
}



BT::NodeStatus SaySomethingSimple(BT::TreeNode &self)
{
  auto msg = self.getInput<std::string>("message");

  // Check if optional is valid. If not, throw its error
  if (!msg)
  {
    throw BT::RuntimeError("missing required input [message]: ", msg.error());
  }

  // use the method value() to extract the valid message.
  std::cout << "Robot says: " << msg.value() << std::endl;
  return BT::NodeStatus::SUCCESS;
}