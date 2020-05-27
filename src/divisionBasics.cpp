// Copyright 2020 Magellan
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int x{65};
    int y{7};

    cout << "x: " << x << " , y: " << y << endl;
    cout << "int/int : " << x/y << endl;
    cout << "double/int : " << static_cast<double>(x)/y << endl;
    cout << "int/double : " << x/static_cast<double>(y) << endl;
    cout << "double/double : " << static_cast<double>(x)/static_cast<double>(y) << endl;
    cout << "x/0:" << x/0 << endl;

    return (0);
}
