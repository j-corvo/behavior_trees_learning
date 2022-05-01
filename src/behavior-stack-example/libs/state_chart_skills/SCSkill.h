/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

# pragma once

#include <Skill_request.h>

#include <yarp/os/RpcServer.h>
#include <yarp/os/Network.h>
#include <QScxmlStateMachine>
#include <QtScxml/qscxmldatamodel.h>//#include "ConditionExampleStateMachine.h"
//#include "ConditionExampleDataModel.h"

class SCSkill:
        public Skill_request
{
public:
    SCSkill(std::string name, QScxmlStateMachine* sm, QScxmlDataModel* model);

    bool execute();

    SkillStatus get_status() override;
    bool start() override;
    void stop() override;

private:
    std::string m_name;
    yarp::os::Network yarpnet;
    yarp::os::RpcServer port;
    //ConditionExampleDataModel dataModel;
    QScxmlStateMachine* stateMachine;
};
