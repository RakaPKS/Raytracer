#include "gtest/gtest.h"
#include "../../src/Primaries/RTuple.h"

TEST(RVectorTestsSuite, verifySubClass) {
    RVector v = {12.0, 13.0, 14.0};
    EXPECT_FLOAT_EQ(v.x, 12.0);
    EXPECT_FLOAT_EQ(v.y, 13.0);
    EXPECT_FLOAT_EQ(v.z, 14.0);
    EXPECT_EQ(v.w, 0);
    EXPECT_FALSE(v.isPoint());
    EXPECT_TRUE(v.isVector());
    EXPECT_EQ(v, RVector(12.0, 13.0, 14.0));
}

TEST(RVectorTestsSuite, verifyRTupleAddition) {
    RVector x = {12.0, 13.0, 14.0};
    RVector y = {12.0, 13.0, 14.0};
    RVector z = x + y;
    EXPECT_EQ(z, RVector(x.x + y.x, x.y + y.y, x.z + y.z));
}

TEST(RVectorTestsSuite, verifyRTupleSubstraction) {
    RVector x = {36.0, 26.0, 42.0};
    RVector y = {12.0, 13.0, 14.0};
    RTuple z = x - y;
    EXPECT_EQ(z, RVector(x.x - y.x, x.y - y.y, x.z - y.z));
}

TEST(RVectorTestsSuite, verifyRTupleNegate) {
    RVector p = {12.0, 13.0, 14.0};
    RVector t = -p;
    EXPECT_EQ(t, RVector(-p.x, -p.y, -p.z));

}

TEST(RVectorTestsSuite, verifyScalarMultiply) {
    RVector p = {1, -2, 3};
    double scalar = 3.5;
    RVector r = p * scalar;
    RVector q = scalar * p;
    EXPECT_EQ(r, RVector(3.5, -7, 10.5));
    EXPECT_EQ(r, q);
}

TEST(RVectorTestsSuite, verifyScalarDivision) {
    RVector p = {1, -2, 3};
    double scalar = 2;
    RVector r = p / scalar;
    EXPECT_EQ(r, RVector(0.5, -1, 1.5));
}

TEST(RVectorTestsSuite, verifyMagnitude) {
    RVector a = {1, 0, 0};
    EXPECT_EQ(a.magnitude(), 1);
    RVector b = {0, 1, 0};
    EXPECT_EQ(b.magnitude(), 1);
    RVector c = {0, 0, 1};
    EXPECT_EQ(c.magnitude(), 1);
    RVector d = {1, 2, 3};
    EXPECT_EQ(d.magnitude(), sqrt(14));
    RVector e = {-1, -2, -3};
    EXPECT_EQ(e.magnitude(), sqrt(14));
}

TEST(RVectorTestsSuite, verifyNormalize) {
    RVector a = {4, 0, 0};
    EXPECT_EQ(a.normalize(), RVector(1, 0, 0));
    RVector b = {1, 2, 3};
    RVector c = {1 / (sqrt(14)), 2 / (sqrt(14)), 3 / (sqrt(14))};
    EXPECT_EQ(b.normalize(), c);
    EXPECT_EQ(b.normalize().magnitude(), 1);
}

TEST(RVectorTestsSuite, verifyDot) {
    RVector a = {1, 2, 3};
    RVector b = {2, 3, 4};
    EXPECT_EQ(a.dot(b), 20);
}

TEST(RVectorTestsSuite, verifyCross) {
    RVector a = {1, 2, 3};
    RVector b = {2, 3, 4};
    EXPECT_EQ(a.cross(b), RVector(-1, 2, -1));
    EXPECT_EQ(b.cross(a), RVector(1, -2, 1));
}