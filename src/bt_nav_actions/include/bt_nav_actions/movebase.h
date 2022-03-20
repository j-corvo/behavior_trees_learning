#ifndef __MOVEBASE_BT_NODE_H_
#define __MOVEBASE_BT_NODE_H_

#include <ros/ros.h>

#include "behaviortree_cpp_v3/bt_factory.h"

struct Pose2D
{
  double x, y, theta;
};

template <> inline Pose2D BT::convertFromString(BT::StringView key)
{
  // three real numbers separated by semicolons
  auto parts = BT::splitString(key, ';');
  if (parts.size() != 3)
  {
    throw BT::RuntimeError("invalid input)");
  }
  else
  {
    Pose2D output;
    output.x = convertFromString<double>(parts[0]);
    output.y = convertFromString<double>(parts[1]);
    output.theta = convertFromString<double>(parts[2]);
    return output;
  }
}

class BTNavAction
{

  public:
    BTNavAction();
    
    ~BTNavAction();

    void run();
    
    static bool goToPose(Pose2D pose);
  
  private:
      ros::NodeHandle nh_;
      BT::Tree tree;


  class MoveBaseAction : public BT::AsyncActionNode
  {
    public:
      MoveBaseAction(const std::string& name, const BT::NodeConfiguration& config, const BTNavAction& e)
        : AsyncActionNode(name, config)
      {
      }

      ~MoveBaseAction()
      {
      }

      static BT::PortsList providedPorts()
      {
        return {BT::InputPort<Pose2D>("goal")};
      }

      BT::NodeStatus tick() override; 

    private:
  };

  inline void RegisterNodes(BT::BehaviorTreeFactory &factory, BTNavAction& e)
  {
    BT::NodeBuilder GoToPose = [&e](const std::string &name, const BT::NodeConfiguration &config)
    {
      return std::make_unique<MoveBaseAction>(name, config, e);
    };

    factory.registerBuilder<MoveBaseAction>("GoToPose", GoToPose);
  }
};

#endif 
