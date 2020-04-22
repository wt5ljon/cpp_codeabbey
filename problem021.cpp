// Problem 21: Array Counters
#include <iostream>
#include <sstream>

int main() {
    int length{};
    int range{};
    std::cin >> length >> range;

    // ignore trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    int* countArray{ new int[range]{ 0 } };
    std::ostringstream out{};
    for (int i{ 0 }; i < length; ++i) {
        int val{};
        in >> val;
        ++countArray[val - 1];
    }

    for (int i{ 0 }; i < range; ++i)
        out << countArray[i] << ' ';

    std::cout << '\n' << out.str() << '\n';

    delete [] countArray;   
    
    return 0;
}