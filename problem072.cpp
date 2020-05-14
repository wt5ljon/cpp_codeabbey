// Problem 72: Funny Word Generator
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

const int A = 445;
const int C = 700001;
const int M = 2097152;

const char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h',
                            'j', 'k', 'l', 'm', 'n', 'p',
                            'r', 's', 't', 'v', 'w', 'x',
                            'z' };

const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

int getRandomVal(int& seed) {
    int xnext;

    xnext = (A*(seed) + C) % M;
    seed = xnext;

    return xnext;
}

int main() {
    int numberWords{};
    int seed{};
    std::cin >> numberWords >> seed;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };
    
    std::ofstream wordFile;
    wordFile.open("funnywords.txt", std::ios_base::out);

    std::ostringstream out{};
    int length{};
    if (wordFile.is_open()) {
        for(int i{ 0 }; i < numberWords; ++i) {
            in >> length;
            int randomVal{};
            char ch{};
            for(int j{ 0 }; j < length; j++) {
                randomVal = getRandomVal(seed);
                if(j%2 == 0)
                    ch = consonants[randomVal % 19];    // consonants
                else
                    ch = vowels[randomVal % 5];         // vowels
                out << ch;
                wordFile << ch;
            }
            out << ' ';
            wordFile << ' ';
        }
    } else {
        out << "open() failed...\n";
    }

    out << '\n';
    std::cout << out.str() << '\n';

    wordFile << '\n';
    wordFile.close();
    
    return 0;
}