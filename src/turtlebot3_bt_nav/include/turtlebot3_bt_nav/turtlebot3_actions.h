#ifndef __TURTLEBOT3_ACTIONS_
#define __TURTLEBOT3_ACTIONS_

#include "behaviortree_cpp_v3/action_node.h"

class TurtleBot3Actions : BT::AsyncActionNode
{
  public:
    TurtleBot3Actions(const std::string &name, const BT::NodeConfiguration &config);
    ~TurtleBot3Actions();

    

  private:
    
};

#endif