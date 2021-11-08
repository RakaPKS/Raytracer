//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include "gtest/gtest.h"
#include "../src/Color.h"

TEST(ColorTestSuite, verifyColorClass){
    Color c = {-0.5, 0.4, 1.7};
    EXPECT_EQ(c.red(), -0.5);
    EXPECT_EQ(c.green(), 0.4);
    EXPECT_EQ(c.blue(), 1.7);
    c.red(1.0);
    c.blue(1.0);
    c.green(1.0);
    EXPECT_EQ(c, Color(1.0, 1.0, 1.0));
}

TEST(ColorTestSuite, verifyAddition){
    Color c1 = {0.9, 0.6, 0.75};
    Color c2 = {0.7, 0.1, 0.25};
    Color c3 = c1 + c2;
    EXPECT_EQ(c3, Color(1.6, 0.7, 1.0))
}