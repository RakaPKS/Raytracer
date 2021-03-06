#ifndef RAYTRACER_ENVIRONMENT_H
#define RAYTRACER_ENVIRONMENT_H

#include "../Primaries/RTuple.h"

class Environment {
public:
    RVector gravity;
    RVector wind;
    Environment(const RVector &gravity, const RVector &wind);
};

#endif //RAYTRACER_ENVIRONMENT_H
