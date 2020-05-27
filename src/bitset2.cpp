// Copyright 2020 Magellan
#include <bitset>
#include <iostream>

int main() {
    std::bitset<4> bits{ 0b0110 };
    std::cout << "bits: " << bits << std::endl;

    std::cout << "bits: " << (bits << 1) << std::endl;

    bits << 1;
    std::cout << "bits: " << (bits >> 1) << std::endl;

    return (0);
}
