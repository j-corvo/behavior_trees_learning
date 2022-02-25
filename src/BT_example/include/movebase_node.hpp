#ifndef __MOVEBASE_BT_NODE_HPP_
#define __MOVEBASE_BT_NODE_HPP_

#include "behaviortree_cpp_v3/action_node.h"

// Custom type
struct Pose2D
{
  double x, y, theta;
};

inline void SleepMS(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

namespace BT
{
  // This template specialization is needed only if you want
  // to AUTOMATICALLY convert a NodeParameter into a Pose2D
  // In other words, implement it if you want to be able to do:
  //
  //   TreeNode::getInput<Pose2D>(key, ...)
  //
  template <> inline Pose2D convertFromString(StringView key)
  {
    // three real numbers separated by semicolons
    auto parts = BT::splitString(key, ';');
    if (parts.size() != 3)
    {
      throw BT::RuntimeError("invalid input)");
    }
    else
    {
      Pose2D output;
      output.x = convertFromString<double>(parts[0]);
      output.y = convertFromString<double>(parts[1]);
      output.theta = convertFromString<double>(parts[2]);
      return output;
    }
  }
} // end namespace BT

// This is an asynchronous operation that will run in a separate thread.
// It requires the input port "goal".

class MoveBaseAction : public BT::AsyncActionNode
{
public:
  // Any TreeNode with ports must have a constructor with this signature
  MoveBaseAction(const std::string &name, const BT::NodeConfiguration &config)
      : AsyncActionNode(name, config)
  {
  }

  // It is mandatory to define this static method.
  static BT::PortsList providedPorts()
  {
    return {BT::InputPort<Pose2D>("goal")};
  }

  BT::NodeStatus tick() override; 

  virtual void halt() override
  {
    _halt_requested.store(true);
  }

private:
  std::atomic_bool _halt_requested;
};

//--------------------------------

BT::NodeStatus MoveBaseAction::tick()
{
  Pose2D goal;
  if (!getInput<Pose2D>("goal", goal))
  {
    throw BT::RuntimeError("missing required input [goal]");
  }

  printf("[ MoveBase: STARTED ]. goal: x=%.f y=%.1f theta=%.2f\n", goal.x, goal.y, goal.theta);

  _halt_requested.store(false);
  int count = 0;

  // Pretend that "computing" takes 250 milliseconds.
  // It is up to you to check periodicall _halt_requested and interrupt
  // this tick() if it is true.
  while (!_halt_requested && count++ < 25)
  {
    SleepMS(10);
  }

  std::cout << "[ MoveBase: FINISHED ]" << std::endl;
  return _halt_requested ? BT::NodeStatus::FAILURE : BT::NodeStatus::SUCCESS;
}

#endif   // MOVEBASE_BT_NODE_H
