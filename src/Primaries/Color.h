#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <ostream>
#include "RTuple.h"
#include <string>
#include <algorithm>
#include <cmath>

class Color {
public:
    double red, green, blue;

    Color();

    Color(double red, double green, double blue);

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

    std::string getPPM() const;

};

static Color operator*(double scalar, Color c) {
    return c * scalar;
}

#endif //RAYTRACER_COLOR_H
