#include "cas-counter.h"

void CasCounter::increment()
{
    int oldval = counter.load();
    int newval = oldval + 1;
    while (!counter.compare_exchange_strong(oldval, newval))
    {
        newval = oldval + 1;
    }
}

int CasCounter::get()
{
    return counter.load();
}
