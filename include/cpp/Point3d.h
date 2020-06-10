// Copyright 2020 Magellan
#ifndef INCLUDE_CPP_POINT3D_H_
#define INCLUDE_CPP_POINT3D_H_

class Vector3d;
class Point3d {
 private:
    double m_x{};
    double m_y{};
    double m_z{};

 public:
    explicit Point3d(double x = 0.0, double y = 0.0, double z = 0.0);
    void print() const;
    void moveByVector(const Vector3d &v);
};

#endif  // INCLUDE_CPP_POINT3D_H_
