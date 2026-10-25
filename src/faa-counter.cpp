#include "faa-counter.h"

int FaaCounter::increment()
{
    return counter.fetch_add(1);
}

int FaaCounter::get()
{
    return counter.load();
}

void FaaCounter::reset()
{
    counter.store(0);
}
