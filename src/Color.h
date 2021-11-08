//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "RTuple.h"

class Color : public RTuple {
    public:
    Color(double red, double green, double blue) : RTuple(red, green, blue) {}

    double red(){return x;}
    double green(){return y;}
    double blue(){return z;}

    void red(double val){x = val;}
    void green(double val){y = val;}
    void blue(double val){z = val;}

};

#endif //RAYTRACER_COLOR_H
