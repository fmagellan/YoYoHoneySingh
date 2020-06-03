// Copyright 2020 Magellan
#include <iostream>

int main() {
    int intArray[]{ 0, 1, 2, 13, 4, 5};
    char charArray[]{"array"};
    char c{ 'D' };
    char *p{ &c };

    std::cout << intArray << std::endl;
    std::cout << charArray << std::endl;
    std::cout << &c << std::endl;
//    std::cout << p << std::endl;

    return (0);
}
