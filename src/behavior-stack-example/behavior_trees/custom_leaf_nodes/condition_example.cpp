/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/


#include <behaviortree_cpp_v3/condition_node.h>
#include "condition_example.h"

#include <chrono>
#include <thread>


ConditionExample::ConditionExample(string name, const NodeConfiguration& config) :
    ConditionNode(name, config)
{

}

NodeStatus ConditionExample::tick()
{
    return NodeStatus::SUCCESS;
}

PortsList ConditionExample::providedPorts()
{
    return { };
}
