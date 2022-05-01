/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#pragma once


#include <behaviortree_cpp_v3/condition_node.h>

#include <string>
#include <future>
using namespace BT;
using namespace std;

class ConditionExample :  public ConditionNode
{
public:
    ConditionExample(string name, const NodeConfiguration &config);
    NodeStatus tick() override;
    static PortsList providedPorts();

};
