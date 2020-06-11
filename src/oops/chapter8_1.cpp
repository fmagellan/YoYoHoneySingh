// Copyright 2020 Magellan
#include <cmath>
#include <iostream>

class Point2d {
 public:
    using point_t = double;
    friend Point2d::point_t distanceFrom(const Point2d &p1, const Point2d &p2);

 private:
     point_t m_x{ 0.0 };
     point_t m_y{ 0.0 };

 public:
     explicit Point2d(point_t x = 0.0, point_t y = 0.0)
         : m_x{ x }, m_y { y } {
     }

     void print() {
         std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
     }

     point_t distanceTo(const Point2d &toPoint) {
         return (std::sqrt((m_x - toPoint.m_x)*(m_x - toPoint.m_x) + (m_y - toPoint.m_y)*(m_y - toPoint.m_y)));
     }
};

Point2d::point_t distanceFrom(const Point2d &p1, const Point2d &p2) {
    return (std::sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y)));
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return(0);
}
