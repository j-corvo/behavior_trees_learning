/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#include "ConditionExampleDataModel.h"
#include <QDebug>
#include <QTimer>
#include <QScxmlStateMachine>



bool ConditionExampleDataModel::setup(const QVariantMap &initialDataValues)
{
    Q_UNUSED(initialDataValues)

    if (!yarp::os::NetworkBase::checkNetwork()) {
        qWarning("Error! YARP Network is not initialized");
        return false;
    }

    // open ports
//
     if (!client_port.open("/ConditionExample/CounterClient")) {
         qWarning("Error! Cannot open YARP port with command: client_port_batteryReader.open(/BatteryReaderClient) " );
         return false;
     }

     // attach services as clients

     if(!counter.yarp().attachAsClient(client_port)) {
         qWarning("Error! Could not attach as client with command : batteryReader.yarp().attachAsClient(client_port_batteryReader) "  );
         return false;
 }
     // open connections to components

     if (!yarp::os::Network::connect(client_port.getName(), "/Components/SimpleCounter")) {
         qWarning("Error! Could not connect to server : /Components/SimpleCounter " );
         return false;
     }

    return true;
}
