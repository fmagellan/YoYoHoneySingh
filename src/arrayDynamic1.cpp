// Copyright 2020 Magellan
#include <iostream>

int main() {
    constexpr int array_size{ 4 };
    int *pArray{new int[4]{1, 2, 3, 4}};
    std::cout << "pArray: " << pArray << std::endl;
    for (int arrayIndex = 0; arrayIndex < array_size; ++arrayIndex) {
        std::cout << pArray[arrayIndex] << " ";
    }
    delete[] pArray;
    std::cout << std::endl;

    int array[]{1, 2, 3, 4};
    std::cout << array << std::endl;
    for (int arrayIndex = 0; arrayIndex < array_size; ++arrayIndex) {
        std::cout << array[arrayIndex] << " ";
    }
    std::cout << std::endl;

//   char *pCharArray{ new char[10]{ "Yo bro" } }; Doesnt work. compiler bug.
    char charArray[]{ "Yo bro" };
    std::cout << "charArray: " << charArray << std::endl;
    char *pCharArray{ new char[10]{ 'Y', 'o', ' ', 'b', 'r', 'o' } };
    std::cout << "pCharArray: " << pCharArray << std::endl;

    return (0);
}
