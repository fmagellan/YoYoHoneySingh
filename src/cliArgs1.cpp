// Copyright 2020 Magellan
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
    for (int index{}; index < argc; ++index) {
        std::cout << "#" << index << "\t" << argv[index] << std::endl;
    }

    if (argc >= 3) {
        // Let's expect argv[2] as an integer for fun.
        std::stringstream tempStream{ argv[2] };
        int intArg{};
        if (!(tempStream >> intArg)) {
            intArg = 0;
        }

        std::cout << "The integer argument argv[2] is: " << intArg << std::endl;
    }

    return (0);
}
