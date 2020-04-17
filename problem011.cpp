// Problem 11: Sum of Digits
#include <iostream>
#include <sstream>

int main() {
    int cases{};
    std::cin >> cases;

    std::ostringstream out{};
    for (int i{ 0 }; i < cases; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int val{ a * b + c };
        int sumOfDigits{ 0 };
        while (val != 0) {
            sumOfDigits += val % 10;
            val /= 10;
        }
        
        out << sumOfDigits << ' ';
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}