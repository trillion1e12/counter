#pragma once

class ConcurrentCounter
{
  public:
    /// @brief Increase the counter by 1
    /// @return The value of the counter before increment
    virtual int increment() = 0;

    /// @return The current value of the counter
    virtual int get() = 0;

    /// @brief Reset the counter to 0
    virtual void reset() = 0;
};
