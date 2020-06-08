// Copyright 2020 Magellan
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional>

struct Season {
    std::string_view name{};
    double averageTemperature{};
};

int main() {
    std::array<Season, 4> seasons{
        { { "Sprint", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 } }
    };

    // Sorting with ascending order of temperature.
    std::sort(seasons.begin(), seasons.end(),
            [](const auto &season1, const auto &season2) {
                return (season1.averageTemperature < season2.averageTemperature);
            });

    std::cout << "Ascending order of seasons, using self-written lambda" << std::endl;
    for (const auto &season : seasons) {
        std::cout << season.name << std::endl;
    }

    return (0);
}
