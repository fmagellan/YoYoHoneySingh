// Copyright 2020 Magellan
#include <cassert>
#include <iostream>
#include <vector>

const int max_size_of_array{10};
class Stack {
 private:
     std::vector<int> m_array{};
     int m_size{};

 public:
     void reset() {
         m_array.resize(0);
         m_size = 0;
     }

     bool push(const int value) {
         if (m_size >= 10) {
             return (false);
         }

         m_array.push_back(value);
         ++m_size;
         return (true);
     }

     void pop() {
         assert(m_size && "Size of the stack is zero. Cannot pop !");

         --m_size;
         m_array.pop_back();
     }

     void print() {
         std::cout << "( ";
         for (auto value : m_array) {
             std::cout << value << " ";
         }
         std::cout << " )" << std::endl;
     }
};

int main() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return (0);
};
