// Copyright 2020 Magellan
#include <iostream>

int main() {
    auto lambdaFunc {
        [](const auto &number) {
            static int counter{0};
            std::cout << "Counter #" << counter++ << ": " << number << std::endl;
        }
    };

    lambdaFunc(1);
    lambdaFunc(1.0);
    lambdaFunc("One");
    lambdaFunc(2);
    lambdaFunc(2.0);
    lambdaFunc("Two");

    return (0);
}
