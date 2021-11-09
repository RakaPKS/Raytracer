
#ifndef RAYTRACER_PROJECTILE_H
#define RAYTRACER_PROJECTILE_H

#include "../Primaries/RTuple.h"
#include "Environment.h"

class Projectile {
public:
    RPoint position;
    RVector velocity;

    Projectile(const RPoint &position, const RVector &velocity) : position(position), velocity(velocity) {};

    Projectile tick(const Environment &env) const {
        return {position + velocity, velocity + env.gravity + env.wind};
    }

};

#endif //RAYTRACER_PROJECTILE_H
