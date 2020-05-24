// Copyright 2020 Magellan
#include <iostream>

using std::cout;

int main() {
    // The below line has to return error during compilation.
    // Strings cannot be separated by new lines, but should be
    // contained in quotes, if separated by new lines !
    cout << "Raw is
        War" << endl;

    return (0);
}
