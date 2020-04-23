// Problem 29: Sort with Indexes
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

class Value {
private:
    int m_value{};
    int m_place{};
public:
    Value(int value, int place) :m_value{ value }, m_place{ place } {}
    int getPlace() { return m_place; }
    int getValue() { return m_value; }
};

bool mySort (Value* a, Value* b) { return (a->getValue() < b->getValue()); }

int main() {    
    int size{};
    std::cin >> size;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line {};
    getline(std::cin, line);
    std::istringstream in{ line };

    std::vector<Value*> vec{};
    // load the vector
    for (int i{ 0 }; i < size; ++i) {
        int val;
        in >> val;
        Value* valPtr = new Value(val, i+1);
        vec.push_back(valPtr);
    }

    // sort the vector of pointers
    std::sort(std::begin(vec), std::end(vec), mySort);

    for (auto& val: vec)
        std::cout << val->getPlace() << ' ';
    std::cout << '\n';

    // clean up memory
    for (auto& val: vec)
        delete val;

    return 0;
}