// Copyright 2020 Magellan
#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array months{
        "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
    };

    auto firstPos{ std::adjacent_find(months.begin(), months.end(),
            [](const auto &first, const auto &second) {
                return (first[0] == second[0]);
            }) };

    if (firstPos != months.end()) {
        std::cout << *firstPos << " and " << *(firstPos + 1) << " start with the same first letter !" << std::endl;
    } else {
        std::cout << "Come back tomorrow." << std::endl;
    }

    auto funcWithLen5{
        [](std::string_view month) {
            return (month.size() == 5);
        }
    };

    auto numberOfMonthsWithLen5{ std::count_if(months.begin(), months.end(), funcWithLen5) };
    std::cout << "Number of months with length 5 is: " << numberOfMonthsWithLen5 << std::endl;

    return (0);
}
