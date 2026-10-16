#pragma once

#include "concurrent-counter.h"
#include <mutex>

using namespace std;

class LockCounter : public ConcurrentCounter
{
  private:
    mutex mtx;
    int counter;

  public:
    LockCounter();
    void increment();
    int get();
};
