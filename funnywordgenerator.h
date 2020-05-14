#ifndef FUNNY_WORD_GENERATOR_H
#define FUNNY_WORD_GENERATOR_H

#include <string>
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

std::string generateFunnyWord(int& seed, int length) {
    char ch{};
    int randomVal{};
    std::string word{};
    std::ostringstream out{};
    for(int j{ 0 }; j < length; j++) {
        randomVal = getRandomVal(seed);
        if(j%2 == 0)
            ch = consonants[randomVal % 19];    // consonants
        else
            ch = vowels[randomVal % 5];         // vowels
        out << ch;
    }
    return out.str();
}

#endif