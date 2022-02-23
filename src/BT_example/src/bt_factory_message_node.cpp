#include "behaviortree_cpp_v3/bt_factory.h"

#include "say_something.hpp"
#include "say_something_simple.hpp"
#include "think_what_to_say.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;
  
  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

  // SimpleActionNodes can not define their own method providedPorts().
  // We should pass a PortsList explicitly if we want the Action to
  // be able to use getInput() or setOutput();  
  BT::PortsList say_something_ports = { BT::InputPort<std::string>("message") };
  factory.registerSimpleAction("SaySomething2", SaySomethingSimple, say_something_ports);

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/BT_example/xml/message_tree.xml");

  tree.tickRoot();

  return 0;
}