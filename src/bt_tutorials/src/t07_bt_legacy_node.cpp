#include "behaviortree_cpp_v3/bt_factory.h"
#include "legacy_code.h"

static const char *xml_text = R"(

 <root>
     <BehaviorTree>
        <MoveTo  goal="-1;3;0.5" />
     </BehaviorTree>
 </root>
 )";

 int main()
 {
   using namespace BT;

   MyLegacyMoveTo move_to;

   // Here we use a lambda that captures the reference of move_to
   auto MoveToWrapperWithLambda = [&move_to](TreeNode& parent_node) -> NodeStatus
   {
    Point3D goal;
    // thanks to parent_node, you can access easily the input and output ports.
    parent_node.getInput("goal", goal);

    bool res = move_to.go(goal);
    // convert bool to NodeStatus
    return res ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
   };

   BehaviorTreeFactory factory;

   // Register the lambda with BehaviorTreeFactory::registerSimpleAction

   PortsList ports = { BT::InputPort<Point3D>("goal") };
   factory.registerSimpleAction("MoveTo", MoveToWrapperWithLambda, ports);
   
   auto tree = factory.createTreeFromText(xml_text);

   tree.tickRoot();

   return 0;
 }