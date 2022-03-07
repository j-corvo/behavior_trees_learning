cmake_minimum_required(VERSION 3.0.2)
project(bt_tutorials)

# compile as static libraries
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
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

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(bt_node src/t01_bt_node.cpp src/GripperInterface.cpp src/ApproachObject.cpp)
add_executable(bt_message_node src/t02_bt_message_node.cpp src/SaySomething.cpp src/ThinkWhatToSay.cpp)
add_executable(bt_calculate_goal_node src/t03_bt_calculate_goal_node.cpp src/CalculateGoal)
add_executable(bt_move_node src/t04_bt_move_node.cpp src/MoveBase.cpp src/GripperInterface.cpp src/SaySomething.cpp)
add_executable(bt_crossdoor_node src/t05_bt_crossdoor_node.cpp src/CrossDoor.cpp)
add_executable(bt_remap_node src/t06_bt_remap_node.cpp src src/SaySomething.cpp src/MoveBase.cpp src/PrintPose2D.cpp)
add_executable(bt_legacy_node src/t07_bt_legacy_node.cpp)
add_executable(bt_coroutines_node src/t09_bt_coroutines_node.cpp src/Coroutines.cpp)


add_dependencies(bt_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_message_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_calculate_goal_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_move_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_crossdoor_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_remap_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_legacy_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(bt_coroutines_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


target_link_libraries(bt_node ${catkin_LIBRARIES})
target_link_libraries(bt_message_node ${catkin_LIBRARIES})
target_link_libraries(bt_calculate_goal_node ${catkin_LIBRARIES})
target_link_libraries(bt_move_node ${catkin_LIBRARIES})
target_link_libraries(bt_crossdoor_node ${catkin_LIBRARIES})
target_link_libraries(bt_remap_node ${catkin_LIBRARIES})
target_link_libraries(bt_legacy_node ${catkin_LIBRARIES})
target_link_libraries(bt_coroutines_node ${catkin_LIBRARIES})
