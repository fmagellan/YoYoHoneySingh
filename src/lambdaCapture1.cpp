// Copyright 2020 Magellan
#include <iostream>

// This example illustrates that we should never initialise
// the variables inside lamba, with that of its outer scope.

int main() {
    auto height{10};
    auto width{10};
    auto lambdaFunc{
        [area{ height * width }]() {
            std::cout << "Area: " << area << std::endl;
        }
    };

    lambdaFunc();
    height = width = 11;
    lambdaFunc();

    return (0);
}
