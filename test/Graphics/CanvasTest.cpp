#include "gtest/gtest.h"
#include "../../src/Graphics/Canvas.h"

TEST(CanvasTestSuite, verifyClass) {
    Canvas c = Canvas(10, 20);
    EXPECT_EQ(c.width, 10);
    EXPECT_EQ(c.height, 20);
    EXPECT_EQ(c.length, 200);
    for (int i = 0; i < c.length; i++)
        EXPECT_EQ(Color(0,0,0), c.canvasPixels[i]);
}

TEST(CanvasTestSuite, verifyWritingPixel){
    Canvas c = Canvas(10, 20);
    Color red = Color(1,0,0);
    int x = 2;
    int y = 3;
    writePixel(c, x, y, red);
    EXPECT_EQ(red, pixelAt(c, x, y));
    EXPECT_EQ(red, c.pixelAt(x, y));
}

