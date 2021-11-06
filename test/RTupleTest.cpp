//
// Created by Raka Schipperheijn on 07/11/2021.
//

#include "gtest/gtest.h"
#include "../src/RTuple.h"

TEST(RTupleTestsSuite, verifyVector){
RTuple r;
r.x = 12.0;
r.y = 13.0;
r.z = 14.0;
r.w = 0;
EXPECT_TRUE(r.isVector());
EXPECT_FALSE(r.isPoint());
}

TEST(RTupleTestsSuite, verifyPoint){
RTuple r;
r.x = 12.0;
r.y = 13.0;
r.z = 14.0;
r.w = 1;
EXPECT_TRUE(r.isPoint());
EXPECT_FALSE(r.isVector());
}