//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include "gtest/gtest.h"
#include "../src/RTuple.h"

TEST(RTupleTestsSuite, verifyVector){
    RTuple v = {12.0, 13.0, 14.0, 0};
    EXPECT_FLOAT_EQ(v.x,12.0);
    EXPECT_FLOAT_EQ(v.y, 13.0);
    EXPECT_FLOAT_EQ(v.z, 14.0);
    EXPECT_EQ(v.w, 0);
    EXPECT_TRUE(v.isVector());
    EXPECT_FALSE(v.isPoint());
}

TEST(RTupleTestsSuite, verifyPoint){
    RTuple p = {12.0, 13.0, 14.0, 1};
    EXPECT_FLOAT_EQ(p.x, 12.0);
    EXPECT_FLOAT_EQ(p.y, 13.0);
    EXPECT_FLOAT_EQ(p.z, 14.0);
    EXPECT_EQ(p.w, 1);
    EXPECT_TRUE(p.isPoint());
    EXPECT_FALSE(p.isVector());
}

TEST(RTupleTestsSuite, verifyRTupleAddition) {
    RTuple x = {12.0, 13.0, 14.0, 0};
    RTuple y = {12.0, 13.0, 14.0, 1};
    RTuple z = x + y;
    EXPECT_EQ(z, RTuple(x.x + y.x, x.y + y.y, x.z + y.z, x.w + y.w));
}

TEST(RTupleTestsSuite, verifyRTupleSubstraction) {
    RTuple x = {36.0, 26.0, 42.0, 1};
    RTuple y = {12.0, 13.0, 14.0, 1};
    RTuple z = x - y;
    EXPECT_EQ(z, RTuple(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w));
}

TEST(RTupleTestsSuite, verifyRTupleNegate) {
    RTuple p = {12.0, 13.0, 14.0, 0};
    RTuple t = -p;
    EXPECT_EQ(t, RTuple(-p.x, -p.y, -p.z, -p.w));

}

TEST(RTupleTestsSuite, verifyScalarMultiply) {
    RTuple p = {1, -2, 3, -4};
    double scalar = 3.5;
    RTuple r = p*scalar;
    RTuple q = scalar*p;
    EXPECT_EQ(r, RTuple(3.5, -7, 10.5, -14));
    EXPECT_EQ(r, q);
}

TEST(RTupleTestsSuite, verifyScalarDivision) {
    RTuple p = {1, -2, 3, -4};
    double scalar = 2;
    RTuple r = p / 2;
    EXPECT_EQ(r, RTuple(0.5, -1, 1.5, -2));
}

TEST(RPointTestsSuite, verifyRPointSubClass){
    RPoint p = {12.0, 13.0, 14.0};
    EXPECT_FLOAT_EQ(p.x, 12.0);
    EXPECT_FLOAT_EQ(p.y, 13.0);
    EXPECT_FLOAT_EQ(p.z, 14.0);
    EXPECT_EQ(p.w, 1);
    EXPECT_TRUE(p.isPoint());
    EXPECT_FALSE(p.isVector());
    EXPECT_EQ(p, RTuple(12.0, 13.0, 14.0, 1));
}

TEST(RVectorTestsSuite, verifyRVectorSubClass){
    RVector v = {12.0, 13.0, 14.0};
    EXPECT_FLOAT_EQ(v.x, 12.0);
    EXPECT_FLOAT_EQ(v.y, 13.0);
    EXPECT_FLOAT_EQ(v.z, 14.0);
    EXPECT_EQ(v.w, 0);
    EXPECT_FALSE(v.isPoint());
    EXPECT_TRUE(v.isVector());
    EXPECT_EQ(v, RTuple(12.0, 13.0, 14.0, 0));
}

TEST(RVectorTestsSuite, verifyMagnitude){
    RVector a = {1,0,0};
    EXPECT_EQ(a.magnitude(), 1);
    RVector b = {0,1,0};
    EXPECT_EQ(b.magnitude(), 1);
    RVector c = {0,0,1};
    EXPECT_EQ(c.magnitude(), 1);
    RVector d = {1,2,3};
    EXPECT_EQ(d.magnitude(), sqrt(14));
    RVector e = {-1,-2,-3};
    EXPECT_EQ(e.magnitude(), sqrt(14));
}
TEST(RVectorTestsSuite, verifyNormalize) {
    RVector a = {4,0,0};
    EXPECT_EQ(a.normalize(), RVector(1,0,0));
    RVector b = {1,2,3};
    RVector c = {1/(sqrt(14)), 2/(sqrt(14)), 3/(sqrt(14))};
    EXPECT_EQ(b.normalize(), c);
    EXPECT_EQ(b.normalize().magnitude(), 1);
}

TEST(RVectorTestsSuite, verifyDot){
    RVector a = {1, 2, 3};
    RVector b = {2, 3, 4};
    EXPECT_EQ(a.dot(b), 20);
}

TEST(RVectorTestsSuite, verifyCross){
    RVector a = {1, 2, 3};
    RVector b = {2, 3, 4};
    EXPECT_EQ(a.cross(b), RVector(-1, 2, -1));
    EXPECT_EQ(b.cross(a), RVector(1, -2, 1));
}