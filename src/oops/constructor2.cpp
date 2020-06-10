// Copyright 2020 Magellan
#include <cstdint>
#include <iostream>

class RGBA {
    using Intensity_t = std::uint_fast8_t;
 private:
    Intensity_t m_red;
    Intensity_t m_green;
    Intensity_t m_blue;
    Intensity_t m_alpha;

 public:
    RGBA() = default;
    RGBA(const Intensity_t red = 0, const Intensity_t green = 0, const Intensity_t blue = 255, const Intensity_t alpha = 255)
        : m_red{ red },
        m_green{ green },
        m_blue{ blue },
        m_alpha{ alpha }
    {
    }

    void print() {
        std::cout << "r=" << static_cast<int>(m_red)
            << " g=" << static_cast<int>(m_green)
            << " b=" << static_cast<int>(m_blue)
            << " a=" << static_cast<int>(m_alpha) << std::endl;
    }
};

int main() {
    RGBA teal{ 0, 127, 127 };
    teal.print();

    return (0);
}
