// Copyright 2020 Magellan
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int add(int x, int y);

int main() {
    int x{}, y{};

    cout << "Enter a value for x: ";
    cin >> x;

    cout << "Enter a value for y: ";
    cin >> y;

    cout << "Total of x and y is: " << add(x, y) << endl;

    return (0);
}
