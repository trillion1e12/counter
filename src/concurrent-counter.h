#pragma once

class ConcurrentCounter
{
  public:
    virtual void increment() = 0;
    virtual int get() = 0;
};
