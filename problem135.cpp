// Problem 135: Variable Length Code
#include <iostream>
#include <iomanip>
#include <map>

typedef std::map<char, std::string> MAP;

void loadMap(MAP& code) {
    code[' '] = "11";
    code['e'] = "101";
    code['t'] = "1001";
    code['o'] = "10001";
    code['n'] = "10000";
    code['a'] = "011";
    code['s'] = "0101";
    code['i'] = "01001";
    code['r'] = "01000";          
    code['h'] = "0011";
    code['d'] = "00101";          
    code['l'] = "001001";
    code['!'] = "001000";         
    code['u'] = "00011";
    code['c'] = "000101";         
    code['f'] = "000100";
    code['m'] = "000011";         
    code['p'] = "0000101";
    code['g'] = "0000100";        
    code['w'] = "0000011";
    code['b'] = "0000010";        
    code['y'] = "0000001";
    code['v'] = "00000001";       
    code['j'] = "000000001";
    code['k'] = "0000000001";     
    code['x'] = "00000000001";
    code['q'] = "000000000001";  
    code['z'] = "000000000000";
}

int main() {
    std::string line{};
    getline(std::cin, line);
    MAP codemap;
    loadMap(codemap);

    // calculate size of output
    int size{ 0 };
    for (const auto &ch: line)
        size += codemap[ch].size();
    int arraySize{ size/8 + 1 };
    int* result = new int[arraySize]();
    int* resultPtr = result;

    int bitPosition{ 128 };
    for (const auto &ch: line) {
        std::string code = codemap[ch];
        
        for (const auto &bit: code) {
            if (bit == '1')
                *resultPtr += bitPosition;
            bitPosition /= 2;
            if (bitPosition == 0) {
                ++resultPtr;
                bitPosition = 128;
            }
        }
    }

    for (int i{ 0 }; i < arraySize; ++i)
        std::cout << std::setfill('0') << std::setw(2) << std::hex << result[i]  << ' ';

    std::cout << '\n';

    delete[] result;
    return 0;
}