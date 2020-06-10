// Copyright 2020 Magellan
#include <iostream>

class Point3d {
 private:
     int m_x{};
     int m_y{};
     int m_z{};

 public:
     void setValues(const int x, const int y, const int z) {
         m_x = x;
         m_y = y;
         m_z = z;
     }

     void print() {
         std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
     }

     bool isEqual(const Point3d &point) const {
         return ((m_x == point.m_x) && (m_y == point.m_y) && (m_z == point.m_z));
     }
};

int main() {
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();

    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2)) {
        std::cout << "point1 and point2 are equal." << std::endl;
    } else {
        std::cout << "point1 and point2 are not equal." << std::endl;
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3)) {
        std::cout << "point1 and point3 are equal." << std::endl;
    } else {
        std::cout << "point1 and point3 are not equal." << std::endl;
    }

    return (0);
}
