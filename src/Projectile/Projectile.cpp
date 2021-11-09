#include "Projectile.h"

Projectile::Projectile(const RPoint &position, const RVector &velocity) : position(position), velocity(velocity) {};

Projectile Projectile::tick(const Environment &env) const {
    return {position + velocity, velocity + env.gravity + env.wind};
}