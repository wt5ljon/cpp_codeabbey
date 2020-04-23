// Problem 27: Bubble Sort
#include <iostream>
#include <sstream>

void swap(int& x, int&y) {
    int temp{ y };
    y = x;
    x = temp;
}

int main() {
    int size{};
    std::cin >> size;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    int* array = new int[size];

    // load array
    for (int i{ 0 }; i < size; ++i) {
        int val{};
        in >> val;
        array[i] = val;
    }

    // sort array
    int passes{ 0 };
    int swaps { 0 };
    while (true) {
        bool didSwap{ false };
        for (int i{ 0 }; i < size-1; ++i) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                ++swaps;
                didSwap = true;
            }
        }
        ++passes;
        if (!didSwap)
            break;
    }

    std::cout << '\n' << passes << ' ' << swaps << '\n';
    delete[] array;
    
    return 0;
}