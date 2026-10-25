#include "cas-counter.h"
#include "concurrent-counter.h"
#include "faa-counter.h"
#include "lock-counter.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <typeinfo>
#include <vector>

using namespace std;

int normal_counter = 0;

void add_n(ConcurrentCounter *counter, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        counter->increment();
    }
}

void test_counter(ConcurrentCounter *counter, int num_threads, int N)
{
    int n = N / num_threads;
    vector<thread> threads;

    for (size_t i = 0; i < num_threads; i++)
    {
        if (i == num_threads - 1)
        {
            threads.push_back(thread(add_n, counter, N - (num_threads - 1) * n));
        }
        else
        {
            threads.push_back(thread(add_n, counter, n));
        }
    }

    for (thread &t : threads)
    {
        t.join();
    }
}

int main(int argc, char **argv)
{
    int N = 100'000'000;
    int num_threads_list[] = {1, 2, 4, 8, 16};
    ConcurrentCounter *counters[] = {new LockCounter(), new CasCounter(), new FaaCounter()};
    vector<string> counter_names = {"LockCounter", "CasCounter", "FaaCounter"};

    for (int num_threads : num_threads_list)
    {
        cout << num_threads << " threads:\n";
        for (size_t i = 0; i < counter_names.size(); i++)
        {
            ConcurrentCounter *counter = counters[i];
            counter->reset();

            auto start = chrono::high_resolution_clock::now();
            test_counter(counter, num_threads, N);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

            cout << counter_names[i] << " result: " << counter->get() << "\n";
            cout << "Time took: " << duration.count() / 1000.0f << "ms\n\n";
        }
    }

    for (ConcurrentCounter *counter : counters)
    {
        delete counter;
    }
}
