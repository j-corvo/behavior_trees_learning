#include "approach_object.h"

BT::NodeStatus ApproachObject::tick()
{
  std::cout << "ApproachObject: " << this->name() << std::endl;
  return BT::NodeStatus::SUCCESS;
}