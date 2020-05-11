// Problem 36: Code Guesser
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

struct Guess {
    std::string value{};
    int numberRight{};
};

int numberMatches(const std::string& guess, const std::string& answer, int length) {
    int matches{ 0 };
    for (int i{ 0 }; i < length; ++i) {
        if (guess[i] == answer[i])
            ++matches;
    }
    return matches;
}

bool isXXX(std::string s) {
    return s == "xxx";
}

std::string to_zero_lead(const int value, int width) {
     std::ostringstream oss;
     oss << std::setw(width) << std::setfill('0') << value;
     return oss.str();
}

int  main() {
    // get number of guesses
    int numberGuesses{};
    std::cin >> numberGuesses;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // get guesses
    std::vector<Guess> Guesses; 
    for (int i{ 0 }; i < numberGuesses; ++i) {
        std::string val{};
        int right{};
        std::cin >> val >> right;
        Guesses.push_back(Guess{ val, right });
    }

    // calc number of columns
    int columns = static_cast<int>(Guesses[0].value.size());

    // generate vector for all possible answers
    std::vector<std::string> answers;
    std::ostringstream ss;
    for (int i{ 0 }; i < std::pow(10,columns); ++i)
        answers.push_back(to_zero_lead(i, columns));

    // cycle through and process guesses
    // eliminate entries for the set of all possible answers
    for (auto guess: Guesses) {
        for (auto it = answers.begin(); it != answers.end(); ++it) {       
            int matches{};
            matches = numberMatches(guess.value, *it, columns);
            if (matches != guess.numberRight)
                *it = "xxx";
        }
        answers.erase(std::remove_if(answers.begin(), answers.end(), isXXX), answers.end());
    }

    // print out the answer - one answer left
    std::cout << '\n' << answers[0] << '\n';

    return 0;
}