################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# Create the BT_protocol C++ Library
add_library(counter_interface STATIC)
#yarp_add_idl(IDL_GEN_FILES counter.thrift)
target_sources(counter_interface
  PRIVATE
 # ${IDL_GEN_FILES}
 Counter.cpp
 Counter.h
)
target_include_directories(counter_interface
#   INTERFACE
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(counter_interface
  PRIVATE
    YARP::YARP_os)
