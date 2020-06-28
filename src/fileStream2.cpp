// Copyright 2020 Magellan
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file{ "mytemp/dump.txt" };
    if (!file) {
        std::cout << "Couldn't open the file mytemp/dump.txt !" << std::endl;
        return (0);
    }

    while (file) {
        std::string str{};
        // file >> str;
        std::getline(file, str);
        std::cout << str << std::endl;
    }

    return (0);
}
