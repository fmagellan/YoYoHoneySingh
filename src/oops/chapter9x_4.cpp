// Copyright 2020 Magellan
#include <cassert>
#include <cstdint>
#include <cmath>
#include <iostream>

class FixedPoint2 {
 private:
    int_least16_t m_nonFraction{};
    int_least8_t m_fraction{};

 public:
    explicit FixedPoint2(int_least16_t nonFraction = 0, int_least8_t fraction = 0);
    explicit FixedPoint2(const double number);
    operator double () const;
    FixedPoint2 operator- () const;

    friend std::ostream& operator<< (std::ostream& out, const FixedPoint2 &number);
    friend std::istream& operator>> (std::istream& in, FixedPoint2 &number);
    friend bool operator== (const FixedPoint2 &f1, const FixedPoint2 &f2);
    friend FixedPoint2 operator+ (const FixedPoint2 &f1, const FixedPoint2 &f2);
};

FixedPoint2::FixedPoint2(int_least16_t nonFraction, int_least8_t fraction)
    : m_nonFraction { nonFraction },
    m_fraction{ fraction } {
    assert((fraction > -99) && (fraction < 99) && "Fraction has to be between -99 and +99");
    // For negative numbers, make sure that both of them are negative,
    // so that the computations later will be simple.
    bool isNegative = ((m_nonFraction < 0) || (m_fraction < 0));
    if (isNegative) {
        if (m_nonFraction) {
            m_nonFraction = -m_nonFraction;
        }
        if (m_fraction) {
            m_fraction = -m_fraction;
        }
    }
}

FixedPoint2::FixedPoint2(double number) {
    m_nonFraction = static_cast<int_least16_t>(number);
    number -= m_nonFraction;
    number *= 100;
    m_fraction = static_cast<int_least8_t>(std::round(number));
}

std::ostream& operator<< (std::ostream& out, const FixedPoint2 &number) {
    out << static_cast<double>(number);

    return (out);
}

std::istream& operator>> (std::istream& in, FixedPoint2 &number) {
    double dNumber{};
    in >> dNumber;
    number = FixedPoint2(dNumber);
    return (in);
}

FixedPoint2::operator double() const {
    double toReturn{};
    if (m_nonFraction < 0) {
        if (m_fraction < 0) {
            toReturn = -(-m_nonFraction + (0.01d * -m_fraction));
        } else {
            toReturn = -(-m_nonFraction + (0.01d * m_fraction));
        }
    } else {
        if (m_fraction < 0) {
            toReturn = -(m_nonFraction + (0.01d * -m_fraction));
        } else {
            toReturn = m_nonFraction + (0.01d * m_fraction);
        }
    }

    return (toReturn);
}

FixedPoint2 FixedPoint2::operator- () const {
    bool isNegative = ((m_nonFraction < 0) || (m_fraction < 0));
    if (isNegative) {
        return (FixedPoint2(std::abs(m_nonFraction), std::abs(m_fraction)));
    }

    return (FixedPoint2(-m_nonFraction, -m_fraction));
}

FixedPoint2 operator+ (const FixedPoint2 &f1, const FixedPoint2 &f2) {
    double number1{ static_cast<double>(f1) };
    double number2{ static_cast<double>(f2) };
    double dResult{ number1 + number2 };

    return (FixedPoint2(dResult));
}

bool operator== (const FixedPoint2 &f1, const FixedPoint2 &f2) {
    bool isF1Negative = ((f1.m_nonFraction < 0) || (f1.m_fraction < 0));
    bool isF2Negative = ((f1.m_nonFraction < 0) || (f2.m_fraction < 0));
    if (isF1Negative ^ isF2Negative) {
        return (false);
    }

    return ((abs(f1.m_nonFraction) == abs(f2.m_nonFraction)) && (abs(f1.m_fraction) == abs(f2.m_fraction)));
}
void testAddition() {
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';  // both positive, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';  // both positive, with decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';  // both negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';  // both negative, with decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';  // second negative, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';  // second negative, possible decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';  // first negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';  // first negative, possible decimal overflow
}

int main() {
    {
        FixedPoint2 a{ 34, 56 };
        std::cout << a << '\n';

        FixedPoint2 b{ -2, 8 };
        std::cout << b << '\n';

        FixedPoint2 c{ 2, -8 };
        std::cout << c << '\n';

        FixedPoint2 d{ -2, -8 };
        std::cout << d << '\n';

        FixedPoint2 e{ 0, -5 };
        std::cout << e << '\n';

        std::cout << static_cast<double>(e) << '\n';
        std::cout << "======= End of 4a =======" << std::endl;
    }
    {
        FixedPoint2 a{ 0.01 };
        std::cout << a << '\n';

        FixedPoint2 b{ -0.01 };
        std::cout << b << '\n';

        FixedPoint2 c{ 5.01 };  // stored as 5.0099999... so we'll need to round this
        std::cout << c << '\n';

        FixedPoint2 d{ -5.01 };  // stored as -5.0099999... so we'll need to round this
        std::cout << d << '\n';
        std::cout << "======= End of 4b =======" << std::endl;
    }

    {
        testAddition();

        FixedPoint2 a{ -0.48 };
        std::cout << a << '\n';

        std::cout << -a << '\n';

        std::cout << "Enter a number: ";  // enter 5.678
        std::cin >> a;

        std::cout << "You entered: " << a << '\n';
    }

    return 0;
}
