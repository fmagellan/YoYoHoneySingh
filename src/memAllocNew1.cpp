// Copyright 2020 Magellan
#include <iostream>

int main() {
    int *pInt{ new (std::nothrow) int{8} };

    if (!pInt) {
        std::cout << "No memory is allocated" << std::endl;
        return (1);
    }

    std::cout << *pInt << std::endl;
    delete pInt;
    pInt = nullptr;
    delete pInt;

    return (0);
}
