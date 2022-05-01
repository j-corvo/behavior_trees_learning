
/*
  * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
  * All rights reserved.
  *
  * This software may be modified and distributed under the terms of the
  * BSD-3-Clause license. See the accompanying LICENSE file for details.
  */

#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include<yarp/os/LogStream.h>
#include <iostream>

#include <atomic>
#include <Skill_request.h>

#include <chrono>
#include <thread>

class ActionExample : public yarp::os::RFModule, public Skill_request
{
public:
        ActionExample(std::string name): m_name(name), m_stopped(false) {}
    double getPeriod()
    {
        // module periodicity (seconds), called implicitly by the module.
        return 10.0;
    }
    // This is our main function. Will be called periodically every getPeriod() seconds
    bool updateModule()
    {
        yInfo() << "ActionExample Server Skill Running";
        return true;
    }

    bool configure(yarp::os::ResourceFinder &rf)
    {
        if (!yarp::os::NetworkBase::checkNetwork()) {
            yWarning("Error! YARP Network is not initialized");
            return false;
        }

        if (!m_port.open("/" + m_name + "/BT_rpc/server")) {
            yWarning("Error! Cannot open YARP port");
            return false;
        }

        if(!this->yarp().attachAsServer(m_port)) {
            yWarning("Error! Could not attach as server");
            return false;
        }
        yInfo("Configuration Done!");

        return true;
    }
    // Interrupt function.
    bool interruptModule()
    {
        std::cout << "Interrupting your module, for port cleanup" << '\n';
        return true;
    }
    // Close function, to perform cleanup.
    bool close()
    {
        yInfo() << "Calling close function\n";
        m_port.close();
        return true;
    }

    SkillStatus get_status() override // actually, no longer used
    {
        return m_status;
    }
    bool start() override
    {

        yInfo() << "ActionExample Received a start";
        while(!m_stopped)
        {
            yInfo() << "ActionExample is doing stuff";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        m_stopped = false;

        yInfo() << "ActionExample Done";

        return true;
    }
    void stop() override
    {
        yInfo() << "ActionExample Received a stop";
        m_stopped = true;
    }

private:
    std::string m_name;
    yarp::os::RpcServer m_port;
    std::atomic<SkillStatus> m_status; // actually, no longer used
    std::atomic<bool> m_stopped;
};

int main(int argc, char * argv[])
{
    // initialize yarp network
    yarp::os::Network yarp;

    // create your module
    ActionExample module("RFActionExample");

    // prepare and configure the resource finder
    yarp::os::ResourceFinder rf;
    rf.configure(argc, argv);

    yInfo()<< "Configuring and starting module.";
    // This calls configure(rf) and, upon success, the module execution begins with a call to updateModule()
    if (!module.runModule(rf)) {
        yError() << "Error module did not start\n";
    }
    return 0;
}
