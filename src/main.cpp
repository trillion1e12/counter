#include "concurrent-counter.h"
#include "lock-counter.h"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

LockCounter lock_counter;
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
    int n = 100000;
    thread t1(add_n, &lock_counter, n);
    thread t2(add_n, &lock_counter, n);
    t1.join();
    t2.join();
    cout << "Lock counter: " << lock_counter.get() << "\nNormal counter: " << normal_counter << "\n";
}
