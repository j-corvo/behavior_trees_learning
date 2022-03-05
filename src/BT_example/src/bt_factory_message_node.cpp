#include "behaviortree_cpp_v3/bt_factory.h"

#include "say_something.hpp"
#include "say_something_simple.hpp"
#include "think_what_to_say.hpp"
#include "behaviortree_cpp_v3/loggers/bt_cout_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_zmq_publisher.h"

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

  // This logger prints state changes on console
  BT::StdCoutLogger logger_cout(tree);

  // This logger publish status changes using ZeroMQ. Used by Groot
  BT::PublisherZMQ publisher_zmq(tree);

  printTreeRecursively(tree.rootNode());
  
  tree.tickRoot();

  return 0;
}