// Copyright 2020 Magellan
#include <iostream>
#include <string>

int main() {
    std::string sentence[]{ "This", "is", "Sparta" };
    for (const auto &word: sentence) {
        std::cout << word << " ";
    }

    constexpr int array[]{ 1, 2, 3, 4 };
//     array[1] = 10; // Will return into compilation error.
    return (0);
}
