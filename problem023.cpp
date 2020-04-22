// Problem 23 - Bubble in Array

#include <iostream>
#include <sstream>

void swap(int& x, int& y)
{
    int temp{ x };
    x = y;
    y = temp;
}

long checksum(int* const array, int size)
{
    const int seed{ 113 };
    const int limit{ 10000007 };

    long result{ 0 };
    for (int i{ 0 }; i < size; ++i) {
        result += array[i];
        result *= seed;
        if (result > limit)
            result %= limit;
    }

    return result;
}


int main()
{
    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };

    int* array = new int[100];

    // load array
    int index{ 0 };
    while (true)
    {
        int val{};
        in >> val;
        if (val == -1 || index >= 100)
            break;
        array[index++] = val;
    }

    // check for swaps
    int size{ index };
    int number_swaps{ 0 };
    for (int i{ 0 }; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            swap(array[i], array[i + 1]);
            ++number_swaps;
        }
    }

    std::cout << '\n' << number_swaps << ' ' << checksum(array, size) << '\n';

    return 0;
}
