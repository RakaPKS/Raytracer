//
// Created by Raka Schipperheijn on 07/11/2021.
//

#ifndef RAYTRACER_RTUPLE_H
#define RAYTRACER_RTUPLE_H

class RTuple {
public:
    double x, y, z;
    int w;

    bool isVector() {
        return !w;
    }

    bool isPoint() {
        return w;
    }
};
#endif //RAYTRACER_RTUPLE_H
