// Copyright 2020 Magellan
#include <iostream>
#include <string>
#include <string_view>

class Ball_1 {
    using Color_t = std::string;
    using Radius_t = double;

 private:
     Color_t m_color{"black"};
     Radius_t m_radius{10.0};

 public:
     Ball_1() = default;

     Ball_1(const Color_t color) {
         m_color = color;
     }

     Ball_1(const Radius_t radius) {
         m_radius = radius;
     }

     Ball_1(const Color_t color, const Radius_t radius) {
         m_color = color;
         m_radius = radius;
     }

     void print() {
         std::cout << "Ball1: color: " << m_color << ", radius: " << m_radius << std::endl;
     }
};

class Ball_2 {
    using Color_t = std::string;
    using Radius_t = double;

 private:
     Color_t m_color{"black"};
     Radius_t m_radius{10.0};

 public:
     Ball_2(const Color_t color = "black" , const Radius_t radius = 10.0) {
         m_color = color;
         m_radius = radius;
     }

     Ball_2(const Radius_t radius) {
         m_radius = radius;
     }

     void print() {
         std::cout << "Ball_2: color: " << m_color << ", radius: " << m_radius << std::endl;
     }
};

int main() {
    {
        Ball_1 def{};
        def.print();

        Ball_1 blue{ "blue" };
        blue.print();

        Ball_1 twenty{ 20.0 };
        twenty.print();

        Ball_1 blueTwenty{ "blue", 20.0 };
        blueTwenty.print();
    }
    {
        Ball_2 def{};
        def.print();

        Ball_2 blue{ "blue" };
        blue.print();

        Ball_2 twenty{ 20.0 };
        twenty.print();

        Ball_2 blueTwenty{ "blue", 20.0 };
        blueTwenty.print();
    }
    return (0);
}
