// Problem 16: Average of an Array
#include <iostream>
#include <sstream>

// produces a rounded up int resulting from x/y
int rounder(int x, int y) {
    int answer { x / y };
    int remain { x % y};

    if(remain < 0)
        remain = -remain;
    if(y < 0)
        y = -y;
    if(answer >= 0) { 
        if (remain * 2 >= y)
            ++answer;
    }
    else {
        if (remain * 2 >= y)
            --answer;
    }

    return answer;
}

int main() {
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        std::string line{};
        getline(std::cin, line);
        std::istringstream in{ line };

        int sum{ 0 };
        int count{ 0 };
        while (true) {
            int val{};
            in >> val;
            if (val == 0)
                break;
            sum += val;
            ++count;
        }
        out << rounder(sum, count) << ' ';       
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}