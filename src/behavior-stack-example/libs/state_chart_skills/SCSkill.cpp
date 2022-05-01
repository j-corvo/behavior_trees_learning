/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#include "SCSkill.h"

#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

#include <QTimer>
#include <QDebug>
#include <QTime>
#include <QStateMachine>
#include <QtScxml/qscxmldatamodel.h>
#include <chrono>
#include <thread>

namespace {
YARP_LOG_COMPONENT(CONDITIONEXAMPLE,
                   "scope.skill.SCSkill",
                   yarp::os::Log::minimumPrintLevel(),
                   yarp::os::Log::LogTypeReserved,
                   yarp::os::Log::printCallback(),
                   nullptr)
}


SCSkill::SCSkill(std::string name, QScxmlStateMachine* sm, QScxmlDataModel* model ) :
        m_name(name), stateMachine(sm)
{
  stateMachine->setDataModel(model);
}

bool SCSkill::execute()
{
    if (!yarp::os::NetworkBase::checkNetwork()) {
        qWarning("Error! YARP Network is not initialized");
        return false;
    }

    if (!port.open("/" + m_name + "/BT_rpc/server")) {
        qWarning("Error! Cannot open YARP port");
        return false;
    }

    if(!this->yarp().attachAsServer(port)) {
        qWarning("Error! Could not attach as server");
        return false;
    }

    //stateMachine.start();

    return true;
}

SkillStatus SCSkill::get_status()
{
    yCTrace(CONDITIONEXAMPLE) << "get_status";

    while (true) {
        for (const auto& state : stateMachine->activeStateNames()) {
            if (state == "success") {
                //stateMachine.submitEvent("get_status");
                yCDebug(CONDITIONEXAMPLE) << "get_status returning SKILL_SUCCESS";
                return SKILL_SUCCESS;
            }
            if (state == "failure") {
                //stateMachine.submitEvent("get_status");
                yCDebug(CONDITIONEXAMPLE) << "get_status returning SKILL_FAILURE";
                return SKILL_FAILURE;
            }
       }
    }
}

bool SCSkill::start()
{
    yCTrace(CONDITIONEXAMPLE) << "start";
    stateMachine->submitEvent("start");
    stateMachine->start();

    //wait until a final state is reached

    SkillStatus current_status = get_status();
    while (current_status !=SKILL_FAILURE && current_status !=SKILL_SUCCESS) {
      current_status = get_status();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return current_status == SKILL_SUCCESS;
}

void SCSkill::stop()
{
    yCTrace(CONDITIONEXAMPLE) << "stop";
   stateMachine->submitEvent("stop",  QStateMachine::HighPriority);
   stateMachine->stop();

}
