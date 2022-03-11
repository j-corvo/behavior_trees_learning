#include "crossdoor_nodes.hpp"

// This function must be implemented in the .cpp file to create
// a plugin that can be loaded at run-time
using namespace CrossDoor;

BT_REGISTER_NODES(factory)
{
  factory.registerSimpleCondition("IsDoorOpen", std::bind(IsDoorOpen));
  factory.registerSimpleAction("PassthroughDoor", std::bind(PassThroughDoor));
  factory.registerSimpleAction("PassthroughWindow", std::bind(PassThroughWindow));
  factory.registerSimpleAction("OpenDoor", std::bind(OpenDoor));
  factory.registerSimpleAction("CloseDoor", std::bind(CloseDoor));
  factory.registerSimpleCondition("IsDoorLocked", std::bind(IsDoorLocked));
  factory.registerSimpleAction("UnlockDoor", std::bind(UnlockDoor));
}


