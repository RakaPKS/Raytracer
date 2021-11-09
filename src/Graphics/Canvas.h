#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H

#include "../Primaries/Color.h"

class Canvas{
public:
    int width;
    int height;
    int length;
    Color* canvasPixels;

    Canvas(int width, int height);

    [[nodiscard]] Color pixelAt(int x, int y) const;

    [[nodiscard]] int findPixelIndex(int x, int y) const;
};

void writePixel(Canvas& canvas, int x, int y, Color color);

Color pixelAt(Canvas canvas, int x, int y);


#endif //RAYTRACER_CANVAS_H
