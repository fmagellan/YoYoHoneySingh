// Copyright 2020 Magellan
#include <iostream>
#include <string>

template <class T>
class Pair1 {
 private:
    T m_first{};
    T m_second{};

 public:
    Pair1(const T &first, const T &second)
        : m_first{ first }, m_second{ second } {
    }

    ~Pair1() = default;

    T first() const {
        return (m_first);
    }

    T second() const {
        return (m_second);
    }
};

template <class FIRST_t, class SECOND_t>
class Pair {
 private:
    FIRST_t m_first{};
    SECOND_t m_second{};

 public:
    Pair(const FIRST_t &first, const SECOND_t &second)
        : m_first{ first }, m_second{ second } {
    }

    const FIRST_t& first() const {
        return (m_first);
    }

    const SECOND_t& second() const {
        return (m_second);
    }
};

template <class SECOND_t>
class StringValuePair : public Pair<std::string, SECOND_t> {
 public:
    StringValuePair(const std::string &first, const SECOND_t &second)
        : Pair<std::string, SECOND_t>(first, second) {
    }
};

void task_a() {
    Pair1<int> p1(5, 8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(2.3, 4.5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task_b() {
    Pair<int, double> p1(5, 6.7);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
 
    const Pair<double, int> p2(2.3, 4);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task_c() {
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}

int main() {
    std::cout << "-----Task_a-----" << std::endl;
    task_a();

    std::cout << "-----Task_b-----" << std::endl;
    task_b();

    std::cout << "-----Task_c-----" << std::endl;
    task_c();

    return (0);
}
