//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_RTUPLE_H
#define RAYTRACER_RTUPLE_H

#include <cmath>

class RTuple {
public:
    double x, y, z;
    double w = 0;

    RTuple(double x, double y, double z) : x(x), y(y), z(z) {};
    RTuple(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {};


    [[nodiscard]] bool isVector() const {
        return !w;
    }

    [[nodiscard]] bool isPoint() const {
        return w;
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

    virtual RTuple operator+(const RTuple &rhs) const{
        return {x+rhs.x, y+rhs.y, z+rhs.z, w+rhs.w};
    }

    RTuple operator-(const RTuple &rhs) const{
        return {x-rhs.x, y-rhs.y, z-rhs.z, w-rhs.w};
    }

    RTuple operator-() const{
        return{-x, -y, -z, -w};
    }

    RTuple operator*(double scalar) const{
        return {x* scalar, y* scalar, z* scalar, w*scalar};
    }

    RTuple operator/(double scalar) const{
        return {x/scalar, y/scalar, z/scalar, w/scalar};
    }

};

class RPoint : public RTuple {

public:
    RPoint(double x, double y, double z) : RTuple(x, y, z, 1) {}

};

class RVector : public RTuple {

public:
    RVector(double x, double y, double z) : RTuple(x, y, z, 0) {}

    double magnitude(){
        return sqrt(x*x + y*y + z*z);
    }

    RVector normalize(){
        return{x/magnitude(), y/magnitude(), z/magnitude()};
    }

    double dot(const RVector &rhs){
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    RVector cross(const RVector &rhs){
        return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
    }
};

static RTuple operator*(double scalar, const RTuple &rhs){
    return {rhs.x * scalar, rhs.y * scalar, rhs.z * scalar, rhs.w * scalar};
};

static RPoint operator+(const RPoint &a, const RVector &b){
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}

static RPoint operator+(const RVector &a, const RPoint &b){
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}

static RPoint operator+(const RPoint &a, const RPoint &b){
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}

static RVector operator+(const RVector &a, const RVector &b){
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}



#endif //RAYTRACER_RTUPLE_H
