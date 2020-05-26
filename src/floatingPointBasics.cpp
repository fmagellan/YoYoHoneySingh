// Copyright 2020 Magellan
#include <iostream>

int main() {
    std::cout << 1.2345678f << std::endl;
    std::cout << 123456.1f << std::endl;

    float posInf{5.0f/0.0f};
    std::cout << "posInf: " << posInf << std::endl;

    float negInf{-5.0f/0.0f};
    std::cout << "negInf: " << negInf << std::endl;

    float ind{0.0f/0.0f};
    std::cout << "ind: " << ind << std::endl;
    return (0);
}
