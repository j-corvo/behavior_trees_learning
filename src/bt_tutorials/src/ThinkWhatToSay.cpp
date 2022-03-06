#include "think_what_to_say.h"

/**
 * @brief Set an output port to the blackboard
 * 
 * @return BT::NodeStatus 
 */
BT::NodeStatus ThinkWhatToSay::tick()
{
  // the output may change at each tick(). Here we keep it simple.
  setOutput("text", "The answer is 42");
  return BT::NodeStatus::SUCCESS;
}