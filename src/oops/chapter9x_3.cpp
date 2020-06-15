// Copyright 2020 Magellan
#include <cassert>
#include <iostream>

class IntArray {
 private:
    int *m_array{};
    int m_size{};

 public:
    explicit IntArray(int size = 0);
    IntArray(const IntArray &array);
    ~IntArray();

    IntArray operator= (const IntArray &array);
    int& operator[] (const int index);

    friend std::ostream& operator<< (std::ostream &out, const IntArray &array);
};

IntArray::IntArray(int size)
    : m_array{ nullptr }, m_size{ size } {

    assert((size > 0) && "Size should be a positive number");
    m_array = new int[size]{};
}

IntArray::IntArray(const IntArray &array)
    : m_array { nullptr }, m_size{ array.m_size } {

    if (!m_size) {
        return;
    }

    m_array = new int[m_size]{};
    for (int index{}; index < m_size; ++index) {
        m_array[index] = (array.m_array)[index];
    }
}

IntArray::~IntArray() {
    if (!m_array) {
        delete[] m_array;
    }
}

IntArray IntArray::operator= (const IntArray &array) {
    if (this == &array) {
        std::cout << "I don't think so." << std::endl;
        return (*this);
    }

    if (!m_size) {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }

    m_size = array.m_size;
    m_array = new int[m_size]{};
    for (int index{}; index < m_size; ++index) {
        m_array[index] = (array.m_array)[index];
    }

    return (*this);
}

int& IntArray::operator[] (const int index) {
    assert((index >= 0) && (index < m_size) && "Array out of bounds.");

    return (m_array[index]);
}

std::ostream& operator<< (std::ostream &out, const IntArray &array) {
    for (int index{}; index < array.m_size; ++index) {
        out << array.m_array[index] << " ";
    }

    return (out);
}

IntArray fillArray() {
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return (a);
}

int main() {
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto &ref{ a };  // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return (0);
}
