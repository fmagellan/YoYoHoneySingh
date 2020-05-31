// Copyright 2020 Magellan
#include <algorithm>
#include <iostream>
#include <utility>

int main() {
    int x{2}, y{3};

    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::swap(x, y);
    std::cout << "x: " << x << ", y: " << y << std::endl;

    int array[]{ 30, 50, 20, 10 , 40 };
    constexpr int sizeOfArray = static_cast<int>(std::size(array));
    std::cout << "Array before sorting:";
    for (int index = 0; index < sizeOfArray; ++index) {
        std::cout << " " << array[index];
    }
    std::cout << std::endl;

    std::sort(std::begin(array), std::end(array));
    std::cout << "Array after sorting:";
    for (int index = 0; index < sizeOfArray; ++index) {
        std::cout << " " << array[index];
    }
    std::cout << std::endl;

    return (0);
}
