#include "gtest/gtest.h"

#include <mmath/util.h>

using mmath::clamp;
using mmath::radiansWrap;

class utilTest : public ::testing::Test
{
protected:
    utilTest() {}
    virtual ~utilTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }
    
    const double PI = 3.14159265358979323846;
    const double HALF_PI = PI / 2;
    const double TWO_PI = PI * 2;
};

TEST_F(utilTest, clampTest)
{
    ASSERT_EQ(clamp(1.0, 0.0, 10.0), 1.0);
    ASSERT_EQ(clamp(100.0, 0.0, 10.0), 10.0);
    ASSERT_EQ(clamp(30.0, 10, 50.0), 30.0);
    ASSERT_EQ(clamp(1.0, 10, 50.0), 10.0);
    ASSERT_EQ(clamp(100.0, 10, 50.0), 50.0);
    ASSERT_EQ(clamp(-1.0, 0.0, 10.0), 0.0);
    ASSERT_EQ(clamp(-100.0, 0.0, 10.0), 0.0);
    ASSERT_EQ(clamp(-1.0, -5.0, 10.0), -1.0);
    ASSERT_EQ(clamp(-100.0, -5.0, 10.0), -5.0);
    ASSERT_EQ(clamp(12.3, -50.0, -10.0), -10.0);
    ASSERT_EQ(clamp(-25.0, -50.0, -10.0), -25.0);
    ASSERT_EQ(clamp(-125.0, -50.0, -10.0), -50.0);
}

TEST_F(utilTest, radiansWrapTest)
{
    ASSERT_EQ(radiansWrap(PI), PI);
    ASSERT_EQ(radiansWrap(-PI), PI);
    ASSERT_EQ(radiansWrap(HALF_PI), HALF_PI);
    ASSERT_EQ(radiansWrap(-HALF_PI), -HALF_PI);
    ASSERT_EQ(radiansWrap(TWO_PI), 0.0);
    ASSERT_EQ(radiansWrap(-TWO_PI), 0.0);
    ASSERT_EQ(radiansWrap(1.0), 1.0);
    ASSERT_EQ(radiansWrap(-1.0), -1.0);
    ASSERT_EQ(radiansWrap(2.0), 2.0);
    ASSERT_EQ(radiansWrap(-2.0), -2.0);
    ASSERT_EQ(radiansWrap(3.0), 3.0);
    ASSERT_EQ(radiansWrap(-3.0), -3.0);
    ASSERT_EQ(radiansWrap(7.0), 7.0 - TWO_PI);
    ASSERT_EQ(radiansWrap(-7.0), -7.0 + TWO_PI);
}