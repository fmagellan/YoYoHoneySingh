// Copyright 2020 Magellan
#include "constants.h"

#include <iostream>

int main() {
    std::cout << "How many students are in your class?: ";
    int students{};
    std::cin >> students;

    if (students > constants::max_class_size)
        std::cout << "There are too many students in this class." << std::endl;
    else
        std::cout << "this class isn't too large." << std::endl;

    return (0);
}
