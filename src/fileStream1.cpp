// Copyright 2020 Magellan
#include <fstream>
#include <iostream>

int main() {
    std::ofstream file{ "mytemp/dump.txt" };
    if (!file) {
        std::cout << "Not able to open mytemp/dump.txt !" << std::endl;
        return (0);
    }

    std::cout << "Writing two lines to the file." << std::endl;
    file << "If you are reading this," << std::endl;
    file << "you are the resistance!" << std::endl;
    file.close();

    std::cout << "Reopening to add two more lines." << std::endl;
    file.open("mytemp/dump.txt", std::ios::app);
    file << "Too many cooks spoil the broth." << std::endl;
    file << "Too many bots incur my wrath." << std::endl;

    return (0);
}
