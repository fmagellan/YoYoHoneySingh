// Copyright 2020 Magellan
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double x;
    cout << "Enter a double value for x: ";
    cin >> x;

    double y;
    cout << "Enter a double value for y: ";
    cin >> y;

    char operation;
    cout << "Enter the operation(+ - * /): ";
    cin >> operation;

    if (operation == '+') {
        cout << x << " " << operation << " " << y << " is " << x + y << endl;
    } else if (operation == '-') {
        cout << x << " " << operation << " " << y << " is " << x - y << endl;
    } else if (operation == '*') {
        cout << x << " " << operation << " " << y << " is " << x * y << endl;
    } else if (operation == '/') {
        cout << x << " " << operation << " " << y << " is " << x / y << endl;
    } else {
        cout << "Invalid operation has been entered." << endl;
    }

    return (0);
}
