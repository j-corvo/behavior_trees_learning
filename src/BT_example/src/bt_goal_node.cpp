#include "behaviortree_cpp_v3/bt_factory.h"
#include "goal_interface.hpp"

static const char* xml_text = R"(

  <root main_tree_to_execute = "MainTree" >
    <BehaviorTree ID="MainTree">
      <SequenceStar name="root">
          <CalculateGoal goal="{GoalPosition}"/>
          <PrintTarget   target="{GoalPosition}"/>
          <SetBlackboard output_key="OtherGoal" value="-1;3"/>
          <PrintTarget   target="{OtherGoal}"/>
      </SequenceStar>
    </BehaviorTree>
  </root>
)";

int main()
{
  using namespace BT;

  BehaviorTreeFactory factory;
  factory.registerNodeType<CalculateGoal>("CalculateGoal");
  factory.registerNodeType<PrintTarget>("PrintTarget");

  // Function read a bt from a variable(text) instead of a file
  auto tree = factory.createTreeFromText(xml_text);
  tree.tickRoot();
  
  return 0;
}