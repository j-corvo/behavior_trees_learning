#ifndef __CUSTOM_BUILDER_H_
#define __CUSTOM_BUILDER_H_

#include "behaviortree_cpp_v3/action_node.h"

class Action_A: public BT::SyncActionNode
{
  public:
    // additional arguments passed to the constructor
    Action_A(const std::string& name, const BT::NodeConfiguration& config, int arg1, double arg2, std::string arg3) : SyncActionNode(name, config),
    _arg1(arg1),
    _arg2(arg2),
    _arg3(arg3) {}

    //Destructor
    ~Action_A() {}

    // this example doesn't require any port
    static BT::PortsList providedPorts() { return {}; }

    // tick() can access the private members
    BT::NodeStatus tick() override;

  private:
    int _arg1;
    double _arg2;
    std::string _arg3;
};

class Action_B : public BT::SyncActionNode
{
  public:
    // additional arguments passed to the constructor
    Action_B(const std::string &name, const BT::NodeConfiguration &config) : SyncActionNode(name, config) {}

    // Destructor
    ~Action_B() {}

    // this example doesn't require any port
    static BT::PortsList providedPorts() { return {}; }

    // tick() can access the private members
    BT::NodeStatus tick() override;

    void init(int arg1, double arg2, const std::string& arg3)
    {
      _arg1 = (arg1);
      _arg2 = (arg2);
      _arg3 = (arg3);
    }
    
  private:
    int _arg1;
    double _arg2;
    std::string _arg3;
};

#endif
