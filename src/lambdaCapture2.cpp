// Copyright 2020 Magellan
#include <iostream>

// The below example illustrates Lambda captures with value, and with reference.
int main() {
    auto height{10};
    auto width{10};
    auto lambdaCaptureWithValue{
        [=]() {
            std::cout << "Lambda Value: Area: " << height * width << std::endl;
        }
    };
    auto lambdaCaptureWithReference{
        [&]() {
            std::cout << "Lambda Capture: Area: " << height * width << std::endl;
        }
    };

    lambdaCaptureWithValue();
    lambdaCaptureWithReference();

    height = width = 11;
    lambdaCaptureWithValue();
    lambdaCaptureWithReference();

    return (0);
}
