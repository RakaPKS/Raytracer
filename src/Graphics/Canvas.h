//
// Created by Raka Schipperheijn on 08/11/2021.
//

#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H

#include "../Primaries/Color.h"

class Canvas{
public:
    int width;
    int height;
    int length;
    Color* canvasPixels;
    Canvas(int width, int height){
        this->width = width;
        this->height = height;
        this->length = width * height;
        this->canvasPixels = new Color [this->length];
    }

    [[nodiscard]] Color pixelAt(int x, int y) const{
        return canvasPixels[findPixelIndex(x, y)];
    }

    [[nodiscard]] int findPixelIndex(int x, int y) const{
        return x + y * width;
    }
};




static void writePixel(Canvas& canvas, int x, int y, Color color){
    canvas.canvasPixels[canvas.findPixelIndex(x, y)] = color;
}

static Color pixelAt(Canvas canvas, int x, int y){
    return canvas.canvasPixels[canvas.findPixelIndex(x, y)];
}

#endif //RAYTRACER_CANVAS_H
