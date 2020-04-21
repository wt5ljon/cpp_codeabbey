// Problem 19: Matching Brackets
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

const std::vector<char> left_bracket{ '<', '(', '[', '{' };
const std::vector<char> right_bracket{ '>', ')', ']', '}' };

bool matchBrackets(char left, char right) {
    if (left == '(' && right == ')')
        return true;
    if (left == '<' && right == '>')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

int main() {    
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::stack<char> bracket;
    std::ostringstream out{};
    for(int i{ 0 }; i < testcases; ++i) {
        bool match{ true };
        std::string line{};
        getline(std::cin, line);

        for (size_t j{ 0 }; j < line.length(); ++j) {
            // if left bracket, push onto the stack
            auto lresult = std::find(std::begin(left_bracket), std::end(left_bracket), line[j]);
            if (lresult != std::end(left_bracket))
                bracket.push(line[j]);

            // if right bracket, compare to top of stack (if stack not empty)
            auto rresult = std::find(std::begin(right_bracket), std::end(right_bracket), line[j]);
            if (rresult != std::end(right_bracket)) {
                if (!bracket.empty()) {
                    match = matchBrackets(bracket.top(), *rresult);
                    bracket.pop();
                } else {
                    match = false;
                }
            }

            if (!match)
                break;
        }

        // stack should be empty now -- empty stack if not empty
        if (!bracket.empty()) {
            match = false;
            while (!bracket.empty())
                bracket.pop();
        }

        out << (match ? '1' : '0') << ' ';
    }

    std::cout << '\n' << out.str() << '\n';
}