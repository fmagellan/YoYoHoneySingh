// Copyright 2020 Magellan
#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string str1{ "This is a simiple string" };
    std::string str2{};
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;

    str2 = std::move(str1);
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;

    return (0);
}
