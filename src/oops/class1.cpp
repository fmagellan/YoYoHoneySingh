// Copyright 2020 Magellan
#include <iostream>

class IntPair {
 public:
    int m_x{};
    int m_y{};

    void set(const int x, const int y) {
        m_x = x;
        m_y = y;
    }

    void print() {
        std::cout << "Pair(" << m_x << ", " << m_y << ")" << std::endl;
    }
};

int main() {
    IntPair p1;
    p1.set(1, 1);

    IntPair p2{ 2, 2 };

    p1.print();
    p2.print();

    return (0);
}
