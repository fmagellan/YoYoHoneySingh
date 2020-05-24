// Copyright 2020 Magellan
#include <iostream>
#include "cpp/add.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int x{}, y{};

    cout << "Enter value for x: " << endl;
    cin >> x;

    cout << "Enter value for y: " << endl;
    cin >> y;

    cout << "Total of x and y : " << add(x, y) << endl;

    return (0);
}
