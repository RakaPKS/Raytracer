#include "gtest/gtest.h"
#include "../../src/Graphics/PPM.h"
#include <string>

TEST(PPMTestSuite, basicTest){
    Canvas c = Canvas(5,3);
    Color c1 = Color(1.5, 0, 0);
    Color c2 = Color(0, 0.5, 0);
    Color c3 = Color(-0.5, 0, 1);
    writePixel(c, 0, 0, c1);
    writePixel(c, 2, 1, c2);
    writePixel(c, 4, 2, c3);
    PPM p = PPM(c);
    std::string a =  p.getPPM();
    EXPECT_NE(a, "");
    std::string b = p.lines[3] + "\n" + p.lines[4] + "\n" + p.lines[5];
    std::string d = "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255";
    EXPECT_EQ(b, d);
}

TEST(PPMTestSuite, splitTest){
    Canvas c = Canvas(10, 2);
    for (int i = 0; i < c.length; i++)
        c.canvasPixels[i] = Color(1, 0.8, 0.6);
    PPM p = PPM(c);
    std::string b = p.lines[3] + "\n" + p.lines[4] + "\n" + p.lines[5] + "\n" + p.lines[6];
    std::string d = "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153";
    EXPECT_EQ(b, d);
}

TEST(PPMTestSuite, checkTerminatingNewLine){
    Canvas c = Canvas(5, 3);
    PPM p = PPM(c);
    std::string a = p.getPPM();
    EXPECT_EQ(a.back(), '\n');

}