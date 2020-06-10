// Copyright 2020 Magellan
#include <iostream>

class Rectangle {
 private:
     int m_length{ 0 };
     int m_breadth{ 0 };

 public:
     Rectangle() = default;
     Rectangle(int length, int breadth)
        : m_length{ length },
         m_breadth{ breadth } {
         }

     void print() {
         std::cout << "Rectangle length: " << m_length << ", breadth: " << m_breadth << std::endl;
     }
};

int main() {
    Rectangle x{};
    x.print();

    return (0);
}
