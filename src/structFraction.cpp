// Copyright 2020 Magellan
#include <iostream>
#include <string>

struct FractionalNumber {
    int numerator;
    int denominator;
    double value;
};

FractionalNumber getInputFractionalNumber() {
    FractionalNumber number;
    std::cout << "Enter the numerator: ";
    std::cin >> number.numerator;
    std::cout << "Enter the denominator: ";
    std::cin >> number.denominator;

    if (number.denominator != 0) {
        number.value = (static_cast<double>(number.numerator))/number.denominator;
    }

    return (number);
}

int main() {
    FractionalNumber firstNumber{ getInputFractionalNumber() };
    if (firstNumber.denominator == 0) {
        std::cout << "Invalid value for denominator. Come back tomorrow." << std::endl;
        return (-1);
    }

    FractionalNumber secondNumber{ getInputFractionalNumber() };
    if (secondNumber.denominator == 0) {
        std::cout << "Invalid value for denominator. Come back tomorrow." << std::endl;
        return (-1);
    }

    std::cout << "firstNumber * secondNumber = " << firstNumber.value * secondNumber.value << std::endl;

    return (0);
}
