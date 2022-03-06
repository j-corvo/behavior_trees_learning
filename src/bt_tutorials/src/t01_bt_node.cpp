#include "behaviortree_cpp_v3/bt_factory.h"

// files that contains the custom nodes definitions
#include "approach_object.h"
#include "gripper_interface.h"

int main()
{
  // We use the BehaviorTreeFactory to register our custom nodes
  BT::BehaviorTreeFactory factory;
  GripperInterface gripper;

  // The recommended way to create a Node is through inheritance.
  factory.registerNodeType<ApproachObject>("ApproachObject");

  // Registering a SimpleActionNode using a function pointer.
  // you may also use C++11 lambdas instead of std::bind
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));

  //Another way to register modes form a class
  factory.registerSimpleAction("OpenGripper", std::bind(&GripperInterface::open, &gripper));
  factory.registerSimpleAction("CloseGripper", std::bind(&GripperInterface::close, &gripper));

  // Trees are created at deployment-time (i.e. at run-time, but only
  // once at the beginning).

  // IMPORTANT: when the object "tree" goes out of scope, all the
  // TreeNodes are destroyed
  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/bt_tutorials/xml/my_tree.xml");

  // To "execute" a Tree you need to "tick" it.
  // The tick is propagated to the children based on the logic of the tree.
  // In this case, the entire sequence is executed, because all the children
  // of the Sequence return SUCCESS.
  tree.tickRoot();

  return 0;
}
  