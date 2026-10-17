#include "lock-counter.h"

int LockCounter::increment()
{
    mtx.lock();
    int previous_count = counter++;
    mtx.unlock();
    return previous_count;
}

int LockCounter::get()
{
    mtx.lock();
    int current_count = counter;
    mtx.unlock();
    return current_count;
}
