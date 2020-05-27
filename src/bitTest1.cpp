// Copyright 2020 Magellan

// Write a program that asks the user to input a number between 0 and 255.
// Print this number as an 8-bit binary number (of the form #### ####).
// Don’t use any bitwise operators. Don’t use std::bitset

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int userInput{};
    cout << "Enter a number between 0-255: ";
    cin >> userInput;

    if(userInput > 255) {
        cout << "Come back tomorrow." << endl;
        return (0);
    }

    int remainder{userInput};
    int bits{};
    cout << "Binary representation is: ";

    bits = remainder/128;
    remainder %= 128;
    cout << bits;

    bits = remainder/64;
    remainder %= 64;
    cout << bits;

    bits = remainder/32;
    remainder %= 32;
    cout << bits;

    bits = remainder/16;
    remainder %= 16;
    cout << bits << " ";

    bits = remainder/8;
    remainder %= 8;
    cout << bits;

    bits = remainder/4;
    remainder %= 4;
    cout << bits;

    bits = remainder/2;
    remainder %= 2;
    cout << bits;

    cout << remainder << endl;

    return (0);
}
