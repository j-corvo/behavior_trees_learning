#include "coroutines.h"

BT::NodeStatus MyAsyncAction::tick()
{
  std::cout << name() << ": Started. Send Request to server." << std::endl;

  BT::TimePoint initial_time = Now();
  BT::TimePoint time_before_reply = initial_time + Milliseconds(100);

  int count = 0;
  bool reply_received = false;

  while (!reply_received)
  {
    if (count++ == 0)
    {
      // call this only once
      std::cout << name() << ": Waiting Reply..." << std::endl;
    }
    // pretend that we received a reply
    if (Now() >= time_before_reply)
    {
      reply_received = true;
    }

    if (!reply_received)
    {
      // set status to RUNNING and "pause/sleep"
      // If halt() is called, we will NOT resume execution
      setStatusRunningAndYield();
    }
  }

  // This part of the code is never reached if halt() is invoked,
  // only if reply_received == true;
  std::cout << name() << ": Done. 'Waiting Reply' loop repeated "
            << count << " times" << std::endl;
  cleanup(false);
  return BT::NodeStatus::SUCCESS;
}

// you might want to cleanup differently if it was halted or successful
void MyAsyncAction::cleanup(bool halted)
{
  if (halted)
  {
    std::cout << name() << ": cleaning up after an halt()\n"
              << std::endl;
  }
  else
  {
    std::cout << name() << ": cleaning up after SUCCESS\n"
              << std::endl;
  }
}

void MyAsyncAction::halt()
{
  std::cout << name() << ": Halted." << std::endl;
  cleanup(true);
  // Do not forget to call this at the end.
  CoroActionNode::halt();
}

inline std::chrono::high_resolution_clock::time_point Now()
{
  return std::chrono::high_resolution_clock::now();
}