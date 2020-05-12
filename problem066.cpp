// Problem 66: Caesar Cipher Cracker
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct BestDecode {
    int key{ 0 };
    int numberDecodes{ 0 };
};

// returns true if word found in local linux dictionary
bool isWord(const std::string& search) {
    std::ifstream wordFile;
    bool found{ false };
    wordFile.open("/usr/share/dict/american-english", std::ios_base::in);
    if (wordFile.is_open()) {
        std::string line{};
        while (wordFile.good()) {
            getline(wordFile,line);
            if (line == search) {
                found = true;
                break;
            }
        }
        wordFile.close();
    }
    else
        std::cout << "Failed to open word file\n";
    return found;
}

// perform Caesar Decipher
void decipher(int key, const std::vector<std::string>& omsg, std::vector<std::string>& dmsg) {
    for (const auto& word : omsg) {
        std::string newWord{ word };
        int index{ 0 };
        for (const auto& letter : word) {
            int ch{ static_cast<int>(letter) };
            ch += 32; // convert to lowercase for file comparison
            ch -= key;
            if (ch < 97)
                ch += 26;
            newWord[index++] = static_cast<char>(ch);
        }
        dmsg.push_back(newWord);
    }
}

int main() {
    // get number of testcases
    int testcases{};
    std::cin >> testcases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ostringstream out{};
    std::vector<std::string> orig_msg;
    std::vector<std::string> decode_msg;
    BestDecode best{};
    for (int i{ 0 }; i < testcases; ++i) {
        std::string line{};
        std::string word{};
        getline(std::cin, line);
        std::istringstream in{ line };
        int msgLength{ 0 };
        // read in each message
        while(in >> word) {
            orig_msg.push_back(word);
            ++msgLength;
        }
        int numberDecodedWords{ 0 };
        for (int key{ 1 }; key <= 25; ++key) {
            decipher(key, orig_msg, decode_msg);
            for (int j{ 0 }; j < msgLength; ++j) {
                if (isWord(decode_msg[j]))
                    ++numberDecodedWords;
            }
            if (numberDecodedWords > best.numberDecodes) {
                best.key = key;
                best.numberDecodes = numberDecodedWords;
            }
            decode_msg.clear();
            numberDecodedWords = 0;
        }

        decipher(best.key, orig_msg, decode_msg);
        // print out first three words of the message then key used
        for (int index{ 0 }; index < 3; ++index) {
            std::string wd{ decode_msg[index] };
            // convert answer back to uppercase
            std::for_each(wd.begin(), wd.end(), [](char& c){
	            c = ::toupper(c);
            });
            out << wd << ' ';
        }
        out << best.key << ' ';

        orig_msg.clear();
        decode_msg.clear();
        best.key = 0;
        best.numberDecodes = 0;
    }

    std::cout << '\n' << out.str() << '\n';
    
    return 0;
}