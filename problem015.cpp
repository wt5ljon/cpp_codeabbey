// Problem 15: Maximum of Array
#include <iostream>
#include <limits>
#include <sstream>

int main() {
    const int size{ 300 };
    int array[300];

    // get 300 numbers
    std::string input{};
    getline(std::cin, input);
    std::stringstream values{ input };

    // load array
    for (int i{ 0 }; i < size; ++i)
        values >> array[i];

    int maximum{ std::numeric_limits<int>::min() };
    int minimum{ std::numeric_limits<int>::max() };
    // find maximum & minimum
    for (int i{ 0 }; i < size; ++i) {
        maximum = array[i] > maximum ? array[i] : maximum;
        minimum = array[i] < minimum ? array[i] : minimum;
    }

    std::cout << '\n';
    std::cout << maximum << ' ' << minimum << '\n';

    return 0;
}