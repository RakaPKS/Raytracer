//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include <iostream>
#include "Primaries/RTuple.h"
#include "Projectile/Projectile.h"
#include "Projectile/Environment.h"
#include "Graphics/Canvas.h"

void shootCannon(){
    Projectile p = {RPoint(0, 1, 0), RVector(1, 1, 0).normalize()};
    Environment env = {RVector(0, -0.1, 0), RVector(-0.01, 0, 0)};
    while(p.position.y > 0) {
        std::cout << "Position: x:" << p.position.x << " y: " << p.position.y << " z: " << p.position.z << std::endl;
        p = p.tick(env);
    }
    std::cout << "Position: x:" << p.position.x << " y: " << p.position.y << " z: " << p.position.z << std::endl;
}

void testCanvas(){
    Canvas c = Canvas(20,10);
    std::cout << c.width << c.height << c.length << std::endl;

}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //RTuple x = {12.0,12.0,12.0,1};
    //std::cout << x.isVector() << x.isPoint();
    //shootCannon();
    testCanvas();

    return 0;
}
