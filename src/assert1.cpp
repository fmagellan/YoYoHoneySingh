// Copyright 2020 Magellan
#define NDEBUG
#include <cassert>
#include <iostream>


void printString(const char *ptr) {
    assert(ptr && "ptr in printString is NULL.");

    std::cout << ptr << std::endl;
}

int main() {
    const char *ptr{ "This is first message" };
    printString(ptr);
    ptr = nullptr;
    printString(ptr);

    return (0);
}
