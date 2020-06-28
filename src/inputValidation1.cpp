// Copyright 2020 Magellan
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string name{};
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    bool isValidName{ true };

    for (std::size_t index{ 0 }; index < name.length(); ++index) {
        if (std::isalpha(name[index])) {
            continue;
        }

        if (name[index] == ' ') {
            continue;
        }

        isValidName = false;
        break;
    }

    if (isValidName) {
        std::cout << "The name is a valid one." << std::endl;
    } else {
        std::cout << "The name is an invalid one." << std::endl;
    }

    return (0);
}
