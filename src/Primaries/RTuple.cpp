#include "RTuple.h"

    RTuple::RTuple(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

    [[nodiscard]] bool RTuple::isVector() const{
        return w == 0;
    }

    [[nodiscard]] bool RTuple::isPoint() const{
        return w == 1;
    }

    RVector::RVector(double x, double y, double z) : RTuple(x, y, z, 0), x(x), y(y), z(z), w(0) {}

    [[nodiscard]] double RVector::magnitude() const{
        return sqrt(x * x + y * y + z * z);
    }

    [[nodiscard]] RVector RVector::normalize() const{
        return {x / magnitude(), y / magnitude(), z / magnitude()};
    }

    [[nodiscard]] double RVector::dot(const RVector &rhs) const{
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    [[nodiscard]] RVector RVector::cross(const RVector &rhs) const{
        return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
    }

    RPoint::RPoint(double x, double y, double z) : RTuple(x, y, z, 1), x(x), y(y), z(z), w(1) {}

RPoint operator+(const RPoint &a, const RVector &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

RPoint operator+(const RVector &a, const RPoint &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

RPoint operator-(const RPoint &a, const RVector &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

RPoint operator*(const double &scalar, RPoint a) {
    return a * scalar;
}

RVector operator+(const RVector &a, const RVector &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}


RVector operator-(const RVector &a, const RVector &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

RVector operator-(const RPoint &a, const RPoint &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

RVector operator*(const double &scalar, RVector a) {
    return a * scalar;
}

double dot(RVector a, const RVector &rhs) {
    return a.x * rhs.x + a.y * rhs.y + a.z * rhs.z;
}

RVector cross(RVector a, const RVector &rhs) {
    return {a.y * rhs.z - a.z * rhs.y, a.z * rhs.x - a.x * rhs.z, a.x * rhs.y - a.y * rhs.x};
}
