// Copyright 2020 Magellan
#include <iostream>

void print(unsigned int value) {
}

void print(float value) {
}

//Compiler should return error for all the below three cases.
int main() {
    print('a');
//    print(10);
//   print(3.14);
    return (0);
}
