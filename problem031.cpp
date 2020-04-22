// Problem 31: Rotate String
#include <iostream>
#include <sstream>

int main()
{
    int testcases{};
    std::cin >> testcases;

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i)
    {
        int dir{};
        std::string str{};
        std::cin >> dir >> str;
        if (dir >= 0) {
            for (int j{ 0 }; j < dir; ++j)
            {
                char temp{ str[0] };
                for (size_t k{ 0 }; k < str.length() - 1; ++k)
                    str[k] = str[k + 1];
                str[str.length() - 1] = temp;
            }  
        } else {
            for (int j{ 0 }; j < -dir; ++j)
            {
                char temp{ str[str.length() - 1] };
                for (size_t k{ str.length() - 1 }; k > 0; --k)
                    str[k] = str[k - 1];
                str[0] = temp;
            }  
        }

        out << str << ' ';
    }

    std::cout << '\n' << out.str() << '\n';
    return 0;
}
