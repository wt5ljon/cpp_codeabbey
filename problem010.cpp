// Problem 10: Linear Function
#include <iostream>
#include <sstream>

int main() {
    int cases{};
    std::cin >> cases;

    std::ostringstream out{};
    for (int i{ 0 }; i < cases; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int a { (y2 - y1)/(x2 -x1) };
        int b { y1 - (a * x1) };

        out << '(' << a << ' ' << b << ") "; 
    }

    std::cout << '\n';
    std::cout << out.str() << '\n';

    return 0;
}