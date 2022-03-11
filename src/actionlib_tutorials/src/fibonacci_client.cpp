#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_tutorials/FibonacciAction.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_fibonacci");

  // create the action client
  // true causes the client to spin its own thread
  actionlib::SimpleActionClient<actionlib_tutorials::FibonacciAction> action_client("fibonacci", true);

  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  action_client.waitForServer(); //will wait for infinite time

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  actionlib_tutorials::FibonacciGoal goal;
  goal.order = 20;
  action_client.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = action_client.waitForResult(ros::Duration(30.0));

  if(finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = action_client.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("Action did not finish before the time out.");
  
  // exit
  return 0;

}