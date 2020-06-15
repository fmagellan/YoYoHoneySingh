// Copyright 2020 Magellan
#include <cassert>
#include <iostream>
#include <string>

class Mystring {
 private:
    std::string m_string{};

 public:
    explicit Mystring(std::string str = "")
        : m_string{ str } {
    }

    std::string operator()(const int index, const int length) {
        assert(index >= 0 && "Invalid index to access the string.");
        assert(length >= 0 && "Invalid length requested.");

        std::string result{};
        for (int i{ index }; (i < (index + length)) && (i < static_cast<int>(m_string.size())); i++) {
            result += m_string[i];
        }

        return result;
    }
};

int main() {
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
