// Copyright 2020 Magellan

#include <iostream>

using std::cout;
using std::endl;

int main() {
    #define NINE 9
#ifdef NINE
    cout << "NINE is: " << NINE << endl;
#else
    cout << "NINE is not defined." << endl;
#endif

    return (0);
}
