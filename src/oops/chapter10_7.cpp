// Copyright 2020 Magellan
#include <cassert>
#include <initializer_list>
#include <iostream>

class IntArray {
 private:
    int *m_array{};
    int m_size{};

 public:
    explicit IntArray(int size = 0);
    IntArray(std::initializer_list<int> list);
    IntArray(const IntArray&) = delete;  // Delete copy-constructor.

    void clear();
    ~IntArray();

    int& operator[] (int index);
    int getLength() const;
//    IntArray& operator= (const IntArray&) = delete;  // Delete copy-assignment.
    IntArray& operator= (std::initializer_list<int> list);
};

IntArray::IntArray(int size)
    : m_size { size }, m_array{ nullptr } {

    assert((m_size >= 0) && "Size cannot be a negative number.");
    if (m_size) {
        m_array = new int[size] {};
    }
}

IntArray::IntArray(std::initializer_list<int> list) {
    m_size = list.size();
    if (m_size) {
        m_array = new int[m_size] {};
        int index{};
        for (auto element : list) {
            m_array[index] = element;
            ++index;
        }
    }
}

void IntArray::clear() {
    if (!m_size) {
        return;
    }

    m_size = 0;
    delete[] m_array;
}

IntArray::~IntArray() {
    clear();
}

int& IntArray::operator[] (int index) {
    assert((index >= 0) && (index < m_size) && "index is out of bounds.");
    return (m_array[index]);
}

int IntArray::getLength() const {
    return (m_size);
}

IntArray& IntArray::operator= (std::initializer_list<int> list) {
    clear();
    m_size = list.size();
    if (!m_size) {
        return (*this);
    }

    m_array = new int[m_size]{};
    int index{};
    for (auto element : list) {
        m_array[index] = element;
        index++;
    }
}

int main() {
    {
        std::cout << "==== Example 1 ====" << std::endl;
        IntArray array{ 5, 4, 3, 2, 1 };  // initializer list
        for (int count{ 0 }; count < array.getLength(); ++count) {
            std::cout << array[count] << ' ';
        }

        std::cout << std::endl;
    }
    {
        std::cout << "==== Example 2 ====" << std::endl;
        IntArray array { 5, 4, 3, 2, 1 };  // initializer list
        for (int count{ 0 }; count < array.getLength(); ++count) {
            std::cout << array[count] << ' ';
        }

        std::cout << '\n';

        array = { 1, 3, 5, 7, 9, 11 };

        for (int count{ 0 }; count < array.getLength(); ++count) {
            std::cout << array[count] << ' ';
        }

        std::cout << '\n';
    }
    return (0);
}
