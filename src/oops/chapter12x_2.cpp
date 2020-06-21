// Copyright 2020 Magellan
#include <cassert>
#include <iostream>
#include <vector>

class Point {
 private:
    int m_x{};
    int m_y{};
    int m_z{};

 public:
    explicit Point(int x = 0, int y = 0, int z = 0)
        : m_x(x), m_y(y), m_z(z) {
    }

    friend std::ostream& operator<<(std::ostream &out, const Point &p) {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
};

class Shape {
 public:
    virtual ~Shape() {
    }

    virtual std::ostream& print(std::ostream &out) const = 0;
    friend std::ostream& operator<< (std::ostream &out, const Shape &shape) {
        return (shape.print(out));
    }
};

class Triangle : public Shape {
 private:
    Point m_a{};
    Point m_b{};
    Point m_c{};

 public:
    explicit Triangle(const Point &a, const Point &b, const Point &c)
        : m_a{ a }, m_b{ b }, m_c{ c} {
    }

    virtual std::ostream& print(std::ostream &out) const override {
        out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")";
        return (out);
    }
};

class Circle : public Shape {
 private:
    Point m_a{};
    int m_radius{};

 public:
    explicit Circle(const Point &a, const int radius)
        : m_a{ a }, m_radius{ radius } {
        assert((m_radius > 0) && "Radius has to be a positive number.");
    }

    virtual std::ostream& print(std::ostream &out) const override {
        out << "Circle(" << m_a << ", radius " <<  m_radius << ")";
        return (out);
    }

    int getRadius() const {
        return (m_radius);
    }
};

void task_b() {
    Circle c(Point(1, 2, 3), 7);
    std::cout << c << '\n';

    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    std::cout << t << '\n';
}

int getLargestRadius(std::vector<Shape *> &v) {
    int maxRadius{};
    for (Shape *pShape : v) {
        Circle *pCircle{ dynamic_cast<Circle *>(pShape) };
        if (pCircle) {
            if (maxRadius < pCircle->getRadius()) {
                maxRadius = pCircle->getRadius();
            }
        }
    }

    return (maxRadius);
}

void task_c() {
    std::vector<Shape *> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 3));

    // print each shape in vector v on its own line here
    for (const Shape *pShape: v) {
        pShape->print(std::cout);
        std::cout << std::endl;
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (const Shape *pShape: v) {
        delete(pShape);
    }
}

int main() {
    task_c();
    return (0);
}
