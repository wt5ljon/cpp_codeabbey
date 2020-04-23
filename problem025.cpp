// Problem 25: Linear Congruential Generator
#include <iostream>
#include <sstream>

int main() {
    int testcases{};
    std::cin >> testcases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int A, C, M, X, N;
        std::cin >> A >> C >> M >> X >> N;
        for (int j{ 0 }; j < N; ++j) {
            X = (A * X + C) % M; 
        }
        out << X << ' ';
    }

    std::cout << '\n' << out.str() << '\n';
    
    return 0;
}