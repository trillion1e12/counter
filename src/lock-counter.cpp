#include "lock-counter.h"

LockCounter::LockCounter() : counter{0}
{
}

void LockCounter::increment()
{
    mtx.lock();
    ++counter;
    mtx.unlock();
}

int LockCounter::get()
{
    mtx.lock();
    int current_count = counter;
    mtx.unlock();
    return current_count;
}
