#include "cas-counter.h"
#include "concurrent-counter.h"
#include "faa-counter.h"
#include "lock-counter.h"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int normal_counter;

void add_n(ConcurrentCounter *counter, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        counter->increment();
        ++normal_counter;
    }
}

int main(int, char **)
{
    ConcurrentCounter *counter = new FaaCounter();
    int n = 100000;
    thread t1(add_n, counter, n);
    thread t2(add_n, counter, n);
    t1.join();
    t2.join();
    cout << "Concurrent counter: " << counter->get() << "\nNormal counter: " << normal_counter << "\n";
    delete counter;
}
