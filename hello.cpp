#include <iostream>
#include <string>
#include <vector>

// 1. Missing 'override' keyword
class Base
{
  public:
    virtual void process()
    {
    }
    virtual ~Base() = default;
};

class Derived : public Base
{
  public:
    void process()
    {
    } // Trigger: modernize-use-override
};

// 2. Passing expensive objects by value instead of const reference
void printData(std::string data)
{ // Trigger: performance-unnecessary-value-param
    // 3. Using std::endl instead of '\n'
    std::cout << data << std::endl; // Trigger: performance-avoid-endl
}

int main()
{
    // 4. Uninitialized variables
    int rawValue; // Trigger: cppcoreguidelines-init-variables

    // 5. Using NULL macro instead of nullptr
    int *ptr = NULL; // Trigger: modernize-use-nullptr

    // 6. Using older loop syntax instead of range-based for loops
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < numbers.size(); i++)
    { // Trigger: modernize-loop-convert
        rawValue = numbers[i];
    }

    printData("Finished processing");

    return 0;
}