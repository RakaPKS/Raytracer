
#include "Color.h"


    Color::Color() : red(0), green(0), blue(0) {};

Color::Color(double red, double green, double blue) : red(red), green(green), blue(blue) {}


    std::string Color::getPPM(){
        std::string x = std::to_string(std::max(std::min((int)round(red * 255), 255),0));
        x += " " +  std::to_string(std::max(std::min((int) round(green * 255), 255),0));
        x += " " +  std::to_string(std::max(std::min((int) round(blue * 255), 255),0));
        return x;
    }
