#ifndef RAYTRACER_RTUPLE_H
#define RAYTRACER_RTUPLE_H

#include <cmath>

class RTuple {
public:
    double x, y, z, w;

    RTuple(double x, double y, double z, double w);

    [[nodiscard]] bool isVector();

    [[nodiscard]] bool isPoint();

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

    RVector(double x, double y, double z);


    [[nodiscard]] double magnitude();

    [[nodiscard]] RVector normalize();

    [[nodiscard]] double dot(const RVector &rhs);

    [[nodiscard]] RVector cross(const RVector &rhs);

    RVector operator-() const {
        return {-x, -y, -z};
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

    RPoint(double x, double y, double z);

    RPoint operator-(){
        return {-x, -y, -z};
    }

    RPoint operator*(const double &scalar){
        return {x * scalar, y * scalar, z * scalar};
    }

    RPoint operator/(const double &scalar) {
        return {x / scalar, y / scalar, z / scalar};
    }
};

RPoint operator+(const RPoint &a, const RVector &b);

RPoint operator+(const RVector &a, const RPoint &b);

RPoint operator-(const RPoint &a, const RVector &b);

RPoint operator*(const double &scalar, RPoint a);

RVector operator+(const RVector &a, const RVector &b);

RVector operator-(const RVector &a, const RVector &b);

RVector operator-(const RPoint &a, const RPoint &b);

RVector operator*(const double &scalar, RVector a);

double dot(RVector a, const RVector &rhs);

RVector cross(RVector a, const RVector &rhs);


#endif //RAYTRACER_RTUPLE_H
