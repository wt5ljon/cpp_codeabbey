// Problem 60: Sweet Harvest
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

std::string toJumpBinary(int value, int width) {
    std::ostringstream oss;
    std::string r;
    while(value!=0) {r=(value%2==0 ?"2":"3")+r; value/=2;}
    oss << std::setw(width) << std::setfill('2') << r;
    return oss.str();
}

int main() {
    // get number of testcases
    int testcases{};
    std::cin >> testcases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ostringstream out{};
    std::vector<int> Candy;
    std::vector<std::string> jumpTable;
    for (int i{ 0 }; i < testcases; ++i) {
        int stones{ 0 };
        std::string line{};
        getline(std::cin, line);
        std::istringstream in{ line };
        int candyCount{};
        while (in >> candyCount) {
            Candy.push_back(candyCount);
            ++stones;
        }
        int width{ (stones-1)/2 };

        // build the jump table
        for (int j{ 0 }; j < std::pow(2,width); ++j)
            jumpTable.push_back(toJumpBinary(j, width));

        // check candy count for all possible paths
        int maxCount{ 0 };
        for (const std::string& jump: jumpTable) {
            int stone{ 0 };
            int count{ Candy[0] };
            for (auto& ch: jump) {
                if (ch == '2')
                    stone += 2;
                else
                    stone += 3;
                
                if (stone < stones)
                    count += Candy[stone];
            }
            if (count > maxCount)
                maxCount = count;
        }
        out << maxCount << ' ';
        maxCount = 0;
        Candy.clear();
        jumpTable.clear();
    }
 
    std::cout << '\n' << out.str() << '\n';
    return 0;
}