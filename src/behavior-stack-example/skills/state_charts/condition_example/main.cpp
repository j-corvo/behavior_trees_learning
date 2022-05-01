/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/


#include <QCoreApplication>
#include <QCommandLineParser>
#include <yarp/os/ResourceFinder.h>
#include <SCSkill.h>
#include "ConditionExampleDataModel.h"
#include "ConditionExampleStateMachine.h"

int main(int argc, char **argv)
{
  QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("SCConditionExample");
    QCoreApplication::setApplicationVersion("0.1");

    ConditionExampleDataModel model;
    ConditionExampleStateMachine sm;
    SCSkill skill("SCConditionExample", &sm, &model);
    if (!skill.execute()) {
        return 1;
    }

    int ret = app.exec();

    return ret;
}
