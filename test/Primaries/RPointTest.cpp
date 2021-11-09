#include "gtest/gtest.h"
#include "../../src/Primaries/RTuple.h"


TEST(RPointTestsSuite, verifySubClass) {
    RPoint p = {12.0, 13.0, 14.0};
    EXPECT_FLOAT_EQ(p.x, 12.0);
    EXPECT_FLOAT_EQ(p.y, 13.0);
    EXPECT_FLOAT_EQ(p.z, 14.0);
    EXPECT_EQ(p.w, 1);
    EXPECT_TRUE(p.isPoint());
    EXPECT_FALSE(p.isVector());
    EXPECT_EQ(p, RPoint(12.0, 13.0, 14.0));
}


TEST(RPointTestsSuite, verifyAddition) {
    RPoint x = {12.0, 13.0, 14.0};
    RVector y = {12.0, 13.0, 14.0};
    RPoint z = x + y;
    EXPECT_EQ(z, RPoint(x.x + y.x, x.y + y.y, x.z + y.z));
}

TEST(RPointTestsSuite, verifySubstraction) {
    RPoint x = {36.0, 26.0, 42.0};
    RVector y = {12.0, 13.0, 14.0};
    RPoint z = x - y;
    EXPECT_EQ(z, RPoint(x.x - y.x, x.y - y.y, x.z - y.z));
}

TEST(RPointTestsSuite, verifyNegate) {
    RPoint p = {12.0, 13.0, 14.0};
    RPoint t = -p;
    EXPECT_EQ(t, RPoint(-p.x, -p.y, -p.z));
}

TEST(RPointTestsSuite, verifyScalarMultiply) {
    RPoint p = {1, -2, 3};
    double scalar = 3.5;
    RPoint r = p * scalar;
    RPoint q = scalar * p;
    EXPECT_EQ(r, RPoint(3.5, -7, 10.5));
    EXPECT_EQ(r, q);
}

TEST(RPointTestsSuite, verifyScalarDivision) {
    RPoint p = {1, -2, 3};
    double scalar = 2;
    RPoint r = p / scalar;
    EXPECT_EQ(r, RPoint(0.5, -1, 1.5));
}