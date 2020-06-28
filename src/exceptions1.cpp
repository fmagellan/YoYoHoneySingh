// Copyright 2020 Magellan
#include <iostream>

int main() {
    std::cout << "This is line-1" << std::endl;

    try {
        std::cout << "This is line-2" << std::endl;
        throw (1);
        std::cout << "This is line-3" << std::endl;
    }
    catch (unsigned int i) {
        std::cout << "Exception is thrown for int: " << i << std::endl;
    }
    catch (double i) {
        std::cout << "Exception is thrown for double: " << i << std::endl;
    }


    return (0);
}
