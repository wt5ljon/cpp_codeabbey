// Problem 92: Binary Heap
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

void swap(int* heap, int index) {
    int childIndex{ index };
    int parentIndex{};
    parentIndex = std::floor((childIndex - 1) / 2);
    int temp{};
    if (childIndex == 0 || heap[parentIndex] < heap[childIndex])
        return;
    temp = heap[parentIndex];
    heap[parentIndex] =  heap[childIndex];
    heap[childIndex] = temp;
    swap(heap, parentIndex);
}

void checkBinaryHeap(int* heap, int index, int size) {
    int child1Index{ 2 * index + 1 };
    int child2Index{ 2 * index + 2 };
    int leastChildIndex{};
    if (child1Index >= size && child2Index >= size)
        return;
    if (child1Index < size && child2Index < size) 
        leastChildIndex = heap[child1Index] < heap[child2Index] ? child1Index : child2Index;
    else 
        leastChildIndex = child1Index;
    if (heap[leastChildIndex] < heap[index]) {
        int temp{ heap[index] };
        heap[index] = heap[leastChildIndex];
        heap[leastChildIndex] = temp;
    }
    checkBinaryHeap(heap, leastChildIndex, size);
}

int main() {
    int commands{};
    std::cin >> commands;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line{};
    getline(std::cin, line);
    std::istringstream in{ line };
    std::ostringstream out{};

    int binaryHeap[50]{ 0 };
    int currentIndex{ 0 };
    int parentIndex{ 0 };
    int size = 0;
    for (int i{ 0 }; i < commands; ++i) {
        int value{};
        in >> value;
        if (value != 0) {
            // insert into heap
            binaryHeap[currentIndex] = value;
            parentIndex = std::floor((currentIndex - 1) / 2);
            if (parentIndex >= 0 && binaryHeap[parentIndex] > value)
                swap(binaryHeap, currentIndex);
            ++size;
            ++currentIndex;
        } else {
            // delete from heap
            --currentIndex;
            --size;
            binaryHeap[0] = binaryHeap[currentIndex];
            binaryHeap[currentIndex] = 0;
            checkBinaryHeap(binaryHeap, 0, size);
        }
    }

    for (int index{ 0 }; index < size; ++index)
        out << binaryHeap[index] << ' ';

    std::cout << out.str() << '\n';

    return 0;
}