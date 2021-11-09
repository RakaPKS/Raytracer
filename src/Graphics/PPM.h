#ifndef RAYTRACER_PPM_H
#define RAYTRACER_PPM_H

#include "Canvas.h"
#include <vector>
#include <string>

class PPM{
private:
    const int max_size = 70;
public:
    std::vector<std::string> lines;
    int size;

    PPM(Canvas c);

    [[nodiscard]] std::string getPPM() const;

};

#endif //RAYTRACER_PPM_H
