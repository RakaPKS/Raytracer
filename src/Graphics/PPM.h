#ifndef RAYTRACER_PPM_H
#define RAYTRACER_PPM_H

#include "Canvas.h"
#include <vector>
#include <string>

class PPM{
private:
    // Maximum stable amount of characters for each line in the PPM
    const int max_size = 70;
public:
    std::vector<std::string> lines;
    int size;

    explicit PPM(Canvas c);

    //Returns a string containing the canvas in the PPM format
    [[nodiscard]] std::string getPPM();

};

#endif //RAYTRACER_PPM_H
