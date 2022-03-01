#include "crossdoor_nodes.hpp"
#include "behaviortree_cpp_v3/bt_factory.h"
#include "behaviortree_cpp_v3/loggers/bt_cout_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_file_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_minitrace_logger.h"
#include "behaviortree_cpp_v3/loggers/bt_zmq_publisher.h"

int main()
{
  using namespace BT;
  using namespace CrossDoor;

  BehaviorTreeFactory factory;

  // register all the actions into the factory
  RegisterNodes(factory);

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/BT_example/xml/crossdoor_tree.xml");

  // This logger prints state changes on console
  StdCoutLogger logger_cout(tree);

  // This logger saves state changes on file
  FileLogger logger_file(tree, "bt_trace.fbl");

  // This logger stores the execution time of each node
  MinitraceLogger logger_minitrace(tree, "bt_trace.json");

#ifdef ZMQ_FOUND
  // This logger publish status changes using ZeroMQ. Used by Groot
  PublisherZMQ publisher_zmq(tree);
#endif

  printTreeRecursively(tree.rootNode());

  NodeStatus status = NodeStatus::RUNNING;
  // Keep on ticking until you get either a SUCCESS or FAILURE state
  while (status == NodeStatus::RUNNING)
  {
    status = tree.tickRoot();
    CrossDoor::SleepMS(1); // optional sleep to avoid "busy loops"
  }
  CrossDoor::SleepMS(2000);
  
  return 0;
}