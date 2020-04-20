// Problem 17: Array Checksum
#include <iostream>
#include <sstream>

const int seed{ 113 };
const int limit{ 10000007 };

int main() {
    int length;
    std::cin >> length;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    //std::cout << std::numeric_limits<int>::max() << '\n';
    long result{ 0 };
    for (int i{ 0 }; i < length; ++i) {
        int val{};
        in >> val;
        result += val;
        result *= seed;
        if (result > limit)
            result %= limit;
    }

    std::cout << '\n' << result << '\n';

    return 0;
}