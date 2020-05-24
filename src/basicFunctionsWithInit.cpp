// Copyright 2020 Magellan

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int getInputValue() {
    int input;
    cout << "Enter an integer value: ";
    cin >> input;

    return (input);
}

int main() {
    int a{getInputValue()};
    int b{getInputValue()};

    cout << "a + b = " << a + b << endl;

    return (0);
}
