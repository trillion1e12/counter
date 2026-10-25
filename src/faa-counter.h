#pragma once

#include "concurrent-counter.h"
#include <atomic>

class FaaCounter : public ConcurrentCounter
{
  private:
    std::atomic<int> counter = 0;

  public:
    int increment();
    int get();
};
