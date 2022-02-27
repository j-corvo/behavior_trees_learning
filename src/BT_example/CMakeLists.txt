cmake_minimum_required(VERSION 3.0.2)
project(BT_example)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

# compile as static libraries
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslib
  behaviortree_cpp_v3
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES BT_example
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/BT_example.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(bt_factory_node src/bt_factory_node.cpp)
add_executable(bt_factory_message_node src/bt_factory_message_node.cpp)
add_executable(bt_goal_node src/bt_goal_node.cpp)
add_executable(bt_mission_node src/bt_mission_node.cpp)
add_executable(bt_crossdoor_node src/bt_crossdoor_node.cpp)
add_executable(bt_remap_ports_node src/bt_remap_ports_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(bt_factory_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_factory_message_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_goal_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_mission_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_crossdoor_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_remap_ports_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(bt_factory_node ${catkin_LIBRARIES})
target_link_libraries(bt_factory_message_node ${catkin_LIBRARIES})
target_link_libraries(bt_goal_node ${catkin_LIBRARIES})
target_link_libraries(bt_mission_node ${catkin_LIBRARIES})
target_link_libraries(bt_crossdoor_node ${catkin_LIBRARIES})
target_link_libraries(bt_remap_ports_node ${catkin_LIBRARIES})

# add_library(bt_sample_nodes STATIC
#     movebase_node.cpp )

# target_link_libraries(bt_sample_nodes PRIVATE behaviortree_cpp_v3)
# set_target_properties(bt_sample_nodes PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BEHAVIOR_TREE_LIB_DESTINATION} )

# # to create a plugin, compile them in this way instead

# add_library(movebase_node_dyn   SHARED movebase_node.cpp )
# target_link_libraries(movebase_node_dyn PRIVATE behaviortree_cpp_v3)
# target_compile_definitions(movebase_node_dyn PRIVATE  BT_PLUGIN_EXPORT )
# set_target_properties(movebase_node_dyn PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${BEHAVIOR_TREE_BIN_DESTINATION} )
