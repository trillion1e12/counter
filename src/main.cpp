#include "cas-counter.h"
#include "concurrent-counter.h"
#include "faa-counter.h"
#include "lock-counter.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int normal_counter = 0;

void add_n(ConcurrentCounter *counter, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        // int val =
        counter->increment();
        // if (i == n - 1)
        // {
        //     cout << "Thread: " << val << "\n";
        // }
        // ++normal_counter;
    }
}

void test_counter(ConcurrentCounter *counter, int num_threads, int n)
{
    vector<thread> threads;
    for (size_t i = 0; i < num_threads; i++)
    {
        threads.push_back(thread(add_n, counter, n));
    }
    for (thread &t : threads)
    {
        t.join();
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: ./build/counter <num_threads> <n>\n"
                "* num_threads: Number of threads\n"
                "* n: The number of times each thread increments the counter\n"
                "Example: ./build/counter 5 100000\n";
        return EXIT_FAILURE;
    }

    int num_threads = stoi(argv[1]);
    int n = stoi(argv[2]);
    ConcurrentCounter *counters[] = {new LockCounter(), new CasCounter(), new FaaCounter()};
    for (ConcurrentCounter *counter : counters)
    {
        auto start = chrono::high_resolution_clock::now();
        test_counter(counter, num_threads, n);
        auto end = chrono::high_resolution_clock::now();
        cout << "Concurrent counter: " << counter->get() << "\nNormal counter: " << normal_counter << "\n";
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Time took: " << duration.count() / 1000.0f << "ms\n\n";
        normal_counter = 0;
    }
    for (ConcurrentCounter *counter : counters)
    {
        delete counter;
    }
}
