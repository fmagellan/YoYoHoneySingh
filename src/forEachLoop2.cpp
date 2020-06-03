// Copyright 2020 Magellan
#include <iostream>
#include <string_view>

int main() {
    std::string_view array[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::string nameToSearch{};
    std::cout << "Enter a name to search: ";
    std::cin >> nameToSearch;

    for (auto element: array) {
        if (nameToSearch == element) {
            std::cout << nameToSearch << " is found." << std::endl;
            return (0);
        }
    }

    std::cout << nameToSearch << " is not found. Come back tomorrow !" << std::endl;

    return (0);
}
