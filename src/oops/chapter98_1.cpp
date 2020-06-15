// Copyright 2020 Magellan
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade {
    std::string m_name{};
    char m_grade{ 'F' };
};

class GradeMap {
 private:
    std::vector<StudentGrade> m_map{};

 public:
    char &operator[](std::string name) {
        auto pStudentEntry = std::find_if(m_map.begin(), m_map.end(),
            [name](const StudentGrade s1) {
                return (s1.m_name == name);
            });
        if (pStudentEntry != m_map.end()) {
            return (pStudentEntry->m_grade);
        }

        m_map.push_back(StudentGrade{ name });
        return (m_map.back().m_grade);
    }
};

int main() {
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
