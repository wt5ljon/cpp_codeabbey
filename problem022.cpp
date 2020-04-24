// Problem 22: Two Printers
#include <iostream>
#include <sstream>

void swap(int& x, int& y) {
    int temp{ x };
    x = y;
    y = temp;
}

int main() {
    int testcases{};
    std::cin >> testcases;

    std::ostringstream out{};
    for(int i{ 0 }; i < testcases; ++i) {
        int p1, p2, pages;
        std::cin >> p1 >> p2 >> pages;

        if (p1 > p2)
            swap(p1, p2);

        int processed{ 1 };
        int elapsedP1{ p1 };
        int elapsedP2{ 0 };
        
        while (processed < pages) {
            if (elapsedP1 + p1 <= elapsedP2 + p2) {
                elapsedP1 += p1;
                ++processed;
                continue;
            }
            elapsedP2 += p2;
            ++processed;
        }

        out << (elapsedP1 > elapsedP2 ? elapsedP1 : elapsedP2) << ' '; 
    }

    std::cout << '\n' << out.str() << '\n';
}