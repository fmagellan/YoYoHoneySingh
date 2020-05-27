// Copyright 2020 Magellan
#include <bitset>
#include <iostream>

using std::cout;
using std::endl;

std::bitset<8> pushToRight(std::bitset<8> bits) {

}

int main() {
    std::bitset<8> bits{ 0b01001001 };
    cout << "bits: " << bits << endl;

    if (bits.test(0)) {
        bits >>= 1;
        bits.set(7);
    } else {
        bits >>= 1;
    }

    cout << "bits: " << bits << endl;

    return (0);
}
