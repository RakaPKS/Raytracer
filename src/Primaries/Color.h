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

    std::string getPPM(){
        std::string x = std::to_string(std::max(std::min((int)round(red * 255), 255),0));
        x += " " +  std::to_string(std::max(std::min((int) round(green * 255), 255),0));
        x += " " +  std::to_string(std::max(std::min((int) round(blue * 255), 255),0));
        return x;
    }

};

static Color operator*(double scalar, Color c) {
    return c * scalar;
}

#endif //RAYTRACER_COLOR_H
