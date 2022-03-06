#ifndef __COVERT_FROM_STRING_HPP_
#define __COVERT_FROM_STRING_HPP_

#include "behaviortree_cpp_v3/action_node.h"

struct  Position2D
{
  double x;
  double y;
};

template <> inline Position2D BT::convertFromString(StringView str)
{
  // The next line should be removed...
  printf("Converting string: \"%s\"\n", str.data());

  // We expect real numbers separated by semicolons
  auto parts = splitString(str, ';');
  if (parts.size() != 2)
  {
    throw BT::RuntimeError("invalid input)");
  }
  else
  {
    Position2D output;
    output.x = convertFromString<double>(parts[0]);
    output.y = convertFromString<double>(parts[1]);
    return output;
  }
}

#endif