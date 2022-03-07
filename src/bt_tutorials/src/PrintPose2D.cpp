#include "print_pose_2d.h"

NodeStatus PrintPose2D::tick()
{
  auto res = getInput<Pose2D>("pose");
  if (!res)
  {
    throw RuntimeError("error reading port [pose]:", res.error());
  }
  Pose2D pose = res.value();
  printf("Goal: [ %.1f, %.1f, %.1f ]\n", pose.x, pose.y, pose.theta);
  return NodeStatus::SUCCESS;
}