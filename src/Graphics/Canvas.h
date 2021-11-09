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

    //Returns the color in the canvas at point (x,y)
    [[nodiscard]] Color pixelAt(int x, int y) const;

    //Converts (x,y) to the index in the canvasPixels array
    [[nodiscard]] int findPixelIndex(int x, int y) const;
};

// Takes a color and writes that color to a coordinate in the canvas
void writePixel(Canvas& canvas, int x, int y, Color color);

// Returns the color inside the given canvas at point (x,y)
Color pixelAt(Canvas canvas, int x, int y);


#endif //RAYTRACER_CANVAS_H
