// Problem 13: Weighted Sum of Digits
#include <iostream>
#include <sstream>

int main() {
    int cases{};
    std::cin >> cases;
    
    std::string line;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin, line);
    std::istringstream in{ line };

    std::ostringstream out{};

    for (int i{ 0 }; i < cases; ++i) {    
        std::string number;
        in >> number;
        const char* ptr { number.c_str() };
        
        int sum{ 0 };
        for (size_t j{ 0 }, count{ 1 }; j < number.length(); ++j, ++count) {
            sum += (*ptr - '0') * count;
            ++ptr;
        }

        out << sum << ' ';
    }      

    std::cout << '\n' << out.str() << '\n';

    return 0;
}