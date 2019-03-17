#include "gtest/gtest.h"

#include <mmath/Angles.h>

using mmath::Angles;

class AnglesTest : public ::testing::Test
{
protected:
    AnglesTest() {}
    virtual ~AnglesTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }
};

TEST_F(AnglesTest, RadToDegTest)
{
    ASSERT_EQ(Angles::RadToDeg(0.0), 0.0);
    ASSERT_EQ(Angles::RadToDeg(1.0), 57.29577951308232286);
    ASSERT_EQ(Angles::RadToDeg(-1.0), -57.29577951308232286);
    ASSERT_EQ(Angles::RadToDeg(3.14159265358979323846), 180.0);
    ASSERT_EQ(Angles::RadToDeg(-3.14159265358979323846), -180.0);
    ASSERT_EQ(Angles::RadToDeg(6.283185307179586232), 360.0);
    ASSERT_EQ(Angles::RadToDeg(-6.283185307179586232), -360.0);
    ASSERT_EQ(Angles::RadToDeg(62.83185307179586232), 3600.0);
    ASSERT_EQ(Angles::RadToDeg(-62.83185307179586232), -3600.0);
}

TEST_F(AnglesTest, DegToRadTest)
{
    ASSERT_EQ(Angles::DegToRad(0.0), 0.0);
    ASSERT_EQ(Angles::DegToRad(57.29577951308232286), 1.0);
    ASSERT_EQ(Angles::DegToRad(-57.29577951308232286), -1.0);
    ASSERT_EQ(Angles::DegToRad(180.0), 3.14159265358979323846);
    ASSERT_EQ(Angles::DegToRad(-180.0), -3.14159265358979323846);
    ASSERT_EQ(Angles::DegToRad(360.0), 6.283185307179586232);
    ASSERT_EQ(Angles::DegToRad(-360.0), -6.283185307179586232);
    ASSERT_EQ(Angles::DegToRad(3600.0), 62.83185307179586232);
    ASSERT_EQ(Angles::DegToRad(-3600.0), -62.83185307179586232);
}
