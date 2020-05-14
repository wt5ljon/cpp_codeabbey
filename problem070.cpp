// Problem 70: Most Frequent Word
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "funnywordgenerator.h"

const int NUMBERWORDS = 900000;
const int WORDLENGTH = 6;
const std::string WORDFILE = "funnywords.txt";

bool generateFunnyWordFile(const std::string& filename, int seed) {
    std::ofstream wordFile;
    wordFile.open(filename, std::ios_base::out);
    if (wordFile.is_open()) {
        std::string word{};
        for (int i{ 0 }; i < NUMBERWORDS; ++i) {
            word = generateFunnyWord(seed, WORDLENGTH);
            wordFile << word << '\n';
        }
        wordFile.close();
        return true;
    }
    else
        return false;
}

int main() {
    int seed{};
    std::cin >> seed;

    // generate file of random funny words
    generateFunnyWordFile(WORDFILE, seed);

    std::ifstream wordFile;
    wordFile.open(WORDFILE, std::ios_base::out);

    std::map<std::string, int> funnyWordMap;
    std::string funnyword{};

    int maxWordCount{ 0 };
    std::string maxWord{};    
    while(wordFile >> funnyword) {
        auto pairFound = funnyWordMap.find(funnyword);
        if (pairFound == funnyWordMap.end())
            funnyWordMap[funnyword] = 1;
        else {
            pairFound->second++;
            if (pairFound->second > maxWordCount) {
                maxWordCount = pairFound->second;
                maxWord = pairFound->first;
            }
        }
    }

    std::cout << '\n' << maxWord << '\n';

    return 0;
}