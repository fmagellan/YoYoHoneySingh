// Copyright 2020 Magellan
#include <iostream>

void printBinary(const unsigned int number) {
    if (number < 2) {
        std::cout << number;
        return;
    }

    std::cout << (number % 2);
    printBinary(number / 2);

    return;
}

int main() {
    int number{};
    std::cout << "Enter a positive number to convert to its binary: ";
    std::cin >> number;

    std::cout << "The binary representation is: ";
    printBinary(number);

    std::cout << std::endl;
    return (0);
}
