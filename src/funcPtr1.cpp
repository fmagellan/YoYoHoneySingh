// Copyright 2020 Magellan
#include <functional>
#include <iostream>

using ArithmeticFunc = std::function<int(int, int)>;

int getInputNumber() {
    int x{};

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> x;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid number. Try again." << std::endl;
        } else {
            std::cin.ignore(1000, '\n');
            break;
        }
    }

    return (x);
}

char getInputOperation() {
    char operation{};

    while (true) {
        std::cout << "Enter one of the four operations(+ - * /): ";
        std::cin >> operation;

        if (std::cin.fail()) {
            std::cin.clear();
        }

        std::cin.ignore(1000, '\n');
        if ((operation == '+') || (operation == '-') ||(operation == '*') || (operation == '/')) {
            break;
        }
    }

    return (operation);
}

int add(int x, int y) {
    return (x + y);
}

int subtract(int x, int y) {
    return (x - y);
}

int multiply(int x, int y) {
    return (x * y);
}

int divide(int x, int y) {
    return (x / y);
}

ArithmeticFunc getArithmeticFunction(char operation) {
    ArithmeticFunc funcPtr{};
    switch (operation) {
        case '+':
            funcPtr = add;
            break;

        case '-':
            funcPtr = subtract;
            break;

        case '*':
            funcPtr = multiply;
            break;

        case '/':
            funcPtr = divide;
            break;
    }

    return funcPtr;
}

int main() {
    int x{ getInputNumber() };
    int y{ getInputNumber() };
    char operation{ getInputOperation() };

    std::cout << "x: " << x << ", y: " << y << ", operation: " << operation << std::endl;
    ArithmeticFunc func{ getArithmeticFunction(operation) };
    std::cout << "Result: " << func(x, y) << std::endl;

    return (0);
}
