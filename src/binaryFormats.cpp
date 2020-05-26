// Copyright 2020 Magellan
#include <iostream>

int main() {
    int bin{ 0b10101111 };
    std::cout << "Bin: " << bin << std::endl;

    int bin2 { 0b0000'1111 };
    std::cout << "Bin2: " << bin2 << std::endl;

    int i { 1'234'567 };
    std::cout << "I: " << i << std::endl;

    int format{20};
    std::cout << "Dec: " << format << std::endl;
    std::cout << std::oct << "Oct: " << format << std::endl;
    std::cout << std::hex << "Hex: " << format << std::endl;
    std::cout << std::dec << "Dec: " << format << std::endl;

    return (0);
}
