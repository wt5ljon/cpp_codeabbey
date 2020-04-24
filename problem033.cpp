// Problem 33: Parity Control
#include <iostream>
#include <sstream>

bool isValidParity(int ch) {
    int numBits{ 0 };
    for (int i{ 0 }; i < 8; ++i) {
        if (ch % 2 == 1)
            ++numBits;
        ch /= 2;
    }
    return (numBits % 2 == 0);
}

int main() {
    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    std::string out{""};
    while (true) {
        int input{};
        in >> input;
        if (isValidParity(input))
            out += static_cast<char>(input) & 0x7F;
        if (input == 46)
            break;
    }

    std::cout << '\n' << out << '\n';
}