// Copyright 2020 Magellan
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    int i{5};
    cout << "Value of i: " << i << endl;
    cout << "Enter a new value for i:" << endl;
    cin >> i;
    cout << "The value entered is: " << i << endl;
    cout << "Double the value  is: " << 2 * i << endl;
    cout << "Triple the value  is: " << 3 * i << endl;

    return (0);
}
