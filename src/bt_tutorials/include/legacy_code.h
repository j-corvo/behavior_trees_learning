#ifndef __LEGACY_CODE_H_
#define __LEGACY_CODE_H_

#include <iostream>

#include "behaviortree_cpp_v3/basic_types.h"

// This is my custom type.
struct  Point3D 
{
  double x, y, z;
};

// We want to create an ActionNode to calls method MyLegacyMoveTo::go
class MyLegacyMoveTo
{
  public:
    bool go(Point3D goal)
    {
      printf("Going to: %f %f %f\n", goal.x, goal.y, goal.z);
      return true;
    }
};

namespace BT
{
  template <> Point3D convertFromString(StringView key)
  {
    // three real numbers separated by semicolons
    auto parts = BT::splitString(key, ';');
    if(parts.size() != 3)
    {
      throw RuntimeError("invalid input");
    }
    else
    {
      Point3D output;
      output.x = convertFromString<double>(parts[0]);
      output.y = convertFromString<double>(parts[1]);
      output.z = convertFromString<double>(parts[2]);

      return output;
    }
  }
}

#endif
