#include "behaviortree_cpp_v3/bt_factory.h"

#include "say_something.hpp"
#include "movebase_node.hpp"
#include "print_pose_2d.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<MoveBaseAction>("MoveBase");
  factory.registerNodeType<PrintPose2D>("PrintPose2D");

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/BT_example/xml/remapping_ports_tree.xml");

  BT::NodeStatus status = BT::NodeStatus::RUNNING;
  // Keep on ticking until you get either a SUCCESS or FAILURE state
  while(status == BT::NodeStatus::RUNNING)
  {
    status = tree.tickRoot();
    SleepMS(1); // optional sleep to avoid "busy loops"
  }

  // let's visualize some information about the current state of the blackboards.
  std::cout << "--------------" << std::endl;
  tree.blackboard_stack[0]->debugMessage();
  std::cout << "--------------" << std::endl;
  tree.blackboard_stack[1]->debugMessage();
  std::cout << "--------------" << std::endl;

  return 0;
}