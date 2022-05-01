################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

 # Create the component (navigation client)
add_executable(simple_counter)
target_sources(simple_counter
  PRIVATE
    SimpleCounter.cpp)
target_link_libraries(simple_counter
  PRIVATE
    counter_interface
    YARP::YARP_os
    YARP::YARP_init
    YARP::YARP_dev)
