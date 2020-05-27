// Copyright 2020 Magellan
#include <bitset>
#include <iostream>

int main() {
    std::bitset<10> bits{};
    std::cout << "bits: " << bits << std::endl;
    bits.set(3);
    std::cout << "bits: " << bits << std::endl;
    std::cout << "bits[3]: " << bits.test(3) << std::endl;

    return (0);
}
