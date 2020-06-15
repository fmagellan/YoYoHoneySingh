// Copyright 2020 Magellan
#include <iostream>

int getInputNumber() {
    int num{};
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32000, '\n');
        } else {
            std::cin.ignore(32000, '\n');
            break;
        }

        std::cout << "Invalid number, Try again." << std::endl;
    }

    return (num);
}

int gcd(int x, int y) {
    if (x < y) {
        std::swap(x, y);
    }

    int remainder = (x % y);
    if (remainder == 0) {
        return (y);
    }

    return (gcd(y, remainder));
}

int main() {
    int x{ getInputNumber() };
    int y{ getInputNumber() };
    std::cout << "X: " << x << ", Y: " << y << std::endl;

    int gcdNumber{ gcd(x, y) };
    std::cout << "GCD: " << gcdNumber << std::endl;

    return (0);
}
