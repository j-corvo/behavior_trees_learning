/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#pragma once


#include <behaviortree_cpp_v3/action_node.h>

#include <string>
#include <future>
using namespace BT;
using namespace std;

class ActionExample :  public CoroActionNode
{
public:
    ActionExample(string name, const NodeConfiguration &config);
    void halt() override;
    NodeStatus tick() override;
    static PortsList providedPorts();

};
