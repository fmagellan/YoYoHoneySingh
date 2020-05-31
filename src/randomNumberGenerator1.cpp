// Copyright 2020 Magellan
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(4);

    for (int index = 1; index <= 100; index++) {
        std::cout << std::rand() << " ";
        if (index % 10 == 0) {
            std::cout << std::endl;
        }
    }

    return (0);
}
