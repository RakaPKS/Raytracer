#include "Canvas.h"

Canvas::Canvas(int width, int height){
    this->width = width;
    this->height = height;
    this->length = width * height;
    this->canvasPixels = new Color [this->length];
}

[[nodiscard]] Color Canvas::pixelAt(int x, int y) const{
    if (x > width || y > height)
        return {0, 0, 0};
    return canvasPixels[findPixelIndex(x, y)];
}


[[nodiscard]] int Canvas::findPixelIndex(int x, int y) const{
    return x + y * width;
}

void writePixel(Canvas& canvas, int x, int y, Color color){
    if (x <= canvas.width && y <= canvas.height)
        canvas.canvasPixels[canvas.findPixelIndex(x, y)] = color;
}

Color pixelAt(Canvas canvas, int x, int y){
    if (x > canvas.width || y > canvas.height)
        return {0, 0, 0};
    return canvas.canvasPixels[canvas.findPixelIndex(x, y)];
}
