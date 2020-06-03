// Copyright 2020 Magellan
#include <iostream>
#include <iterator>

void tempFuncWithRef(int (&refArray)[5]) {
    std::cout << "std::size of array in tempFuncWithRef: " << std::size(refArray) << std::endl;
    std::cout << "sizeof (refArray): " << sizeof (refArray) << std::endl << std::endl;
}

void tempFuncWithPtr(int *pArray) {
    // std::cout << "std::size of array in tempFuncWithPtr: " << std::size(pArray) << std::endl; // Compilation error.
    std::cout << "sizeof (pArray) in tempFuncWithPtr: " << sizeof (pArray) << std::endl;
}

void tempFuncWithArrayPtr(int *pArray[]) {
    // std::cout << "std::size of array in tempFuncWithPtr: " << std::size(pArray) << std::endl; // Compilation error.
    std::cout << "sizeof (pArray) in tempFuncWithArrayPtr: " << sizeof (pArray) << std::endl;
}

int main() {
    int array[]{ 1, 2, 3, 4, 5 };
    int array4[]{ 1, 2, 3, 4 };

    std::cout << "std::size of array in main: " << std::size(array) << std::endl;
    std::cout << "sizeof (array): " << sizeof (array) << std::endl << std::endl;
    tempFuncWithRef(array);
//    tempFuncWithRef(array4); // Compilation error.
    tempFuncWithPtr(array);
//     tempFuncWithArrayPtr(array); // Compilation error.

    return (0);
}
