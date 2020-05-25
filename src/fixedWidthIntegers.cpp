// Copyright 2020 Magellan
#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "std::uint16_t is:" << sizeof (std::uint16_t) << " bytes" << endl;
    cout << "sizeof(std::int_least16_t) is:" << sizeof (std::int_least16_t) << " bytes" << endl;
    cout << "sizeof(std::int_fast16_t) is:" << sizeof (std::int_fast16_t) << " bytes" << endl;
    cout << "sizeof(std::size_t) is:" << sizeof (std::size_t) << " bytes" << endl;

    return (0);
}
