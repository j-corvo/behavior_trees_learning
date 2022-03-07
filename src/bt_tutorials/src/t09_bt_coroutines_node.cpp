#include "behaviortree_cpp_v3/bt_factory.h"

#include "coroutines.h"

int main()
{
  // Simple tree: a sequence of two asycnhronous actions,
  // but the second will be halted because of the timeout.

  BT::BehaviorTreeFactory factory;
  factory.registerNodeType<MyAsyncAction>("MyAsyncAction");

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/bt_tutorials/xml/coroutines_tree.xml");

  //---------------------------------------
  // keep executin tick until it returns etiher SUCCESS or FAILURE
  while (tree.tickRoot() == BT::NodeStatus::RUNNING)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  return 0;
}