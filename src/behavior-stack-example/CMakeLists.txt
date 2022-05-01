cmake_minimum_required(VERSION 3.12)

project(behavior-stack-example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5 COMPONENTS Widgets Qml Scxml REQUIRED)
set(CMAKE_AUTOMOC ON)


# BehaviorTree.CPP links Boost::coroutine, but does not look for it
find_package(Boost COMPONENTS coroutine REQUIRED)
find_package(BehaviorTreeV3 REQUIRED)

find_package(YARP COMPONENTS os idl_tools dev REQUIRED)

add_subdirectory(libs)
add_subdirectory(components_interfaces)
add_subdirectory(behavior_trees)
add_subdirectory(skills)
add_subdirectory(components)
