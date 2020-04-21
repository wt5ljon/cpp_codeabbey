// Problem 20: Vowel Count
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

const std::vector<char> vec { 'a', 'e', 'i', 'o', 'u', 'y' };

int main() {
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        std::string line{};
        getline(std::cin, line);

        int count{ 0 };
        for (size_t j { 0 }; j < line.length(); ++j) {
            auto result = std::find(std::begin(vec), std::end(vec), line[j]);
            if (result != std::end(vec))
                ++count;
        }

        out << count << ' ';
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}