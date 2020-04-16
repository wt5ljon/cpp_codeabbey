// Problem 7: Fahrenheit to Celsius
#include <iostream>
#include <sstream>

// produces a rounded up int resulting from x/y
int rounder(int x, int y) {
    int answer { x / y };
    int remain { x % y};

    if(remain < 0)
        remain = -remain;
    if(y < 0)
        y = -y;
    if(answer >= 0) { 
        if (remain * 2 >= y)
            ++answer;
    }
    else {
        if (remain * 2 >= y)
            --answer;
    }

    return answer;
}

int main() {
    std::string line{};
    getline(std::cin, line);

    std::istringstream in{ line };
    int testCases{ 0 };
    in >> testCases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testCases; ++i) {
        int f;
        in >> f;
        out << rounder((f - 32) * 5, 9) << ' ';
    }

    std::cout << '\n';
    std::cout << out.str() << '\n';

    return 0;
}