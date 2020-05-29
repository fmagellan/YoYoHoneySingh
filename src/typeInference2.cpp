// Copyright 2020 Magellan

// Try to compile the program with the below commands.
// g++ --std=c++17 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++14 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++11 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++03 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
#include <iostream>

auto add(int x, int y) -> int {
    return (x + y);
}

int main() {
    std::cout << add(2, 3) << std::endl;

    return (0);
}
