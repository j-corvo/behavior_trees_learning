#include "bt_nav_actions/movebase.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "bt_move_base_node");
  
  ROS_INFO("Move Base Node is initializing...");

  if(ros::ok())
  {
    BTNavAction move_base_action;
    ROS_INFO("Move Base Node is online");
    move_base_action.run();
  }

  return 0;
}