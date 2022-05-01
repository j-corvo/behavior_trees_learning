/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

#include <yarp/os/Network.h>
#include <yarp/os/RpcServer.h>

#include <Counter.h>
#include <atomic>
class SimpleCounter : public Counter
{
public:
    SimpleCounter() = default;
    bool open()
    {

        this->yarp().attachAsServer(server_port);
        if (!server_port.open("/Components/SimpleCounter")) {
            yError("Could not open ");
            return false;
        }

        return true;
    }

    void close()
    {
        server_port.close();
    }


    std::int32_t get_value() override
    {
        yWarning("get_counts() called. Value: %d", value.load());
        return value;
    }

    void increase() override
    {
        yWarning("increase called(). New value: %d", value.load());
        value++;
    }

    void decrease() override
    {
        yWarning("decrease called. New value: %d", value.load());
        value--;
    }

    void reset() override
    {
        yWarning("reset_counter called. New value: %d", value.load());
        value = 0;
    }

private:
    std::atomic<int32_t> value{ 0 };
    yarp::os::RpcServer server_port;
};

int main()
{
    yarp::os::Network yarp;

    SimpleCounter simpleCounter;
    if (!simpleCounter.open()) {
        return 1;
    }

    while (true) {
        yInfo("Server running happily");
        yarp::os::Time::delay(10);
    }

    simpleCounter.close();

    return 0;
}
