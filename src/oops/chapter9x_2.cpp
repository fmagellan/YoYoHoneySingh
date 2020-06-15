// Copyright 2020 Magellan
#include <cstdint>
#include <iostream>

class Average {
 private:
    int_least32_t m_sum{};
    int_least8_t m_count{};

 public:
    explicit Average(const int_least32_t sum = 0, const int_least8_t count = 0)
        : m_sum{ sum },
        m_count{ count } {
    }

    Average(const Average &toCopyFrom)
        : m_sum{ toCopyFrom.m_sum },
        m_count{ toCopyFrom.m_count } {
    }

    Average operator= (const Average &toCopyFrom);
    Average& operator+= (const int i);

    friend Average operator+ (const Average &a1, const int i);
    friend Average operator+ (const int i, const Average &a1);
    friend std::ostream& operator<< (std::ostream& out, const Average &a1);
};

Average Average::operator= (const Average &toCopyFrom) {
    if (this == &toCopyFrom) {
        return (*this);
    }

    m_sum = toCopyFrom.m_sum;
    m_count = toCopyFrom.m_count;

    return (*this);
}

Average& Average::operator+= (const int i) {
    m_sum += i;
    ++m_count;

    return (*this);
}

Average operator+ (const Average &a1, const int i) {
    Average result{ a1 };
    result.m_sum += i;
    ++result.m_count;

    return (result);
}

Average operator+ (const int i, const Average &a1) {
    return (a1 + i);
}

std::ostream& operator<< (std::ostream& out, const Average &a1) {
    std::cout << (a1.m_sum / (static_cast<double>(a1.m_count)));
    return (out);
}

int main() {
    Average avg{};

    avg += 4;
    std::cout << avg << '\n';  // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n';  // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n';  // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n';  // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;  // 2 calls chained together
    std::cout << avg << '\n';  // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return (0);
}
