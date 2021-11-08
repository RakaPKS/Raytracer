//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "RTuple.h"

class Color {
public:
    double red, green, blue;

    Color() : red(0), green(0), blue(0) {};

    Color(double red, double green, double blue) : red(red), green(green), blue(blue) {}

    bool operator==(const Color &rhs) const {
        return red == rhs.red &&
               green == rhs.green &&
               blue == rhs.blue;
    }

    bool operator!=(const Color &rhs) const {
        return !(rhs == *this);
    }

    Color operator+(const Color &rhs) const {
        return {red + rhs.red, green + rhs.green, blue + rhs.blue};
    }

    Color operator-(const Color &rhs) const {
        return {red - rhs.red, green - rhs.green, blue - rhs.blue};
    }

    Color operator*(const Color &rhs) const {
        return {red * rhs.red, green * rhs.green, blue * rhs.blue};
    }

    Color operator*(double scalar) const {
        return {red * scalar, green * scalar, blue * scalar};
    }
};

static Color operator*(double scalar, Color c) {
    return c * scalar;
}

#endif //RAYTRACER_COLOR_H
