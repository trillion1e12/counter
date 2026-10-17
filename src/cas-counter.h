#pragma once

#include "concurrent-counter.h"
#include <atomic>

class CasCounter : public ConcurrentCounter
{
  private:
    std::atomic<int> counter = 0;

  public:
    void increment();
    int get();
};
