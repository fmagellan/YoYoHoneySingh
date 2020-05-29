// Copyright 2020 Magellan
#include <iostream>
#include <string>

struct Person {
    std::string name {"WWE superstar"};
    int age{30};    // years
    int height{72}; // inches
};

struct PersonNoDefaults {
    std::string name;
    int age;    // years
    int height; // inches
};

void printPerson(Person person) {
    std::cout << "Name  : " << person.name << std::endl;
    std::cout << "Age   : " << person.age << " years" << std::endl;
    std::cout << "Height: " << person.height << " inches" << std::endl << std::endl;

    return;
}

void printPerson(PersonNoDefaults person) {
    std::cout << "Name  : " << person.name << std::endl;
    std::cout << "Age   : " << person.age << " years" << std::endl;
    std::cout << "Height: " << person.height << " inches" << std::endl << std::endl;

    return;
}

int main() {
    Person viper{"Randy Orton", 37, 78};
    printPerson(viper);

    Person phenomenon;
    phenomenon = {"AJ Styles" , 40, 73};
    printPerson(phenomenon);

    Person faceless;
    printPerson(faceless);

    return (0);
}
