// Copyright 2020 Magellan
#include <iostream>
#include <iterator>

int getInput() {
    int value{};
    while (true) {
        std::cout << "Enter a value to search: ";
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32600, '\n');
        } else {
            return (value);
        }
    }

    return (value);
}

int main() {
    constexpr int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int sizeOfArray{ static_cast<int>(std::size(array)) };

    std::cout << "Array:";
    for (int index = 0; index < sizeOfArray; ++index) {
        std::cout << " " << array[index];
    }
    std::cout << std::endl;

    int valueToSearch{ getInput() };
    std::cout << "You have entered: " << valueToSearch << std::endl;

    for (int index = 0; index < sizeOfArray; ++index) {
        if (valueToSearch == array[index]) {
            std::cout << "The index of the first matching number in the array is: " << index << std::endl;
            return (0);
        }
    }
    std::cout << "The number that you have entered did not match with anything in the array!" << std::endl;

    return (0);
}
