//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_RTUPLE_H
#define RAYTRACER_RTUPLE_H

#include <cmath>

class RTuple {
public:
    double x, y, z, w;

    RTuple(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

    [[nodiscard]] bool isVector() const {
        return w == 0;
    }

    [[nodiscard]] bool isPoint() const {
        return w == 1;
    }

    bool operator==(const RTuple &rhs) const {
        return x == rhs.x &&
               y == rhs.y &&
               z == rhs.z &&
               w == rhs.w;
    }

    bool operator!=(const RTuple &rhs) const {
        return !(rhs == *this);
    }
};

class RVector : public RTuple {

public:
    double x, y, z;
    double w = 0;

    RVector(double x, double y, double z) : RTuple(x, y, z, 0), x(x), y(y), z(z), w(0) {}

    RVector operator-() const {
        return {-x, -y, -z};
    }

    [[nodiscard]] double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    [[nodiscard]] RVector normalize() const {
        return {x / magnitude(), y / magnitude(), z / magnitude()};
    }

    [[nodiscard]] double dot(const RVector &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    [[nodiscard]] RVector cross(const RVector &rhs) const {
        return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
    }

    RVector operator*(const double &scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    RVector operator/(const double &scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }
};


class RPoint : public RTuple {

public:
    double x, y, z;
    double w = 1;

    RPoint(double x, double y, double z) : RTuple(x, y, z, 1), x(x), y(y), z(z), w(1) {}

    RPoint operator-() const {
        return {-x, -y, -z};
    }

    RPoint operator*(const double &scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    RPoint operator/(const double &scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }
};

static RPoint operator+(const RPoint &a, const RVector &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

static RPoint operator+(const RVector &a, const RPoint &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

static RPoint operator-(const RPoint &a, const RVector &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

static RPoint operator*(const double &scalar, const RPoint a) {
    return a * scalar;
}

static RVector operator+(const RVector &a, const RVector &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}


static RVector operator-(const RVector &a, const RVector &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

static RVector operator-(const RPoint &a, const RPoint &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

static RVector operator*(const double &scalar, const RVector a) {
    return a * scalar;
}

static double dot(const RVector a, const RVector &rhs) {
    return a.x * rhs.x + a.y * rhs.y + a.z * rhs.z;
}

static RVector cross(const RVector a, const RVector &rhs) {
    return {a.y * rhs.z - a.z * rhs.y, a.z * rhs.x - a.x * rhs.z, a.x * rhs.y - a.y * rhs.x};
}


#endif //RAYTRACER_RTUPLE_H
