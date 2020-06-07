// Copyright 2020 Magellan
#include <iostream>

const int factorial(const int n) {
    if (n <= 1) {
        return (1);
    }

    return (n * factorial(n-1));
}

int main() {
    int number{};
    std::cout << "Enter a number to calculate factorial: ";
    std::cin >> number;

    std::cout << "The factorial of the number is: " << factorial(number) << std::endl;

    return (0);
}
