#include "say_something.h"
#include "think_what_to_say.h"
#include "behaviortree_cpp_v3/loggers/bt_cout_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_zmq_publisher.h"

int main()
{
  BT::BehaviorTreeFactory factory;

  //Registering Nodes in Factory
  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

  BT::PortsList say_something_ports = {BT::InputPort<std::string>("message")};
  factory.registerSimpleAction("SaySomething2", SaySomethingSimple, say_something_ports);

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/bt_tutorials/xml/message_tree.xml");

  // This logger prints state changes on console
  BT::StdCoutLogger logger_cout(tree);

  // This logger publish status changes using ZeroMQ. Used by Groot
  BT::PublisherZMQ publisher_zmq(tree);

  printTreeRecursively(tree.rootNode());
  
  tree.tickRoot();

  return 0;
}