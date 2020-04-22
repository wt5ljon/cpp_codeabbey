// Problem 30: Reverse String
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string line{};
    getline(std::cin, line);

    std::reverse(std::begin(line), std::end(line));
    std::cout << '\n' << line << '\n';

    return 0;
}
