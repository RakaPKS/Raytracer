#include <iostream>
#include <fstream>
#include "src/Primaries/RTuple.h"
#include "src/Projectile/Projectile.h"
#include "src/Projectile/Environment.h"
#include "src/Graphics/Canvas.h"
#include "src/Graphics/PPM.h"

void shootCannon(){
    Projectile p = {RPoint(0, 1, 0), RVector(1, 1.8, 0).normalize()*11.25};
    Environment env = {RVector(0, -0.1, 0), RVector(-0.01, 0, 0)};
    Canvas c = Canvas(900, 500);
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
