// Copyright 2020 Magellan
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student {
    std::string_view m_name{};
    int m_points{};
};

int main() {
    std::array<Student, 8> arr{
        { { "Albert", 3 },
            {"Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 },
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } }
    };

    auto studentWithMaxPoints{ std::max_element(arr.begin(), arr.end(),
            [](const auto &firstStudent, const auto &secondStudent) {
            return (firstStudent.m_points < secondStudent.m_points);
            }) };

    if (studentWithMaxPoints != arr.end()) {
        std::cout << "Student with max points is: " << (*studentWithMaxPoints).m_name << std::endl;
    } else {
        std::cout << "Student with max points is not found. Comeback tomorrow !" << std::endl;
    }

    return (0);
}
