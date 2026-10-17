#include "lock-counter.h"

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
