################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# Create the sc_skill library
add_library(sc_skill STATIC)
target_sources(sc_skill
  PRIVATE
SCSkill.cpp
SCSkill.h
)
target_include_directories(sc_skill
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(sc_skill
  PUBLIC
  Qt5::Scxml
    YARP::YARP_os
    YARP::YARP_init
    skill_interface
    )
