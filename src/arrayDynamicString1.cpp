// Copyright 2020 Magellan
#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::cout << "How many names would you like to enter? ";

    int numberOfNames{};
    std::cin >> numberOfNames;

    // Input the names.
    std::string *pNames{ new std::string[numberOfNames]{} };
    for (int indexNames{ 0 }; indexNames < numberOfNames; ++indexNames) {
        std::cout << "Enter name #" << indexNames + 1 << " ";
        std::cin >> pNames[indexNames];
    }

    // Sort the names.
    for (int outerIndex{ 0 }; outerIndex < numberOfNames - 1; ++outerIndex) {
        for (int innerIndex { 0 }; innerIndex < numberOfNames - outerIndex - 1; ++innerIndex) {
            if (pNames[innerIndex] > pNames[innerIndex + 1]) {
                std::swap(pNames[innerIndex], pNames[innerIndex + 1]);
            }
        }
    }


    // Output the sorted-names.
    std::cout << "You have entered: " << std::endl;
    for (int indexNames{ 0 }; indexNames < numberOfNames; ++indexNames) {
        std::cout << pNames[indexNames] << std::endl;
    }

    return (0);
}
