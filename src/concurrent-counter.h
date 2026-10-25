#pragma once

class ConcurrentCounter
{
  public:
    /// @brief Increase the counter by 1
    /// @return The value of the counter before increment
    virtual int increment() = 0;

    /// @return The current value of the counter
    virtual int get() = 0;
};
