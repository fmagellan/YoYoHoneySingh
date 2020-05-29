// Copyright 2020 Magellan
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your name: ";
    std::string name;
//    std::getline(std::cin, name);
    std::cin >> name;
    std::cin.ignore(100, '\n');

    std::cout << "Enter your age: ";
    std::string age;
    std::getline(std::cin, age);

    std::cout << "Hello " << name << ", your age is " << age << " seconds." << std::endl;

    return (0);
}
