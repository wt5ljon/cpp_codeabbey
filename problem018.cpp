// Problem 18: Square Root
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
    int testcases{};
    std::cin >> testcases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int val, steps;
        std::cin >> val >> steps;

        double r{ 1 };
        for (int j{ 0 }; j < steps; ++j)
            r = (r + val/r)/2.0;

        out << std::fixed;
        out << std::setprecision(7);
        out << r << ' ';
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}