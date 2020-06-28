// Copyright 2020 Magellan
#include <fstream>
#include <iostream>

int main() {
    std::fstream file{ "mytemp/dump.txt", std::ios::in | std::ios::out };
    if (!file) {
        std::cout << "Not able to open the file dump.txt." << std::endl;
        return (0);;
    }

    char ch{};
    while (file.get(ch)) {
        if (ch == 't') {
            file.seekg(-1, std::ios::cur);
            file << '#';
            file.seekg(file.tellg(), std::ios::beg);
        }
        std::cout << ch << '\n';
    }

    return (0);
}
