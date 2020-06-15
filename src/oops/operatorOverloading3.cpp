// Copyright 2020 Magellan
#include <iostream>

class Cents {
 private:
    int m_cents;

 public:
    explicit Cents(int cents = 0) : m_cents(cents) {
    }

    friend bool operator>(const Cents &c1, const Cents &c2);
    friend bool operator<(const Cents &c1, const Cents &c2);
    friend bool operator>=(const Cents &c1, const Cents &c2);
    friend bool operator<=(const Cents &c1, const Cents &c2);
};

bool operator>(const Cents &c1, const Cents &c2) {
    return (c1.m_cents > c2.m_cents);
}

bool operator<(const Cents &c1, const Cents &c2) {
//    return (c1.m_cents < c2.m_cents);
    return !(c1 >= c2);
}

bool operator>=(const Cents &c1, const Cents &c2) {
    return (c1.m_cents >= c2.m_cents);
}

bool operator<=(const Cents &c1, const Cents &c2) {
//    return (c1.m_cents <= c2.m_cents);
    return !(c1 > c2);
}

int main() {
    Cents nickel{ 10 };
    Cents dime{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";

    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";

    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";

    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";

    return (0);
}
