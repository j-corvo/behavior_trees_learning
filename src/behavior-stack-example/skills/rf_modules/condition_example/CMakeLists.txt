################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################


add_executable(rf_module_condition_example)
target_include_directories(rf_module_condition_example
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_sources(rf_module_condition_example
  PRIVATE
    main.cpp
)

target_link_libraries(rf_module_condition_example
  PRIVATE
    YARP::YARP_os
    YARP::YARP_init
    skill_interface)
