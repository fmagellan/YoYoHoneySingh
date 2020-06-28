// Copyright 2020 Magellan
#include <iostream>
#include <stdexcept>

class Fraction {
 private:
    int m_numerator{};
    int m_denominator{};

 public:
    Fraction(const int numerator, const int denominator)
        : m_numerator{ numerator }, m_denominator{ denominator } {
        if (denominator == 0)
        throw (std::runtime_error("Denominator is zero."));
    }

    void print() {
        std::cout << "The Fraction is: " << m_numerator << "/" << m_denominator << std::endl;
    }
};

int main() {
    int numerator{};
    int denominator{};

    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        Fraction fraction{numerator, denominator};
        fraction.print();
    }
    catch (const std::exception &exception) {
        std::cout << "Exception encountered with the reason: " << exception.what() << std::endl;
    }

    return (0);
}
