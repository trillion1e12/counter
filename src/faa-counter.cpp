#include "faa-counter.h"

void FaaCounter::increment()
{
    counter.fetch_add(1);
}

int FaaCounter::get()
{
    return counter.load();
}
