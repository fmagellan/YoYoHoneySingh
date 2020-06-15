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
     explicit Fraction(const int numerator = 0, const int denominator = 1)
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
     friend std::ostream& operator<<(std::ostream &out, const Fraction &fr);
     friend std::istream& operator>>(std::istream &in, Fraction &fr);
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

std::ostream& operator<<(std::ostream &out, const Fraction &fr) {
    out << fr.m_numerator << "/" << fr.m_denominator;
    return (out);
}

std::istream& operator>>(std::istream &in, Fraction &fr) {
    in >> fr.m_numerator >> fr.m_denominator;
    return (in);
}

int main() {
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return (0);
}
