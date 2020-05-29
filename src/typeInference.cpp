// Copyright 2020 Magellan

// Try to compile the program with the below commands.
// g++ --std=c++17 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++14 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++11 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp
// g++ --std=c++03 -I. -Iinclude/ -Ithird-party/plog/include/ src/typeInference.cpp

#include <iostream>
int main() {
    auto x{5};
    std::cout << "Value of x: " << x << std::endl;

    return (0);
}
