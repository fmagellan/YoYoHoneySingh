// Copyright 2020 Magellan
#include <iostream>

int gcd(int x, int y) {
    if ((x == 0) || (y == 0)) {
        return (0);
    }

    if (x < y) {
        std::swap(x, y);
    }

    int remainder = (x % y);
    if (remainder == 0) {
        return (y);
    }

    return (gcd(y, remainder));
}

class Fraction {
 private:
     int m_numerator{ 0 };
     int m_denominator{ 1 };

 public:
     explicit Fraction(const int numerator, const int denominator)
        : m_numerator{ numerator },
         m_denominator{ denominator } {
             int gcdNumber{ gcd(numerator, denominator) };
             if (gcdNumber != 0) {
                 m_numerator /= gcdNumber;
                 m_denominator /= gcdNumber;
             }
         }

     void print() {
         std::cout << m_numerator << "/" << m_denominator << std::endl;
     }

     friend Fraction operator*(const Fraction &f1, const int num);
     friend Fraction operator*(const int num, const Fraction &f1);
     friend Fraction operator*(const Fraction &f1, const Fraction &f2);
};

Fraction operator*(const Fraction &f1, const int num) {
    return (Fraction{ f1.m_numerator * num, f1.m_denominator });
}

Fraction operator*(const int num, const Fraction &f1) {
    return (Fraction{ f1.m_numerator * num, f1.m_denominator });
}

Fraction operator*(const Fraction &f1, const Fraction &f2) {
    return (Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator });
}

int main() {
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

    Fraction f7(0, 6);
    f7.print();

	return (0);
}
