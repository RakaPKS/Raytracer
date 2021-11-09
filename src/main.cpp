//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include <iostream>
#include <fstream>
#include "Primaries/RTuple.h"
#include "Projectile/Projectile.h"
#include "Projectile/Environment.h"
#include "Graphics/Canvas.h"
#include "Graphics/PPM.h"

void shootCannon(){
    Projectile p = {RPoint(200, 100, 0), RVector(100, 100, 0).normalize()};
    Environment env = {RVector(0, -1, 0), RVector(-1, 0, 0)};
    Canvas c = Canvas(210, 110);
    Color red = {1, 0 ,0};
    while(p.position.y > 0) {
        std::cout << "Position: x:" << p.position.x << " y: " << p.position.y << " z: " << p.position.z << std::endl;
        writePixel(c, (int)round(p.position.x), (int)round(p.position.y), red);
        p = p.tick(env);
    }
    PPM pm = PPM(c);
    std::string s = pm.getPPM();
    std::ofstream out("../images/Projectile.ppm");
    out << s;
    out.close();
    //::cout << "Position: x:" << p.position.x << " y: " << p.position.y << " z: " << p.position.z << std::endl;
}

void testCanvas(){
    Canvas c = Canvas(20,10);
    std::cout << c.width << c.height << c.length << std::endl;

}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //RTuple x = {12.0,12.0,12.0,1};
    //std::cout << x.isVector() << x.isPoint();
    shootCannon();
    //testCanvas();

    return 0;
}
