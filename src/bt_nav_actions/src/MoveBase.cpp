#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include "bt_nav_actions/movebase.h"

#include "behaviortree_cpp_v3/loggers/bt_zmq_publisher.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

BTNavAction::BTNavAction()
  : nh_("~")
{
}

BTNavAction::~BTNavAction()
{
}

BT::NodeStatus BTNavAction::MoveBaseAction::tick()
{
  Pose2D goal;
  if (!getInput<Pose2D>("goal", goal))
  {
    throw BT::RuntimeError("missing required input [goal]");
  }

  printf("[ MoveBase: STARTED ]. goal: x=%.f y=%.1f theta=%.2f\n", goal.x, goal.y, goal.theta);

  bool status = BTNavAction::goToPose(goal);

  std::cout << "[ MoveBase: FINISHED ]" << std::endl;

  return status ? BT::NodeStatus::FAILURE : BT::NodeStatus::SUCCESS;
}

bool BTNavAction::goToPose(Pose2D pose)
{
  //tell the action client that we want to spin a thread by default
  MoveBaseClient mb_client("move_base", true);

  //wait for the action server to come up
  while(!mb_client.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = pose.x;
  goal.target_pose.pose.position.y = pose.y;
  goal.target_pose.pose.orientation.z = pose.theta;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  mb_client.sendGoal(goal);

  mb_client.waitForResult();

  if(mb_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Hooray, goal reached");
    return true;
  }
  else
  {
    ROS_INFO("The base failed to reache teh goal for some reason");
    return false;
  }
}

void BTNavAction::run()
{
  ros::Rate r(1);
  
  BT::BehaviorTreeFactory factory;      
  RegisterNodes(factory, *this);

  auto tree = factory.createTreeFromFile("/home/rythm/thesis_ws/src/bt_nav_actions/xml/go_to_pose.xml");

  //DEBUG LOGGERS
  // This logger publish status changes using ZeroMQ. Used by Groot
  BT::PublisherZMQ publisher_zmq(tree);

  //Because bt connection on Groot 
  // it needs to have a delay before the tree appears 
  sleep(10); 

  tree.tickRoot();
  
//   while (ros::ok())
//   {
//       tree.tickRoot();
//       r.sleep();
//       ros::spinOnce();
//   }
}