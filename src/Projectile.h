//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_PROJECTILE_H
#define RAYTRACER_PROJECTILE_H

#include "RTuple.h"
#include "Environment.h"

class Projectile{
public:
    RPoint position;
    RVector velocity;
    Projectile(const RPoint &position, const RVector &velocity) : position(position), velocity(velocity) {};

    Projectile tick(const Environment& env) const{
        return {position + velocity, velocity + env.gravity + env.wind};
    }

};
#endif //RAYTRACER_PROJECTILE_H