// Problem 28: Body Mass Index
#include <iostream>
#include <sstream>

int main() {
    int testcases{};
    std::cin >> testcases;
    
    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        double weight;
        double height;
        std::cin >> weight >> height;
        double BMI{ weight / ( height * height) };

        if (BMI < 18.5)
            out << "under ";
        else if (BMI >= 18.5 && BMI < 25.0)
            out << "normal ";
        else if (BMI >= 25.0 && BMI < 30.0)
            out << "over ";
        else 
            out << "obese ";
    }

    std::cout << '\n' << out.str() << '\n';

    return 0;
}