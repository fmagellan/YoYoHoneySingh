// Copyright 2020 Magellan
#include <iostream>

int main() {
    int i{ 5 };
    int *ptr;

    if (ptr) {
        std::cout << "Ptr is not NULL." << std::endl;
    } else {
        std::cout << "Ptr is NULL." << std::endl;
    }

    return (0);
}
