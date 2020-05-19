// Problem 54: Pythagorean Triplets
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int main() {
    int testcases{};
    std::cin >> testcases;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int sum{};
        std::cin >> sum;

        int n{ 1 };
        long c{};
        bool found{ false };
        while (!found) {
            int m{ n + 1 };
            while (true) {
                int s{ m*m + m*n };
                if ( s == sum / 2 ) {
                    // a = (m*m) - (n*n);
                    // b = 2 * m * n;
                    c = (m*m) + (n*n);
                    found = true;
                    break; 
                } else if (s > sum / 2) {
                    ++n;
                    break;
                } else {
                    ++m;
                }
            }
        }
        out << c*c << ' ';
    }

    std::cout << out.str() << '\n';
    return 0;
}