#ifndef __COROUTINE_H_
#define __COROUTINE_H_

#include "behaviortree_cpp_v3/action_node.h"

typedef std::chrono::milliseconds Milliseconds;

class MyAsyncAction : public BT::CoroActionNode
{

  public:
    MyAsyncAction(const std::string& name) : CoroActionNode(name, {}) {}
    
    ~MyAsyncAction () {}

  private:
    // This is the ideal skeleton/template of an async action:
    //  - A request to a remote service provider.
    //  - A loop where we check if the reply has been received.
    //  - You may call setStatusRunningAndYield() to "pause".
    //  - Code to execute after the reply.
    //  - A simple way to handle halt().
    BT::NodeStatus tick() override;

    // you might want to cleanup differently if it was halted or successful
    void cleanup(bool halted);

    void halt() override;
};

inline std::chrono::high_resolution_clock::time_point Now();

#endif
