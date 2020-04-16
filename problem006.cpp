// Problem 6: Rounding
#include <iostream>
#include <sstream>

int main() {
    int testCases{ 0 };
    std::cin >> testCases;
    
    std::stringstream result {};
    for (int i{ 0 }; i < testCases; ++i) {
        int a, b;
        std::cin >> a >> b;
        int answer { a / b };
        int remain { a % b};

        if(remain < 0)
            remain = -remain;
        if(b < 0)
            b = -b;
        if(answer >= 0) { 
            if (remain * 2 >= b)
                ++answer;
        }
        else {
            if (remain * 2 >= b)
                --answer;
        }
        result << answer << ' ';
    }

    std::cout << '\n';
    std::cout << result.str() << '\n';

    return 0;
}