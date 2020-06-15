// Copyright 2020 Magellan
#include <string>
#include <iostream>

class MyString {
 private:
    std::string m_string{"default"};
 public:
    explicit MyString(std::string str = "default")
        : m_string{ str } {
    }

    MyString(char) = delete;

    void print() {
        std::cout << "( " << m_string << " )" << std::endl;
    }
};

int main() {
    MyString myStr;
    myStr.print();

    return (0);
}
