#include <iostream>
#include <sstream>

int main() {
    int number_pairs{ 0 };
    std::cin >> number_pairs;

    std::stringstream result{};
    for (int i{ 0 }; i < number_pairs; ++i) {
        int a, b;
        std::cin >> a >> b;
        result << a + b << ' ';
    }

    std::cout << '\n';
    std::cout << result.str() << '\n';

    return 0;
}