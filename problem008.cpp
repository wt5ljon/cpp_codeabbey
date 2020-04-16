// Problem 8: Arithmatic Progression
#include <iostream>
#include <sstream>

int main() {
    int testcases{ 0 };
    std::cin >> testcases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int start{};
        int step{};
        int values{};
        std::cin >> start >> step >> values;

        int sum{ 0 };
        for(int j{ 0 }; j < values; ++j) {
            sum += start;
            start += step;
        }
        out << sum << ' ';
    }

    std::cout << '\n';
    std::cout << out.str() << '\n';
}
