// Copyright 2020 Magellan
#include <iostream>
#include <iterator>

int main() {
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int sizeOfArray = static_cast<int>(std::size(array));

    // Printing before sorting.
    std::cout << "Array before sorting:";
    for (int index = 0; index < sizeOfArray; ++index) {
        std::cout << " " << array[index];
    }
    std::cout << std::endl;

    // Sorting
    for (int outerIndex = 0; outerIndex < sizeOfArray - 1; ++outerIndex) {
        bool isSwapDoneInThisIteration{false};
        for (int innerIndex = 0; innerIndex < sizeOfArray - outerIndex; ++innerIndex) {
            if (array[innerIndex] > array[innerIndex + 1]) {
                std::swap(array[innerIndex], array[innerIndex + 1]);
                isSwapDoneInThisIteration = true;
            }
        }

        if (!isSwapDoneInThisIteration) {
            // All items in the sorting order already. No need to do anything further.
            std::cout << "Breaking out when outerIndex is " << outerIndex << std::endl;
            break;
        }
    }

    // Printing after sorting.
    std::cout << "Array after sorting:";
    for (int index = 0; index < sizeOfArray; ++index) {
        std::cout << " " << array[index];
    }
    std::cout << std::endl;

    return (0);
}
