// Copyright 2020 Magellan
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    char c{};

    cout << "Enter a character: " << endl;
    cin >> c;
    cout << "You entered: " << c << endl;

    cout << "Enter a character: " << endl;
    cin >> c;
    cout << "You entered: " << c << endl;

    cout << "Enter a character: " << endl;
    cin >> c;
    cout << "You entered: " << c << endl;

    cout << "Enter a character: " << endl;
    cin >> c;
    cout << "You entered: " << c << endl;

    cout << "Enter a character: ";
    cin >> c;
    cout << "\rYou entered: " << c;

    cout << "\rEnter a character: " << endl;
    cin >> c;
    cout << "You entered: " << c << endl;

    return (0);
}
