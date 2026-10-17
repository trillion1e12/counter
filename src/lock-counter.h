#pragma once

#include "concurrent-counter.h"
#include <mutex>

class LockCounter : public ConcurrentCounter
{
  private:
    std::mutex mtx;
    int counter = 0;

  public:
    void increment();
    int get();
};
