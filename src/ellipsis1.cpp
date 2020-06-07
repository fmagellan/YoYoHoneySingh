// Copyright 2020 Magellan
#include <cstdarg>
#include <iostream>

void printVarArgs(int numArgs, ...) {
    std::cout << "List is: ";
    va_list list;
    va_start(list, numArgs);
    for (int index{}; index < numArgs; ++index) {
        std::cout << va_arg(list, int) << "\t";
    }
    std::cout << std::endl;
    va_end(list);

    return;
}

void printVarArgsWithSentinel(int sentinel, ...) {
    std::cout << "List is: ";
    va_list list;
    va_start(list, sentinel);
    while (true) {
        int arg = va_arg(list, int);
        if (arg == 0xffffffff) {
            break;
        }
        std::cout << arg << "\t";
    }
    std::cout << std::endl;
    va_end(list);

    return;
}

int main() {
    printVarArgs(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    printVarArgs(5, 11, 12, 13, 14, 15);
    printVarArgsWithSentinel(0xffffffff, 21, 22, 23, 24, 25, 26, 0xffffffff);

    return (0);
}
