#include "calculate_goal.h"

BT::NodeStatus CalculateGoal::tick()
{
  Position2D mygoal = {1.1, 2.3};
  setOutput<Position2D>("goal", mygoal);
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PrintTarget::tick()
{
  auto res = getInput<Position2D>("target");
  if (!res)
  {
    throw BT::RuntimeError("error reading port [target]:", res.error());
  }
  Position2D target = res.value();
  printf("Target positions: [ %.1f, %.1f ]\n", target.x, target.y);
  return BT::NodeStatus::SUCCESS;
}

void RegisterNodes(BT::BehaviorTreeFactory &factory)
{
  factory.registerNodeType<CalculateGoal>("CalculateGoal");
  factory.registerNodeType<PrintTarget>("PrintTarget");
}