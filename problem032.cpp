// Problem 32: Josephus Problem
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int size, step;
    std::cin >> size >> step;

    // load array with soldiers
    int* soldiers = new int[size];
    for (int i{ 0 }; i < size; ++i)
        soldiers[i] = i + 1;
    
    int index{ 0 };
    int remaining{ size };
    int count{ 1 };
    while (remaining > 1) {
        if (soldiers[index] == -1) {
            if (++index == size)
                index = 0;
            continue;
        }
        if (count == step) {
            soldiers[index++] = -1;
            count = 1;
            --remaining;
        } else {
            ++count;
            ++index;
        }
        if (index == size)
            index = 0;
    }

    // find remaining soldier
    for (int i{ 0 }; i < size; ++i) {
        if (soldiers[i] != -1) {
            std::cout << soldiers[i] << '\n';
            break;
        }
    }

    // clean up memory
    delete[] soldiers;

    return 0;    
}