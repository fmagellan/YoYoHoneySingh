// Copyright 2020 Magellan
#include <functional>
#include <iostream>

void testIntWithFunc(const int i, const std::function<bool(int)> &func) {
    std::cout << "In testIntWithFunc(): func returned: " << std::boolalpha << func(i) << std::endl;
}

int main() {
    auto isEven {
        [](int i) {
            return ( (i % 2) == 0);
        }
    };

    if (isEven(6)) {
        std::cout << "Even number" << std::endl;
    }

    testIntWithFunc(8, isEven);
    testIntWithFunc(9, isEven);

    return (0);
}
