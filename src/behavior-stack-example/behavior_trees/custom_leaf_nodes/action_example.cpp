/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#include <behaviortree_cpp_v3/action_node.h>

#include "action_example.h"

#include <chrono>
#include <thread>


ActionExample::ActionExample(string name, const NodeConfiguration& config) :
    CoroActionNode(name, config)
{

}

NodeStatus ActionExample::tick()
{

    unsigned int i = 0;
    while(i++ < 10)
    {
        setStatusRunningAndYield();
    }

    return NodeStatus::SUCCESS;
}

void ActionExample::halt()
{

    CoroActionNode::halt();
}


PortsList ActionExample::providedPorts()
{
    return { };
}
