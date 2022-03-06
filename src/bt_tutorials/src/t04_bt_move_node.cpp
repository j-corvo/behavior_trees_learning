#include "behaviortree_cpp_v3/bt_factory.h"
#include "say_something.h"
#include "gripper_interface.h"
#include "movebase.h"

int main()
{
  BT::BehaviorTreeFactory factory;
  
  factory.registerSimpleCondition("BatteryOK", std::bind(CheckBattery));
  factory.registerNodeType<MoveBaseAction>("MoveBase");
  factory.registerNodeType<SaySomething>("SaySomething");

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/bt_tutorials/xml/reactive_sequence.xml");

  BT::NodeStatus status;

  std::cout << "\n--- 1st executeTick() ---" << std::endl;
  status = tree.tickRoot();

  SleepMS(150);
  std::cout << "\n--- 2nd executeTick() ---" << std::endl;
  status = tree.tickRoot();

  SleepMS(150);
  std::cout << "\n--- 3rd executeTick() ---" << std::endl;
  status = tree.tickRoot();

  std::cout << std::endl;

  return 0;
}