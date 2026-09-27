#include "utils/math_utils.h"
#include <iostream>
#include <vector>

int main(int, char **)
{
    // Uninitialized variable
    int x;

    // Redundant initialization / modernize-style issues
    int *p = new int(42);

    // C-style cast
    double d = 3.14;
    int n = (int)d;

    // Prefer nullptr over NULL
    int *q = NULL;

    // Signed/unsigned comparison
    std::vector<int> values = {1, 2, 3};
    for (int i = 0; i < values.size(); ++i)
    {
        std::cout << values[i] << '\n';
    }

    // Possible null dereference
    if (q)
    {
        std::cout << *q << '\n';
    }

    // Memory leak
    std::cout << *p << '\n';

    // Unused variable
    int unused = 123;
    int *ptr = NULL;
    std::cout << add_func(6, 7) << "\n";
    std::cout << "Hello, from counterrrr!\n";
}
