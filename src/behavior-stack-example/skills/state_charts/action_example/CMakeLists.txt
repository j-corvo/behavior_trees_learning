################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# Create the skill (state machine executable)


add_executable(state_chart_action_example)
target_include_directories(state_chart_action_example
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_sources(state_chart_action_example
  PRIVATE
    main.cpp
    ActionExampleDataModel.cpp
    ActionExampleDataModel.h
)

qt5_add_statecharts(STATECHARTS_FILES ActionExampleStateMachine.scxml)
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/ActionExampleStateMachine.cpp PROPERTIES SKIP_AUTOMOC TRUE)

target_sources(state_chart_action_example
  PRIVATE
    ${STATECHARTS_FILES})

target_link_libraries(state_chart_action_example
  PRIVATE
    Qt5::Scxml
    YARP::YARP_os
    YARP::YARP_init
    counter_interface
    sc_skill)
