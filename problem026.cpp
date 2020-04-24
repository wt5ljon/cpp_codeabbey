// Problem 26: Greatest Common Divisor
#include <iostream>
#include <sstream>

int gcdCalc(int a, int b) {
    while (true) {
        if (a > b) {
            a = a % b;
            if (a == 0)
                return b;
        } else {
            b = b % a;
            if (b == 0)
                return a;
        }
    }
}

int lcmCalc(int a, int b, int gcd) {
    return (a * b) / gcd;
}

int main() {
    int testcases{};
    std::cin >> testcases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int a, b;
        std::cin >> a >> b;

        int gcd{ gcdCalc(a, b) };
        int lcm{ lcmCalc(a, b, gcd) };

        out << '(' << gcd << ' ' << lcm << ") ";
    }

    std::cout << '\n' << out.str() << '\n';
    return 0;
}