// Copyright 2020 Magellan
#ifndef INCLUDE_CPP_VECTOR3D_H_
#define INCLUDE_CPP_VECTOR3D_H_

#include "cpp/Point3d.h"

class Vector3d {
 private:
    double m_x{};
    double m_y{};
    double m_z{};

 public:
    explicit Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);
    void print() const;
    friend void Point3d::moveByVector(const Vector3d &v);
};

#endif  // INCLUDE_CPP_VECTOR3D_H_
