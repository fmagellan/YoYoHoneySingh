// Copyright 2020 Magellan
#include <iostream>

const int addDigits(const int number) {
    if (number <= 0) {
        return (0);
    }

    if (number < 10) {
        return (number);
    }

    return ((number % 10) + addDigits(number / 10));
}

int main() {
    int number{};
    std::cout << "Enter a number to sum it up: ";
    std::cin >> number;

    std::cout << "The sum of the digits is: " << addDigits(number) << std::endl;

    return (0);
}
