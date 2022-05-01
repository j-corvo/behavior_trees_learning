################################################################################
#                                                                              #
# Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

add_subdirectory(custom_leaf_nodes)

# Create the BT executable
add_executable(run_bt)
target_sources(run_bt
  PRIVATE
    run_bt.cpp
    )
target_link_libraries(run_bt
  PRIVATE
    YARP::YARP_os
    YARP::YARP_init
    BT::behaviortree_cpp_v3
    yarp_bt_nodes
    custom_leaf_nodes
    pthread)

    file(COPY xmls/BT_leaf_nodes_example.xml DESTINATION "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
    file(COPY xmls/BT_state_charts_example.xml DESTINATION "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
    file(COPY xmls/BT_rf_modules_example.xml DESTINATION "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
