// Problem 5: Minimum of three - correct
#include <iostream>
#include <sstream>

int main() {
    int number_triplets{ 0 };
    std::cin >> number_triplets;

    std::stringstream result{};
    for (int i{ 0 }; i < number_triplets; ++i) {
        int a, b, c, minimum;
        std::cin >> a >> b >> c;
        minimum = a < b ? a : b;
        minimum = c < minimum ? c : minimum;
        result << minimum << ' ';
    }

    std::cout << '\n';
    std::cout << result.str() << '\n';

    return 0;
}