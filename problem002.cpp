// Problem 2: Sum In Loop
#include <iostream>
#include <limits>
#include <sstream>

int main() {
    int size{ 0 };
    std::cin >> size;
    int* array = new int[size];

    std::string line;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin, line);
    std::stringstream input{ line };

    for (int i{ 0 }; i < size; ++i)     // fill array with input
        input >> array[i];

    int sum{ 0 };
    for (int i{ 0 }; i < size; ++i)     // sum array elements
        sum += array[i];

    std::cout << sum << '\n';
    delete [] array;

    return 0;
}