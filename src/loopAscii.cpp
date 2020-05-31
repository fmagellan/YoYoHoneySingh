// Copyright 2020 Magellan
#include <iostream>

int main() {
    char myChar{'a'};
    while (myChar != 'z') {
        std::cout << myChar << ": " << static_cast<int>(myChar) << std::endl;
        ++myChar;
    }

    return (0);
}
