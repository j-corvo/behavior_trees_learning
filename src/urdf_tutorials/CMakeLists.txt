cmake_minimum_required(VERSION 3.0.2)
project(urdf_tutorials)

find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY images meshes launch rviz urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})