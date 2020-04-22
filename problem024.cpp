// Problem 24: Neumann's Random Generator
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    std::vector<int> vec{};
    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i)
    {
        int number{};
        in >> number;
        int loops{ 0 };
        while (true)
        {
            vec.push_back(number);
            number = number * number;
            number = (number / 100) % 10000;
            auto found = std::find(std::begin(vec), std::end(vec), number);
            ++loops;
            if (found != std::end(vec))
                break;
        }

        // print out answer and clear vector
        out << loops << ' ';
        vec.clear();
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}
